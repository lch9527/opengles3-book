#include "EsContextLinux.h"

#include <X11/Xatom.h>

#include <cstdio>
#include <cstring>
#include <utility>

namespace {
EGLint kContextAttribs[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};

#ifdef EGL_OPENGL_ES3_BIT_KHR
constexpr EGLint kEs3RenderableBit = EGL_OPENGL_ES3_BIT_KHR;
#else
constexpr EGLint kEs3RenderableBit = EGL_OPENGL_ES2_BIT;
#endif

EGLint kConfigAttribs[] = {
    EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
    EGL_RENDERABLE_TYPE, kEs3RenderableBit,
    EGL_RED_SIZE, 8,
    EGL_GREEN_SIZE, 8,
    EGL_BLUE_SIZE, 8,
    EGL_ALPHA_SIZE, 8,
    EGL_DEPTH_SIZE, 24,
    EGL_NONE};
}  // namespace

EsContextLinux::EsContextLinux(int width, int height, const char* title)
    : width_(width), height_(height), title_(title) {}

EsContextLinux::~EsContextLinux() { cleanup(); }

EsContextLinux::EsContextLinux(EsContextLinux&& other) noexcept { *this = std::move(other); }

EsContextLinux& EsContextLinux::operator=(EsContextLinux&& other) noexcept {
  if (this != &other) {
    cleanup();
    width_ = other.width_;
    height_ = other.height_;
    title_ = other.title_;
    xDisplay_ = other.xDisplay_;
    window_ = other.window_;
    wmDeleteMessage_ = other.wmDeleteMessage_;
    eglDisplay_ = other.eglDisplay_;
    eglSurface_ = other.eglSurface_;
    eglContext_ = other.eglContext_;

    other.xDisplay_ = nullptr;
    other.window_ = 0;
    other.wmDeleteMessage_ = 0;
    other.eglDisplay_ = EGL_NO_DISPLAY;
    other.eglSurface_ = EGL_NO_SURFACE;
    other.eglContext_ = EGL_NO_CONTEXT;
  }
  return *this;
}

bool EsContextLinux::initialize() {
  xDisplay_ = XOpenDisplay(nullptr);
  if (!xDisplay_) return false;

  Window root = DefaultRootWindow(xDisplay_);
  XSetWindowAttributes attributes{};
  attributes.event_mask = ExposureMask | KeyPressMask | StructureNotifyMask;

  window_ = XCreateWindow(xDisplay_, root, 0, 0, width_, height_, 0, CopyFromParent,
                          InputOutput, CopyFromParent, CWEventMask, &attributes);
  if (!window_) return false;

  wmDeleteMessage_ = XInternAtom(xDisplay_, "WM_DELETE_WINDOW", False);
  XSetWMProtocols(xDisplay_, window_, &wmDeleteMessage_, 1);
  XStoreName(xDisplay_, window_, title_);
  XMapWindow(xDisplay_, window_);

  eglDisplay_ = eglGetDisplay((EGLNativeDisplayType)xDisplay_);
  if (eglDisplay_ == EGL_NO_DISPLAY) return false;

  if (!eglInitialize(eglDisplay_, nullptr, nullptr)) return false;

  EGLConfig config = nullptr;
  EGLint numConfigs = 0;
  if (!eglChooseConfig(eglDisplay_, kConfigAttribs, &config, 1, &numConfigs) || numConfigs < 1) {
    return false;
  }

  eglSurface_ = eglCreateWindowSurface(eglDisplay_, config, (EGLNativeWindowType)window_, nullptr);
  if (eglSurface_ == EGL_NO_SURFACE) return false;

  eglContext_ = eglCreateContext(eglDisplay_, config, EGL_NO_CONTEXT, kContextAttribs);
  if (eglContext_ == EGL_NO_CONTEXT) return false;

  if (!eglMakeCurrent(eglDisplay_, eglSurface_, eglSurface_, eglContext_)) return false;

  return true;
}

bool EsContextLinux::shouldClose() {
  XEvent event;
  while (XPending(xDisplay_)) {
    XNextEvent(xDisplay_, &event);
    if (event.type == ClientMessage && static_cast<Atom>(event.xclient.data.l[0]) == wmDeleteMessage_) {
      return true;
    }
    if (event.type == DestroyNotify) {
      return true;
    }
  }
  return false;
}

void EsContextLinux::swapBuffers() { eglSwapBuffers(eglDisplay_, eglSurface_); }

void EsContextLinux::cleanup() noexcept {
  if (eglDisplay_ != EGL_NO_DISPLAY) {
    eglMakeCurrent(eglDisplay_, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    if (eglContext_ != EGL_NO_CONTEXT) eglDestroyContext(eglDisplay_, eglContext_);
    if (eglSurface_ != EGL_NO_SURFACE) eglDestroySurface(eglDisplay_, eglSurface_);
    eglTerminate(eglDisplay_);
  }
  eglDisplay_ = EGL_NO_DISPLAY;
  eglSurface_ = EGL_NO_SURFACE;
  eglContext_ = EGL_NO_CONTEXT;

  if (xDisplay_ && window_) {
    XDestroyWindow(xDisplay_, window_);
  }
  if (xDisplay_) {
    XCloseDisplay(xDisplay_);
  }
  xDisplay_ = nullptr;
  window_ = 0;
}
