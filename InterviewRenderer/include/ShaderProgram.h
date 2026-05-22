#pragma once

#include <GLES3/gl3.h>

#include <string>
#include <string_view>

class ShaderProgram {
public:
  ShaderProgram() = default;
  ShaderProgram(std::string_view vertexSource, std::string_view fragmentSource);
  ~ShaderProgram();

  ShaderProgram(const ShaderProgram&) = delete;
  ShaderProgram& operator=(const ShaderProgram&) = delete;
  ShaderProgram(ShaderProgram&& other) noexcept;
  ShaderProgram& operator=(ShaderProgram&& other) noexcept;

  bool build(std::string_view vertexSource, std::string_view fragmentSource);
  void use() const noexcept;
  GLuint id() const noexcept { return id_; }
  const std::string& lastError() const noexcept { return lastError_; }

private:
  GLuint compile(GLenum type, std::string_view source);
  void cleanup() noexcept;

  GLuint id_{0};
  std::string lastError_;
};
