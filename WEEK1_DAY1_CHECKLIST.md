# Week 1 Day 1 Checklist (WSL2 Ubuntu 24.04, Linux + C++)

Target session length: `~5 hours`

## 0) Session Goal

By end of Day 1 you should:

- have WSL2 Ubuntu toolchain ready
- compile this repo in Linux
- run `Hello_Triangle`
- understand Linux platform path in `Common`
- draft first C++ wrapper skeleton

## 1) Environment Bring-Up (60-75 min)

Run in Ubuntu terminal:

```bash
sudo apt update
sudo apt install -y \
  build-essential cmake pkg-config \
  libx11-dev libegl1-mesa-dev libgles2-mesa-dev \
  mesa-utils
```

Expected:

- install completes with no missing package errors

Sanity check:

```bash
cmake --version
g++ --version
```

Expected:

- both commands print versions successfully

## 2) Configure + Build Repo (45-60 min)

```bash
cd /mnt/e/GraphicInterviewPractice/opengles3-book
cmake -S . -B build
cmake --build build -j"$(nproc)"
```

Expected:

- CMake configure succeeds
- build completes and creates sample binaries under `build/Chapter_*`

If build fails, capture first error line and the 20 lines above it.

## 3) Run First Sample (30 min)

```bash
./build/Chapter_2/Hello_Triangle/Hello_Triangle
```

Expected:

- window opens through WSLg
- triangle renders
- app exits cleanly when closed

Optional GPU info:

```bash
glxinfo -B
```

Expected:

- renderer/vendor/version information visible

## 4) Code Reading Block: Linux Context Path (60 min)

Read these in order:

1. `Common/Include/esUtil.h`
2. `Common/Source/esUtil.c`
3. `Common/Source/LinuxX11/esUtil_X11.c`
4. `Chapter_2/Hello_Triangle/Hello_Triangle.c`

Focus questions:

- Where is `ESContext` populated?
- Where are EGL display/context/surface created?
- Where does render loop call `drawFunc`?
- How does sample initialize shaders + vertex data?

Output artifact:

- write 8-12 bullet notes in your study notebook.

## 5) C++ Mapping Draft (45-60 min)

Create a scratch note (no repo edits required yet) with these class outlines:

- `class EsContextLinux`
- `class ShaderProgram`
- `class BufferObject`

For each class define:

- constructor responsibilities
- destructor cleanup
- move-only policy (`delete` copy, allow move)

Minimum pseudocode target:

```cpp
class ShaderProgram {
public:
  ShaderProgram(std::string_view vs, std::string_view fs);
  ~ShaderProgram();
  ShaderProgram(const ShaderProgram&) = delete;
  ShaderProgram& operator=(const ShaderProgram&) = delete;
  ShaderProgram(ShaderProgram&&) noexcept;
  ShaderProgram& operator=(ShaderProgram&&) noexcept;
  void use() const noexcept;
private:
  unsigned int id_{0};
};
```

## 6) End-of-Day Validation (15 min)

You are done with Day 1 when all are true:

- Linux dependencies installed
- repo builds on WSL2
- `Hello_Triangle` runs
- LinuxX11 + EGL flow understood at high level
- first C++ wrapper draft exists

## 7) Troubleshooting Quick Notes

- If window does not open:
  - run `echo $DISPLAY`
  - run `glxinfo -B`
  - ensure you launched from WSL2 Ubuntu (not PowerShell)
- If EGL headers not found:
  - recheck `libegl1-mesa-dev` and `libgles2-mesa-dev` install
- If build artifacts look stale:
  - remove `build/` and reconfigure:
    - `rm -rf build && cmake -S . -B build`
