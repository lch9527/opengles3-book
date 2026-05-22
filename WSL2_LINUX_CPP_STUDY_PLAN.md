# OpenGL ES 3 Book: WSL2 Linux + C++ Implementation Plan

This guide implements the agreed path:

- Platform: Windows 11 + WSL2 (`Ubuntu 24.04`)
- Focus: Linux/X11 samples + parallel C++ learning
- Pace: `30 hours/week`, `2 weeks total`

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

## 2) Install Linux Build Dependencies (Inside Ubuntu)

Run:

```bash
sudo apt update
sudo apt install -y \
  build-essential cmake pkg-config \
  libx11-dev libegl1-mesa-dev libgles2-mesa-dev \
  mesa-utils
```

## 3) Build This Repo in Linux (Inside Ubuntu)

If your repo is on Windows drive `E:`, access it from WSL at:
`/mnt/e/GraphicInterviewPractice/opengles3-book`

```bash
cd /mnt/e/GraphicInterviewPractice/opengles3-book
cmake -S . -B build
cmake --build build -j"$(nproc)"
```

## 4) Smoke Test the First Sample

From repo root:

```bash
./build/Chapter_2/Hello_Triangle/Hello_Triangle
```

Expected result: a sample window opens via WSLg.

Optional renderer check:

```bash
glxinfo -B
```

## 5) Study Workflow Rule (Per Sample)

For each chapter sample:

1. Build and run original C sample.
2. Trace core flow:
   - context/window creation
   - shader compile/link
   - buffers/VAO/textures/FBO logic
3. Re-implement same sample behavior in modern C++:
   - RAII resource wrappers
   - explicit ownership/lifetimes
   - minimal global state

## 6) Accelerated 2-Week Schedule (30h/week)

### Week 1

- Day 1: `Common` internals (`esUtil`, shaders, transforms, LinuxX11 path)
- Day 2: `Hello_Triangle`, `Example_6_3`, `Example_6_6`
- Day 3: `MapBuffers`, `VertexBufferObjects`
- Day 4: `VertexArrayObjects`, `Instancing`, `Simple_VertexShader`
- Day 5: `Simple_Texture2D`, `TextureWrap`, `MipMap2D`
- Day 6: C++ cleanup/refactor buffer day

### Week 2

- Day 1: `Simple_TextureCubemap`, `MultiTexture`
- Day 2: `MRTs`, `Noise3D`
- Day 3: `ParticleSystem`, `ParticleSystemTransformFeedback`
- Day 4: `Shadows`, `TerrainRendering`
- Day 5: Capstone integration (instancing + textures + FBO/shadow path)
- Day 6: Stabilization, notes, final review

## 7) Repo Sample Map (Linux Native C Targets)

- Chapter 2: `Hello_Triangle`
- Chapter 6: `Example_6_3`, `Example_6_6`, `MapBuffers`, `VertexArrayObjects`, `VertexBufferObjects`
- Chapter 7: `Instancing`
- Chapter 8: `Simple_VertexShader`
- Chapter 9: `Simple_Texture2D`, `Simple_TextureCubemap`, `MipMap2D`, `TextureWrap`
- Chapter 10: `MultiTexture`
- Chapter 11: `MRTs`
- Chapter 14: `Noise3D`, `ParticleSystem`, `ParticleSystemTransformFeedback`, `Shadows`, `TerrainRendering`

## 8) Daily Validation Checklist

- `cmake --build build -j"$(nproc)"` completes
- sample(s) for the day run without crash
- shader compile/link logs clean
- C++ port for same feature compiles and runs
- short note captured: what changed, what broke, what learned

## 9) Session Checklists

- Week 1 Day 1 execution checklist:
  - `WEEK1_DAY1_CHECKLIST.md`
