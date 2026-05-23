#include "EsContextLinux.h"
#include "MeshData.h"
#include "ShaderProgram.h"

#include <GLES3/gl3.h>

#include <cstddef>
#include <iostream>

int main() {
  EsContextLinux context(1280, 720, "InterviewRenderer");
  if (!context.initialize()) {
    std::cerr << "Failed to initialize EGL/X11 context.\n";
    return 1;
  }

  constexpr const char* kVertexShader = R"(#version 300 es
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColor;
out vec4 vColor;
void main() {
  vColor = aColor;
  gl_Position = vec4(aPos, 1.0);
})";

  constexpr const char* kFragmentShader = R"(#version 300 es
precision mediump float;
in vec4 vColor;
out vec4 FragColor;
void main() {
  FragColor = vColor;
})";

  ShaderProgram program;
  if (!program.build(kVertexShader, kFragmentShader)) {
    std::cerr << "Shader build failed: " << program.lastError() << "\n";
    return 1;
  }

  MeshData triangle = MeshData::makeTriangle();

  GLuint vao = 0;
  GLuint vbo = 0;
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER,
               static_cast<GLsizeiptr>(triangle.vertices.size() * sizeof(Vertex)),
               triangle.vertices.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        reinterpret_cast<void*>(offsetof(Vertex, position)));
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        reinterpret_cast<void*>(offsetof(Vertex, color)));
  glEnableVertexAttribArray(1);

  while (!context.shouldClose()) {
    glViewport(0, 0, context.width(), context.height());
    glClearColor(0.08f, 0.10f, 0.13f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    program.use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(triangle.vertices.size()));

    context.swapBuffers();
  }

  glDeleteBuffers(1, &vbo);
  glDeleteVertexArrays(1, &vao);
  return 0;
}
