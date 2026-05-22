# CODEX_HANDOFF_PLAN.md

## Project Mission
Prepare for the Tesla Rendering Engineer (Infotainment) interview by building a Linux-first C++ OpenGL ES renderer project from the `opengles3-book` repo.

Primary target role areas:
- Real-time rendering techniques
- GLSL shader implementation depth
- 2D/3D UI rendering architecture thinking
- GPU/CPU performance debugging and optimization
- Code quality, maintainability, ownership clarity

## Time Budget and Cadence
- Total: `60 hours`
- Schedule: `2 weeks`, `5 days/week`, `12 hours/day`
- Platform: `WSL2 Ubuntu (Linux/X11) + C++ + OpenGL ES 3`

## What Has Already Been Implemented
### 1) New project scaffold
- `InterviewRenderer/`
- `InterviewRenderer/CMakeLists.txt`
- Included in root build via root `CMakeLists.txt` (`SUBDIRS(... InterviewRenderer)`)

### 2) Core initial code
- `InterviewRenderer/include/EsContextLinux.h`
- `InterviewRenderer/src/EsContextLinux.cpp`
  - X11 window creation
  - EGL display/surface/context setup
  - render loop close handling
  - cleanup lifecycle (RAII, move-only)
- `InterviewRenderer/include/ShaderProgram.h`
- `InterviewRenderer/src/ShaderProgram.cpp`
  - vertex/fragment shader compile
  - program link
  - error log collection
- `InterviewRenderer/src/main.cpp`
  - boot context
  - compile shaders
  - create VAO/VBO
  - draw triangle loop

### 3) Existing planning docs
- `InterviewRenderer/docs/MASTER_PLAN_10D_12H.md`
- `InterviewRenderer/docs/WEEK1_5DAY_12H_CHECKLIST.md`
- `InterviewRenderer/docs/WEEK2_5DAY_12H_CHECKLIST.md`

## Master Implementation Plan (Decision Complete)

## Week 1 (Foundation + Core Renderer)
### Day 1
- Validate WSL2 Linux dependencies
- Build and run existing sample (`Hello_Triangle`)
- Read and trace:
  - `Common/Include/esUtil.h`
  - `Common/Source/esUtil.c`
  - `Common/Source/LinuxX11/esUtil_X11.c`
  - `Chapter_2/Hello_Triangle/Hello_Triangle.c`
- Output:
  - 10+ bullets on ESContext/EGL/render loop flow

### Day 2
- Validate custom `InterviewRenderer` target build
- Confirm context creation/cleanup stability
- Confirm shader compile/link diagnostics
- Output:
  - stable custom triangle render

### Day 3
- Add MVP camera math path
- Add indexed mesh drawing path
- Add small reusable mesh upload abstraction
- Output:
  - rotating 3D object with MVP

### Day 4
- Add texture wrapper and upload path
- Add sampler/wrap/filter/mipmap controls
- Add instanced draw path with per-instance attributes
- Output:
  - textured instanced scene

### Day 5
- Integrate all Week 1 systems into one scene
- Refactor ownership/cleanup edges
- Record baseline metrics
- Output:
  - Week 1 integration checkpoint + baseline perf

## Week 2 (GLSL + Lighting + Post + Optimization + Interview Pack)
### Day 6
- GLSL deep dive:
  - precision strategy (`lowp`, `mediump`, `highp`)
  - coordinate spaces and interpolation implications
  - branch/divergence awareness
- Output:
  - GLSL rulesheet

### Day 7
- Implement lighting shaders:
  - Lambert
  - Blinn-Phong
- Add basic material parameter controls
- Output:
  - lit scene presets

### Day 8
- Add MSAA path (where supported)
- Add FBO offscreen render path
- Add post process pass (tone/contrast; optional vignette/bloom-lite)
- Output:
  - multi-pass render path

### Day 9
- Performance pass:
  - CPU vs GPU bottleneck process
  - state-change reduction
  - draw-call pressure reduction
  - memory footprint logging
- Output:
  - before/after optimization report

### Day 10
- Final stabilization + cleanup
- Final README + architecture summary
- Prepare 8 interview narratives (debugging/perf/tradeoffs)
- Output:
  - interview-ready package

## Required Architecture Targets
Codex should evolve the scaffold toward these concrete interfaces:
- `EsContextLinux`
- `ShaderProgram`
- `BufferObject`
- `VertexArray`
- `Texture2D`
- `Framebuffer`
- `RenderPass` base class
- concrete passes (`GeometryPass`, `PostProcessPass`, optional `UIPass`)
- `FrameStats` metrics structure

Rules:
- Prefer move-only GPU resource wrappers
- No raw owning pointers for resource lifetimes
- Deterministic cleanup in destructors
- Preserve Linux-first behavior

## Build and Run Commands (WSL2 Ubuntu)
From repo root:

```bash
cd /mnt/e/GraphicInterviewPractice/opengles3-book
cmake -S . -B build
cmake --build build -j"$(nproc)"
./build/InterviewRenderer/InterviewRenderer
```

Reference sample check:

```bash
./build/Chapter_2/Hello_Triangle/Hello_Triangle
```

## Acceptance Gates
### Week 1 Gate
- custom renderer runs stable
- textured + instanced path functional
- baseline metrics captured (`FPS`, `frame ms`, `draw calls`)

### Week 2 Gate
- lighting + post-processing functional
- optimization report with measurable deltas
- interview package complete

### Final Success Criteria
A new interviewer can review this repo and see:
- C++ rendering architecture decisions
- GLSL competence
- concrete optimization methodology
- clean, maintainable implementation patterns

## Daily Output Contract (for any Codex continuation)
Every working day must end with:
1. runnable code state
2. concise learning notes (8-15 bullets)
3. metrics snapshot
4. next-day task list

## Continuation Protocol for New Codex Session
When a new Codex opens this repo, it should:
1. Read this file first: `InterviewRenderer/docs/CODEX_HANDOFF_PLAN.md`
2. Read current checklist file for active day:
   - Week 1: `InterviewRenderer/docs/WEEK1_5DAY_12H_CHECKLIST.md`
   - Week 2: `InterviewRenderer/docs/WEEK2_5DAY_12H_CHECKLIST.md`
3. Inspect current code status under `InterviewRenderer/src` and `InterviewRenderer/include`
4. Continue implementation from the first unchecked/day-pending item
5. Update notes and metrics before ending the session

## Immediate Next Task (Current State)
The next implementation task is **Week 1 Day 3**:
- add MVP transform path
- add indexed mesh drawing
- add reusable mesh upload abstraction

This should be the default next coding action unless the user reprioritizes.
