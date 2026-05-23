#pragma once

#include <EGL/egl.h>
#include <EGL/eglext.h>

#include <X11/Xlib.h>

class EsContextLinux {
public:
  EsContextLinux(int width, int height, const char* title);
  ~EsContextLinux();

  EsContextLinux(const EsContextLinux&) = delete;
  EsContextLinux& operator=(const EsContextLinux&) = delete;
  EsContextLinux(EsContextLinux&& other) noexcept;
  EsContextLinux& operator=(EsContextLinux&& other) noexcept;

  bool initialize();
  bool shouldClose();
  void swapBuffers();

  int width() const noexcept { return width_; }
  int height() const noexcept { return height_; }

private:
  void cleanup() noexcept;

  int width_;
  int height_;
  const char* title_;

  Display* xDisplay_{nullptr};
  Window window_{0};
  Atom wmDeleteMessage_{0};

  EGLDisplay eglDisplay_{EGL_NO_DISPLAY};
  EGLSurface eglSurface_{EGL_NO_SURFACE};
  EGLContext eglContext_{EGL_NO_CONTEXT};
};
