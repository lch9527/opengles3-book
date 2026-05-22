# Week 2 Checklist (5 Days, 12h/Day)

## Day 6 - GLSL Intensive

### Tasks
- precision strategy (`lowp/mediump/highp`) and tradeoffs
- coordinate-space review in shaders
- shader debugging workflow (logs + visual toggles)

### Output
- GLSL note sheet with concrete do/don't rules

## Day 7 - Lighting and Material Controls

### Tasks
- implement Lambert + Blinn-Phong shaders
- material parameter controls (diffuse/spec/gloss)
- normal-ready structure for future map support

### Output
- lit scene presets and tradeoff notes

## Day 8 - Anti-aliasing and Post Process

### Tasks
- enable MSAA path where supported
- build FBO offscreen path
- implement one post-pass (tone/contrast/vignette)

### Output
- before/after visual comparison notes

## Day 9 - Performance Debug and Optimization

### Tasks
- profile CPU/GPU bottlenecks
- reduce redundant state changes
- reduce draw-call pressure
- log memory footprint for textures and buffers

### Output
- optimization report with before/after metrics

## Day 10 - Interview Packaging

### Tasks
- final code cleanup and README
- architecture diagram and render pipeline summary
- prepare 8 interview stories (bugs, perf, tradeoffs)
- mock Q&A drills for Tesla rendering topics

### Final acceptance criteria
- renderer boots reliably on Linux/X11
- lighting + post-process path works
- measured optimization improvement is documented
- interview packet is ready and concise
