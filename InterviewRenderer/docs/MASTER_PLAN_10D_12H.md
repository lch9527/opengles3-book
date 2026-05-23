# Rendering Interview Prep (10 Days, 6h/Day)

Total budget: `60 hours`
Cadence: `5 days/week`, `6 hours/day`, `2 weeks`
Platform focus: `Linux + C++ + OpenGL ES 3`

## Goal

Build interview-ready understanding and code evidence by reading LearnOpenGL in topic order, tracing this repo's OpenGL ES examples, and growing `InterviewRenderer` into a small C++ renderer.

Core evidence:

- real-time rendering pipeline knowledge
- GLSL ES shader fluency
- 3D math and coordinate-space understanding
- renderer data-structure design
- CPU/GPU ownership and multi-threading boundaries
- performance and debugging workflow

## Study Rhythm

Every day has four lanes:

1. Read: LearnOpenGL topic for the day.
2. Trace: matching OpenGL ES sample in this repo.
3. Code: one C++ practice task for `InterviewRenderer` or a design sketch.
4. Explain: 8-15 bullets in plain language.

## Core Skills

- Data structures: `Vertex`, `MeshData`, `Mesh`, `Material`, `Texture2D`, `Light`, `RenderPass`, `Framebuffer`.
- Shaders: compile/link, attributes, uniforms, varyings, samplers, precision, lighting.
- Math: `Vec3`, `Mat4`, dot product, cross product, normalization, MVP, camera basis.
- Threading: render-thread GL ownership, worker-thread asset loading, CPU data handoff queues.

## Structure

- Week 1 execution: `docs/WEEK1_5DAY_12H_CHECKLIST.md`
- Week 2 execution: `docs/WEEK2_5DAY_12H_CHECKLIST.md`
- Project scaffold: `InterviewRenderer/`

## Daily Output Requirement

Every day must end with:

1. runnable sample proof or source trace
2. 8-15 bullet learning notes
3. one code/math/shader/threading practice artifact
4. metrics or validation note where relevant
5. short next-day task list

## End-State Acceptance

- `InterviewRenderer` runs on Linux/X11 through WSL2.
- The study docs clearly map LearnOpenGL topics to repo examples.
- You can explain CPU data structures, GPU resources, shader inputs, and final pixels.
- You have notes for dot/cross products, MVP, camera basis, lighting, textures, FBOs, and threading boundaries.
- You have a concise interview story bank covering bugs, performance, tradeoffs, and architecture.
