#include "EsContextLinux.h"
#include "ShaderProgram.h"

#include <GLES3/gl3.h>

#include <array>
#include <iostream>

int main() {
  EsContextLinux context(1280, 720, "InterviewRenderer");
  if (!context.initialize()) {
    std::cerr << "Failed to initialize EGL/X11 context.\n";
    return 1;
  }

  constexpr const char* kVertexShader = R"(#version 300 es
layout(location = 0) in vec3 aPos;
void main() {
  gl_Position = vec4(aPos, 1.0);
})";

  constexpr const char* kFragmentShader = R"(#version 300 es
precision mediump float;
out vec4 FragColor;
void main() {
  FragColor = vec4(0.87, 0.17, 0.22, 1.0);
})";

  ShaderProgram program;
  if (!program.build(kVertexShader, kFragmentShader)) {
    std::cerr << "Shader build failed: " << program.lastError() << "\n";
    return 1;
  }

  std::array<float, 9> triangle = {
      0.0f,  0.5f, 0.0f,
     -0.6f, -0.5f, 0.0f,
      0.6f, -0.5f, 0.0f,
  };

  GLuint vao = 0;
  GLuint vbo = 0;
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
  glEnableVertexAttribArray(0);

  while (!context.shouldClose()) {
    glViewport(0, 0, context.width(), context.height());
    glClearColor(0.08f, 0.10f, 0.13f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    program.use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    context.swapBuffers();
  }

  glDeleteBuffers(1, &vbo);
  glDeleteVertexArrays(1, &vao);
  return 0;
}
