#include "ShaderProgram.h"

#include <vector>
#include <utility>

ShaderProgram::ShaderProgram(std::string_view vertexSource, std::string_view fragmentSource) {
  build(vertexSource, fragmentSource);
}

ShaderProgram::~ShaderProgram() { cleanup(); }

ShaderProgram::ShaderProgram(ShaderProgram&& other) noexcept { *this = std::move(other); }

ShaderProgram& ShaderProgram::operator=(ShaderProgram&& other) noexcept {
  if (this != &other) {
    cleanup();
    id_ = other.id_;
    lastError_ = std::move(other.lastError_);
    other.id_ = 0;
  }
  return *this;
}

bool ShaderProgram::build(std::string_view vertexSource, std::string_view fragmentSource) {
  cleanup();
  lastError_.clear();

  GLuint vs = compile(GL_VERTEX_SHADER, vertexSource);
  if (vs == 0) return false;

  GLuint fs = compile(GL_FRAGMENT_SHADER, fragmentSource);
  if (fs == 0) {
    glDeleteShader(vs);
    return false;
  }

  id_ = glCreateProgram();
  glAttachShader(id_, vs);
  glAttachShader(id_, fs);
  glLinkProgram(id_);

  GLint linked = 0;
  glGetProgramiv(id_, GL_LINK_STATUS, &linked);

  glDeleteShader(vs);
  glDeleteShader(fs);

  if (!linked) {
    GLint logLength = 0;
    glGetProgramiv(id_, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> log(static_cast<size_t>(logLength > 1 ? logLength : 1));
    glGetProgramInfoLog(id_, logLength, nullptr, log.data());
    lastError_ = log.data();
    cleanup();
    return false;
  }

  return true;
}

void ShaderProgram::use() const noexcept { glUseProgram(id_); }

GLuint ShaderProgram::compile(GLenum type, std::string_view source) {
  GLuint shader = glCreateShader(type);
  const GLchar* src = source.data();
  GLint len = static_cast<GLint>(source.size());
  glShaderSource(shader, 1, &src, &len);
  glCompileShader(shader);

  GLint compiled = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
  if (!compiled) {
    GLint logLength = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> log(static_cast<size_t>(logLength > 1 ? logLength : 1));
    glGetShaderInfoLog(shader, logLength, nullptr, log.data());
    lastError_ = log.data();
    glDeleteShader(shader);
    return 0;
  }

  return shader;
}

void ShaderProgram::cleanup() noexcept {
  if (id_ != 0) {
    glDeleteProgram(id_);
    id_ = 0;
  }
}
