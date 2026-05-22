# Week 1 Checklist (5 Days, 12h/Day)

## Day 1 - Environment + Rendering Flow Grounding

### Build and run
- Install Linux deps in WSL2 Ubuntu.
- Build root repo with CMake.
- Run `Hello_Triangle`.

### Code reading order
1. `Common/Include/esUtil.h`
2. `Common/Source/esUtil.c`
3. `Common/Source/LinuxX11/esUtil_X11.c`
4. `Chapter_2/Hello_Triangle/Hello_Triangle.c`

### Required outputs
- Explain `ESContext` lifecycle and EGL setup.
- Explain where draw loop calls user callback.
- Write 10 bullets on disk-to-pixel flow.

## Day 2 - C++ Skeleton and First Draw

### Implementation tasks
- Build `InterviewRenderer` target.
- Validate `EsContextLinux` startup/shutdown path.
- Validate `ShaderProgram` compile/link error logs.
- Draw triangle from custom C++ code path.

### Required outputs
- screenshot or terminal proof of app run
- class responsibility notes for context + shader wrappers

## Day 3 - Geometry and Camera Path

### Implementation tasks
- Add MVP transform path.
- Add indexed draw flow.
- Add small mesh abstraction for CPU->GPU upload.

### Required outputs
- rotating object render
- math note: model/view/projection roles

## Day 4 - Textures and Instancing

### Implementation tasks
- Texture2D loader/binder skeleton.
- sampler state handling (wrap/filter/mipmap)
- instanced draw path and per-instance data

### Required outputs
- textured scene
- instancing validation with N instances
- draw call count log

## Day 5 - Week 1 Integration Gate

### Implementation tasks
- integrate triangle/mesh/texture/instance path into one scene
- refactor ownership and cleanup paths
- produce baseline performance numbers

### Acceptance criteria
- app runs stably for 2+ minutes
- no shader compile/link failures
- baseline metrics recorded (`FPS`, `frame ms`, `draw calls`)
- 1-page architecture note completed
