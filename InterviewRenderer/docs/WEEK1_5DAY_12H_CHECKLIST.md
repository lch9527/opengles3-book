# Week 1 Checklist (5 Days, 6h/Day)

## Day 1 - Completed: Environment + Rendering Flow Grounding

### Read
- LearnOpenGL: OpenGL, Creating a Window, Hello Window, Hello Triangle.

### Trace
1. `Common/Include/esUtil.h`
2. `Common/Source/esUtil.c`
3. `Common/Source/LinuxX11/esUtil_X11.c`
4. `Chapter_2/Hello_Triangle/Hello_Triangle.c`

### Required outputs
- Explain `ESContext` lifecycle and EGL setup.
- Explain where the draw loop calls the user callback.
- Write 10 bullets on disk-to-pixel flow.

## Day 2 - Triangle, Shaders, First Data Structures

### Read
- LearnOpenGL: Hello Triangle.
- LearnOpenGL: Shaders.

### Trace
- `Chapter_2/Hello_Triangle/Hello_Triangle.c`
- `Chapter_6/Example_6_3/Example_6_3.c`
- `InterviewRenderer/src/ShaderProgram.cpp`
- `InterviewRenderer/src/main.cpp`

### Code practice
- Define responsibilities for `Vertex`, `MeshData`, and `ShaderProgram`.
- Build and run `InterviewRenderer`.
- Record one shader compile/link failure mode and how the code reports it.

### Required outputs
- Explain vertex attributes, vertex shader, fragment shader, program link, and draw call.
- Write a small data-structure note: what lives on CPU vs GPU for a triangle.

## Day 3 - Buffers, VAOs, Indexing, Memory Layout

### Read
- LearnOpenGL: buffer objects and VAO parts from Hello Triangle.
- Skim LearnOpenGL: Advanced Data.

### Trace
- `Chapter_6/VertexBufferObjects/VertexBufferObjects.c`
- `Chapter_6/VertexArrayObjects/VertexArrayObjects.c`
- `Chapter_6/MapBuffers/MapBuffers.c`

### Code practice
- Design `BufferObject`, `VertexArray`, and `Mesh` RAII wrappers.
- Include copy-delete and move-allow ownership policy.
- Write a small layout table for position, normal, color, and UV attributes.

### Required outputs
- Explain CPU array vs GPU buffer.
- Explain stride, offset, index buffer, and VAO state.
- List two bugs caused by incorrect attribute layout.

## Day 4 - Textures and Disk-to-Pixel

### Read
- LearnOpenGL: Textures.

### Trace
- `Chapter_9/Simple_Texture2D/Simple_Texture2D.c`
- `Chapter_9/TextureWrap/TextureWrap.c`
- `Chapter_9/MipMap2D/MipMap2D.c`
- `Chapter_10/MultiTexture/MultiTexture.c`
- `Common/Source/esUtil.c` texture loading path.

### Code practice
- Design `Texture2D`, `SamplerState`, and `Material`.
- Sketch texture lifetime: file path -> CPU pixels -> GL texture -> shader sampler.
- Record texture unit binding rules for one-texture and two-texture cases.

### Required outputs
- Explain `esLoadTGA`, `glTexImage2D`, wrap modes, filters, mipmaps, and sampler uniforms.
- Write one paragraph on why texture upload and texture sampling are separate steps.

## Day 5 - 3D Math Foundation

### Read
- LearnOpenGL: Transformations.
- LearnOpenGL: Coordinate Systems.

### Trace
- `Chapter_6/Example_6_6/Example_6_6.c`
- `Chapter_8/Simple_VertexShader/Simple_VertexShader.c`
- `Common/Source/esTransform.c`

### Code practice
- Sketch or implement `Vec3`, `Mat4`, `dot`, `cross`, `normalize`, and matrix multiply tests.
- Write expected results for:
  - `dot((1,0,0), (0,1,0))`
  - `cross((1,0,0), (0,1,0))`
  - normalizing `(3,4,0)`

### Acceptance criteria
- Explain local, world, view, clip, NDC, and screen spaces.
- Explain model, view, projection, and MVP matrix order.
- Explain how dot product relates to angle and how cross product creates a perpendicular vector.
