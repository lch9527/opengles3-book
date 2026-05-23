# OpenGL ES 3 Book: WSL2 Linux + C++ Study Plan

This guide is the main study path for using LearnOpenGL concepts to understand and rebuild the examples in this OpenGL ES 3 repository.

- Platform: Windows 11 + WSL2 (`Ubuntu 24.04`)
- Focus: Linux/X11 samples + modern C++ renderer practice
- Pace: `30 hours/week`, `2 weeks`, `10 study days`, `6 hours/day`
- Concept rhythm: LearnOpenGL order, adapted to OpenGL ES 3 and this repo

## 1) One-time WSL2 Setup on Windows 11

Open PowerShell as Administrator and run:

```powershell
wsl --install -d Ubuntu-24.04
```

Reboot if prompted, then launch **Ubuntu 24.04** from Start menu and create your Linux username/password.

Confirm WSL version:

```powershell
wsl -l -v
```

You should see `Ubuntu-24.04` with `VERSION 2`.

## 2) Install Linux Build Dependencies

Run inside Ubuntu:

```bash
sudo apt update
sudo apt install -y \
  build-essential cmake pkg-config \
  libx11-dev libegl1-mesa-dev libgles2-mesa-dev \
  mesa-utils
```

## 3) Build This Repo in Linux

From the repo root:

```bash
cmake -S . -B build
cmake --build build -j"$(nproc)"
```

Smoke test:

```bash
./build/Chapter_2/Hello_Triangle/Hello_Triangle
```

Optional renderer check:

```bash
glxinfo -B
```

## 4) Daily Workflow

Each study day follows the same loop:

1. Read the matching LearnOpenGL text.
2. Run the matching repo sample.
3. Trace the important OpenGL ES calls in source.
4. Sketch or implement the matching C++ data structures in `InterviewRenderer`.
5. Explain the CPU data, GPU data, shader inputs, and visible pixels.

Daily output:

- runnable proof or source trace
- 8-15 bullet notes
- one math, shader, data-structure, or threading practice artifact
- short next-day cleanup list

## 5) Core Skills Ladder

- Data structures: vertex arrays, index buffers, mesh structs, material structs, texture handles, render-pass structs, explicit resource ownership.
- Shaders: attributes, uniforms, varyings, sampler uniforms, GLSL ES precision, compile/link logs, lighting shaders.
- 3D math: vectors, matrices, dot product, cross product, normalization, model/view/projection, coordinate spaces.
- Multi-threading: CPU-side file loading and decode workers, handoff queues, render-thread GL ownership, synchronization boundaries.
- Code practice: one focused C++ design or implementation task every study day.

## 6) LearnOpenGL-Aligned 10-Day Schedule

### Day 1 - Completed: Environment + Rendering Flow

- Read: OpenGL, Creating a Window, Hello Window, Hello Triangle.
- Trace: `Common/Include/esUtil.h`, `Common/Source/esUtil.c`, `Common/Source/LinuxX11/esUtil_X11.c`, `Chapter_2/Hello_Triangle/Hello_Triangle.c`.
- Output: `ESContext` lifecycle, EGL setup, draw callback loop, 10 bullets on disk-to-pixel flow.

### Day 2 - Triangle, Shaders, First Data Structures

- Read: LearnOpenGL Hello Triangle and Shaders.
- Trace: `Chapter_2/Hello_Triangle`, `Chapter_6/Example_6_3`, `InterviewRenderer/src/ShaderProgram.cpp`.
- Code practice: define responsibilities for `Vertex`, `MeshData`, and `ShaderProgram`.
- Explain: vertex attributes, vertex shader, fragment shader, program link, draw call.

### Day 3 - Buffers, VAOs, Indexing, Memory Layout

- Read: LearnOpenGL buffer and VAO sections from Hello Triangle.
- Trace: `Chapter_6/VertexBufferObjects`, `Chapter_6/VertexArrayObjects`, `Chapter_6/MapBuffers`.
- Code practice: design `BufferObject`, `VertexArray`, and `Mesh` RAII wrappers.
- Explain: CPU array vs GPU buffer, stride, offset, indexed draw, ownership.

### Day 4 - Textures and Disk-to-Pixel

- Read: LearnOpenGL Textures.
- Trace: `Chapter_9/Simple_Texture2D`, `Chapter_9/TextureWrap`, `Chapter_9/MipMap2D`, `Chapter_10/MultiTexture`.
- Code practice: design `Texture2D`, `SamplerState`, and `Material`.
- Explain: file bytes, image dimensions, `glTexImage2D`, texture units, sampler uniforms.

### Day 5 - 3D Math Foundation

- Read: LearnOpenGL Transformations and Coordinate Systems.
- Trace: `Chapter_6/Example_6_6`, `Chapter_8/Simple_VertexShader`, `Common/Source/esTransform.c`.
- Code practice: sketch or implement `Vec3`, `Mat4`, `dot`, `cross`, `normalize`, and matrix multiply tests.
- Explain: local, world, view, clip, NDC, and screen spaces.

### Day 6 - Camera and Dot/Cross Product Practice

- Read: LearnOpenGL Camera.
- Trace: `Chapter_14/Noise3D`, `Chapter_14/TerrainRendering`.
- Code practice: derive camera forward/right/up vectors and a look-at matrix.
- Explain: dot product for angle/projection/lighting; cross product for perpendicular axes and normals.

### Day 7 - Lighting Shaders

- Read: LearnOpenGL Colors, Basic Lighting, Materials.
- Trace: `Chapter_14/Noise3D`, `Chapter_14/TerrainRendering`, shader strings that use normals or light direction.
- Code practice: design `Light`, `Material`, and shader uniform update flow.
- Explain: ambient, diffuse, specular, normal normalization, Lambert dot product.

### Day 8 - Advanced OpenGL State and Framebuffers

- Read: LearnOpenGL Depth Testing, Blending, Face Culling, Framebuffers.
- Trace: `Chapter_11/MRTs`, `Chapter_14/ParticleSystem`, `Chapter_14/Shadows`.
- Code practice: design `RenderPass`, `Framebuffer`, and `RenderTarget`.
- Explain: default framebuffer vs offscreen FBO, depth buffer, blending order, culling.

### Day 9 - Instancing, Particles, Data-Oriented Layout, Threading

- Read: LearnOpenGL Instancing and Debugging.
- Trace: `Chapter_7/Instancing`, `Chapter_14/ParticleSystemTransformFeedback`.
- Code practice: sketch instance data layout and a CPU asset-loading worker queue.
- Explain: render thread owns GL calls; worker threads read/decode files and hand finished CPU data to render thread.

### Day 10 - Shadows, Integration, Interview Packaging

- Read: LearnOpenGL Shadow Mapping and advanced lighting overview.
- Trace: `Chapter_14/Shadows`, `Chapter_14/TerrainRendering`.
- Code practice: assemble final `InterviewRenderer` architecture note.
- Explain: shadow map pass, depth texture, light-space matrix, final renderer data flow.

## 7) Repo Sample Map

- Chapter 2: `Hello_Triangle`
- Chapter 6: `Example_6_3`, `Example_6_6`, `MapBuffers`, `VertexArrayObjects`, `VertexBufferObjects`
- Chapter 7: `Instancing`
- Chapter 8: `Simple_VertexShader`
- Chapter 9: `Simple_Texture2D`, `Simple_TextureCubemap`, `MipMap2D`, `TextureWrap`
- Chapter 10: `MultiTexture`
- Chapter 11: `MRTs`
- Chapter 14: `Noise3D`, `ParticleSystem`, `ParticleSystemTransformFeedback`, `Shadows`, `TerrainRendering`

## 8) OpenGL ES Notes While Reading LearnOpenGL

- LearnOpenGL uses desktop OpenGL; this repo uses OpenGL ES 3.
- Use GLSL ES `#version 300 es`, not desktop GLSL versions.
- Fragment shaders need precision qualifiers such as `precision mediump float;`.
- Window/context setup is EGL/X11 here, not GLFW/GLAD.
- Treat desktop-only topics as concepts unless there is a matching ES 3 sample.

## 9) Session Checklists

- Week 1 execution: `InterviewRenderer/docs/WEEK1_5DAY_12H_CHECKLIST.md`
- Week 2 execution: `InterviewRenderer/docs/WEEK2_5DAY_12H_CHECKLIST.md`
