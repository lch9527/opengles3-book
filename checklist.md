# Checklist

## Question: Write 10 bullets on disk-to-pixel flow.

- The app starts by creating a native window and EGL context: `WinCreate`/`esCreateWindow` on the sample side, or `EsContextLinux::initialize()` in `InterviewRenderer`.
- EGL selects a framebuffer configuration, creates a window surface, creates an OpenGL ES 3 context, and makes that context current before any GL object work happens.
- Image assets on disk, such as `basemap.tga`, `lightmap.tga`, or `heightmap.tga`, are opened through `esLoadTGA`, which uses platform-specific file access and reads the TGA header plus raw pixel bytes.
- The loader returns CPU-side pixel memory and image dimensions; caller code checks for failure before trying to upload anything to the GPU.
- Texture setup allocates a GPU texture name with `glGenTextures`, binds it with `glBindTexture`, and transfers CPU pixels into GPU texture storage with `glTexImage2D`.
- Texture state is completed with sampler-relevant parameters such as min/mag filtering and wrap modes, then the temporary CPU pixel buffer is freed.
- Shader source is compiled and linked into a program with `esLoadProgram` or the C++ `ShaderProgram` wrapper; texture uniforms such as `s_baseMap` are queried with `glGetUniformLocation`.
- Per-frame draw code sets viewport and clears buffers, binds vertex/index data, enables attributes for positions and texture coordinates, and activates the shader program.
- The texture is assigned to a texture unit with `glActiveTexture`/`glBindTexture`, and the sampler uniform is set with `glUniform1i` so the fragment or vertex shader samples the correct uploaded image.
- The draw call runs the pipeline, shader output lands in the EGL surface color buffer, and `eglSwapBuffers` presents that rendered buffer to the X11/WSLg window as visible pixels.
