# Fusion_View – Task Breakdown

## Overall Goal
Build a desktop visualization tool for robotics/AV:
- Synchronized timeline for multi-sensor data (LiDAR point clouds, camera images, diagnostics, plots).
- Supports live streaming and log playback; easy to extend with new data types and panels.
- Smooth, low-latency OpenGL rendering with safe, cross‑thread data flow.
- Configuration-driven layouts, styles, and sources; portable Windows-first build with CPM-managed deps.

## Architecture Summary
- Timebase controls playback/scrubbing/speed; every message has a timestamp (ns).
- Topic stores are append-only, time-indexed buffers per type/topic with fast sample_at(T) queries.
- Transports ingest live or recorded data and publish typed messages to stores.
- Panels are ImGui windows; renderers draw GPU resources (3D view, image, plots) from store samples.
- Registries provide pluggable panels, renderers, and transports; simple static registration macros.

Core data types (initial): PointCloud (xyz + intensity), ImageRGBA, Diagnostics (KV table), Series (time,y).

## Dependency Plan (CPM)
- Required: glfw, glad (generator), imgui (+freetype), glm, stb, implot, spdlog, fmt, nlohmann_json.
- Optional later: eigen (geometry), ZMQ (live UDP/TCP), mcap/rosbag2 (log playback).

---

## Completed
- [x] Migrate dependencies to CPM
  - GLFW (3.3.8), GLM (1.0.1), FreeType (VER-2-13-3), ImGui (1.90.9 with backends + freetype)
  - GLAD via Python generator (OpenGL 3.3 core)
- [x] Remove vendored folders now replaced by CPM
  - Deleted: `dependencies/glfw`, `dependencies/imgui`, `dependencies/freetype`
- [x] Add stb via CPM; remove `dependencies/imgui_addons`

## Phase 1 – Core & Scaffolding
- [ ] Create folders: `core/`, `types/`, `render/`, `panels/`, `transport/`
- [ ] Implement `Timebase` (play/pause, speed, seek, tick)
- [ ] Implement `TopicStore<T>` (append-only, sample_at, range)
- [ ] Implement `Registry` (stores, panels, renderers, transports)
- [ ] Define `types/` messages: `PointCloud`, `ImageRGBA`, `Diagnostics`, `Series`
- [ ] Add `AppContext` (timebase, registry, resources, logger)
- [ ] Add logging (`spdlog`) and config (`nlohmann_json`)
- [ ] App dockspace + status bar; load/save layout (ImGui ini)

## Phase 2 – Rendering Basics
- [ ] `GpuPointCloud` (VBO/SSBO, persistent mapping, color modes)
- [ ] `GpuImageQuad` (texture + PBO upload)
- [ ] Minimal shader set in `assets/shaders`
- [ ] `RendererRegistry` and `Scene` container
- [ ] `Panel3D` (camera orbit/FPS, grid/axes, overlays)
- [ ] `PanelImage` (fit/fill/1:1, zoom/pan)

## Phase 3 – Timeline & Data Flow
- [ ] `PanelTimeline` (scrub, play/pause, speed, range)
- [ ] Mock data source for all types (synthetic)
- [ ] File player v0: simple framed file or MCAP reader skeleton
- [ ] Cross-thread queues; safe store updates; snapshot reads on UI thread

## Phase 4 – Diagnostics & Plots
- [ ] `PanelDiagnostics` (KV table + history)
- [ ] `PanelPlot` via ImPlot (multi-series; downsampling for large windows)
- [ ] Topic selection UX and per-panel settings

## Phase 5 – Real Data Sources
- [ ] MCAP reader (or rosbag2) → `Message<T>` adapters
- [ ] Live UDP/TCP (`ZMQ`) adapters for LiDAR/camera/telemetry
- [ ] Extrinsics/frames metadata; world/map frame handling

## Phase 6 – Performance
- [ ] Persistent mapped buffers; PBO path finalized
- [ ] Point budget & simple LOD; frustum culling
- [ ] Zero/allocation frames; memory pools for decode
- [ ] Profiling HUD; timings per panel/source

## Phase 7 – Configuration & UX
- [ ] JSON project file (sources, topics, styles, transforms, layout)
- [ ] Layout save/restore; keybindings & camera presets
- [ ] Theming & color presets

## Phase 8 – Packaging & CI
- [ ] Add `implot`, `spdlog`, `fmt`, `nlohmann_json` via CPM (pin versions)
- [ ] Set `CPM_SOURCE_CACHE` and (optionally) re-enable CPM hash pin
- [ ] Minimal unit tests for stores/timebase/parsers
- [ ] Release presets; artifact packaging instructions

