# 2D Game Engine

> A small C++ game-engine playground built from first principles with SDL2.

This project is the beginning of a lightweight 2D game engine and a practical learning space for computer graphics, game loops, input handling, asset management, and engine architecture.

The goal is not to hide the fundamentals behind a large framework. Instead, the engine grows one subsystem at a time so that every window, event, frame, and rendered object can be understood and extended.

## Current state

The first engine milestone is complete:

- Opens an `800x600` borderless SDL window
- Creates an SDL renderer
- Runs the core game-loop cycle: input -> update -> render
- Exits when the window is closed or `Esc` is pressed
- Clears the frame with a red background
- Includes a starter asset library for future gameplay and rendering work

At this stage, the bundled images and sounds are prepared for upcoming systems but are not yet loaded by the C++ code. The project is intentionally a foundation, not yet a complete game.

## The engine loop

Each frame follows the same simple pipeline:

```text
Process input/events -> Update game state -> Render the frame -> Present frame
        ^                                                        |
        +------------------------- next frame ------------------+
```

This separation is the core idea behind most real-time applications: input changes the world, update advances its state, and rendering turns that state into pixels.

## Technology

- **C++17** - engine implementation
- **SDL2** - window creation, event processing, and 2D rendering
- **GLM** - vector and matrix mathematics for future graphics systems
- **Dear ImGui** - immediate-mode tooling for future debugging/editor interfaces
- **Lua + Sol2** - scripting foundation for future gameplay logic
- **Make** - build and run commands

The third-party libraries are kept locally in `libs/` so the project can evolve as a self-contained learning environment.

## Project structure

```text
2dgameengine/
|- assets/
|  |- fonts/       Fonts for UI and in-game text
|  |- images/      Vehicles, helicopter, bullets, trees, and UI sprites
|  |- sounds/      Audio assets
|  `- tilemaps/    Jungle map data and tileset
|- libs/
|  |- glm/         Mathematics
|  |- imgui/       Debug/editor UI foundation
|  |- lua/         Lua headers
|  `- sol/         C++/Lua binding
|- src/
|  |- Game.h       Game class interface
|  |- Game.cpp     SDL lifecycle and main loop
|  `- Main.cpp     Application entry point
|- Makefile
`- README.md
```

## Requirements

You need:

- A C++17-compatible compiler, such as `g++` or `clang++`
- GNU Make
- SDL2 development libraries: SDL2, SDL2_image, SDL2_ttf, and SDL2_mixer
- Lua 5.3 development libraries

On Debian or Ubuntu, install the dependencies with:

```bash
sudo apt update
sudo apt install build-essential \
  libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev \
  liblua5.3-dev
```

## Build and run

```bash
git clone <repository-url>
cd 2dgameengine
make build
make run
```

You should see the current SDL window with a red background. Close the window or press `Esc` to exit.

Remove the generated executable with:

```bash
make clean
```

The generated `gameengine` executable is intentionally excluded from version control through `.gitignore`.

## Controls

| Input | Action |
|---|---|
| `Esc` | Quit the engine |
| Window close button | Quit the engine |

Gameplay controls will be added as the input and gameplay systems develop.

## Learning path

The project is designed to grow through small, understandable milestones:

1. Add frame timing and delta time
2. Load and draw textures from `assets/images`
3. Add sprite animation using the helicopter spritesheet
4. Load the jungle tilemap and build a camera system
5. Add entities, collision detection, and gameplay state
6. Introduce audio, UI, and Lua-driven behavior
7. Build debugging tools and an in-engine editor with ImGui

Each step should extend an existing subsystem instead of replacing the engine with a heavier abstraction.

## Contributing to the experiment

Keep changes focused and easy to understand. A useful contribution should ideally include:

- A clear reason for the change
- Small, focused code
- A reproducible way to test it
- Notes about any new dependency or platform assumption

This repository is primarily an educational engine project, so readable design and strong fundamentals matter as much as the visual result.

## License

The project contains third-party libraries and assets. Check the license files in `libs/` and the relevant asset directories before redistributing them.
