# InterviewRenderer

Linux-first C++ OpenGL ES renderer scaffold for interview preparation.

## Build (inside WSL2 Ubuntu)

```bash
cd /mnt/e/GraphicInterviewPractice/opengles3-book
cmake -S . -B build
cmake --build build -j"$(nproc)"
./build/InterviewRenderer/InterviewRenderer
```

## Current scope

- X11 + EGL context wrapper (`EsContextLinux`)
- shader compilation/link wrapper (`ShaderProgram`)
- minimal triangle render loop

## Next milestones

- buffer/VAO/texture RAII wrappers
- MVP camera path
- instancing path
- lighting and post-processing passes
- performance metric instrumentation
