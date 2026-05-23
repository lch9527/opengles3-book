cmake_minimum_required(VERSION 3.16)
project(InterviewRenderer LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
  ${CMAKE_SOURCE_DIR}/Common/Include
  ${CMAKE_SOURCE_DIR}/External/Include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(InterviewRenderer
  src/main.cpp
  src/EsContextLinux.cpp
  src/ShaderProgram.cpp
)

target_link_libraries(InterviewRenderer
  EGL
  GLESv2
  X11
)
