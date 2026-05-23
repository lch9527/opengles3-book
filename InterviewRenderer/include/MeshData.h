#pragma once

#include <array>
#include <vector>

struct Vertex {
  std::array<float, 3> position{};
  std::array<float, 4> color{};
};

struct MeshData {
  std::vector<Vertex> vertices;

  static MeshData makeTriangle() {
    return MeshData{{
        {{0.0f, 0.5f, 0.0f}, {0.95f, 0.20f, 0.25f, 1.0f}},
        {{-0.6f, -0.5f, 0.0f}, {0.20f, 0.75f, 0.35f, 1.0f}},
        {{0.6f, -0.5f, 0.0f}, {0.20f, 0.45f, 0.95f, 1.0f}},
    }};
  }
};
