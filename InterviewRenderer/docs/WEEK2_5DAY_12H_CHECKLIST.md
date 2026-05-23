# Week 2 Checklist (5 Days, 6h/Day)

## Day 6 - Camera and Dot/Cross Product Practice

### Read
- LearnOpenGL: Camera.

### Trace
- `Chapter_14/Noise3D/Noise3D.c`
- `Chapter_14/TerrainRendering/TerrainRendering.c`
- `Common/Source/esTransform.c`

### Code practice
- Derive camera `forward`, `right`, and `up` vectors.
- Sketch a look-at matrix using position, target, and world up.
- Write two dot-product examples: one for lighting and one for checking whether an object is in front of the camera.

### Output
- Explain camera basis vectors.
- Explain why cross product order matters.
- Explain how projection changes 3D coordinates into clip space.

## Day 7 - Lighting Shaders

### Read
- LearnOpenGL: Colors.
- LearnOpenGL: Basic Lighting.
- LearnOpenGL: Materials.

### Trace
- `Chapter_14/Noise3D/Noise3D.c`
- `Chapter_14/TerrainRendering/TerrainRendering.c`
- shader strings that use normals, light direction, MVP, or sampled height.

### Code practice
- Design `Light`, `Material`, and shader uniform update flow.
- Write GLSL ES snippets for ambient, diffuse, and specular terms.
- Add notes for `lowp`, `mediump`, and `highp` usage.

### Output
- Explain ambient, diffuse, specular, normal normalization, and Lambert lighting.
- Explain why `max(dot(normal, lightDir), 0.0)` appears in lighting shaders.

## Day 8 - Advanced OpenGL State and Framebuffers

### Read
- LearnOpenGL: Depth Testing.
- LearnOpenGL: Blending.
- LearnOpenGL: Face Culling.
- LearnOpenGL: Framebuffers.

### Trace
- `Chapter_11/MRTs/MRTs.c`
- `Chapter_14/ParticleSystem/ParticleSystem.c`
- `Chapter_14/Shadows/Shadows.c`

### Code practice
- Design `RenderPass`, `Framebuffer`, and `RenderTarget`.
- Sketch pass order for offscreen render -> post-process -> default framebuffer.
- Record which state belongs to a pass: viewport, clear, depth, blend, cull, shader, targets.

### Output
- Explain default framebuffer vs offscreen framebuffer.
- Explain depth buffer, blending order, face culling, and multiple render targets.

## Day 9 - Instancing, Particles, Data-Oriented Layout, Threading

### Read
- LearnOpenGL: Instancing.
- LearnOpenGL: Debugging.

### Trace
- `Chapter_7/Instancing/Instancing.c`
- `Chapter_14/ParticleSystemTransformFeedback/ParticleSystemTransformFeedback.c`

### Code practice
- Sketch `InstanceData` layout for transform and color.
- Sketch a CPU asset-loading worker queue:
  - worker thread reads/decodes files into CPU memory
  - main render thread receives completed jobs
  - render thread creates GL buffers/textures
- Write rules for data ownership across threads.

### Output
- Explain `glVertexAttribDivisor` and per-instance data.
- Explain why GL calls should stay on the render/context thread.
- Explain how threading can help asset loading without making rendering unsafe.

## Day 10 - Shadows, Integration, Interview Packaging

### Read
- LearnOpenGL: Shadow Mapping.
- Skim LearnOpenGL: Advanced Lighting overview.
- Review LearnOpenGL: Debugging.

### Trace
- `Chapter_14/Shadows/Shadows.c`
- `Chapter_14/TerrainRendering/TerrainRendering.c`
- `InterviewRenderer/src/main.cpp`

### Code practice
- Assemble final `InterviewRenderer` architecture note.
- Include sections for:
  - data structures
  - shader system
  - math/camera
  - textures/materials
  - render passes/FBOs
  - threading boundaries
  - performance metrics

### Final acceptance criteria
- Renderer boots reliably on Linux/X11.
- You can explain shadow map pass, depth texture, light-space matrix, and final scene pass.
- You have notes for dot/cross products, MVP, camera, lighting, textures, FBOs, instancing, and threading.
- Interview packet is concise and ready for review.
