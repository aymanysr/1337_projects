# Repository Guidelines

This is the 42 Network Cub3D project. Follow 42 rules (Norminette) and the constraints below when contributing.

## Project Structure & Module Organization
- `src/core`: entrypoint, init/teardown, main loop.
- `src/parsing`: `.cub` file parsing and helpers.
- `src/validation`: argument, scene, and map validation.
- `src/rendering`: drawing, ray casting, textures.
- `src/player`: player state and movement.
- `includes`: public headers (see `game.h`).
- `lib/gnl`: get_next_line implementation used by parser.
- `libft`: local C utilities built as a static library.
- `lib/MLX42`: created by `make mx42` (do not edit by hand).

## Build, Test, and Development Commands
- `make`: builds `cub3d` (default target).
- `make clean | fclean | re`: remove objects | all artifacts | rebuild.
- `make mx42`: clones and builds MLX42 into `lib/MLX42/build`.
- Run: `./cub3d` (current state uses a default scene; `.cub` parsing is disabled for now).
- macOS deps: `brew install glfw` (Makefile auto-detects path).
- Linux deps: install GLFW, X11, and dev headers (e.g., `apt install libglfw3-dev xorg-dev`).
- Optional: `norminette src includes libft` to check 42 style locally.

## Coding Style & Naming Conventions
- Language: C (C99, as in 42). Compile with `cc -Wall -Wextra -Werror`; avoid GNU extensions.
- Norminette: follow the official Norm (v3). Run `norminette` before commits.
- Layout limits: ≤25 lines per function, ≤5 functions per file, ≤80 cols.
- Interfaces: ≤4 params per function; ≤5 local vars per function.
- Constructs: no ternary, `for`, `switch`, or `goto`; use `while` and early returns.
- Indentation: tabs; one statement per line; braces on their own lines per existing style.
- Naming: snake_case for files/functions/vars; `t_*`/`s_*` types; macros UPPER_SNAKE.
- Headers: 42 header at top; include guards; prototypes live in `includes/` only.

## Testing Guidelines
- Runtime checks: movement/collisions, ray hits, floor/ceiling fill, frame stability.
- Current state: default scene only; ensure performance and no crashes without textures.
- Memory: no leaks (macOS `leaks --atExit -- ./cub3d` or Linux `valgrind`).
- Style: CI-equivalent is passing Norminette locally before PR.

## Commit & Pull Request Guidelines
- Commits: imperative mood, scoped and small (e.g., `render: add flat wall shade`).
- Explain why + what; reference tasks/issues when relevant.
- PRs: description, verification steps, and short clip/screenshot if rendering changes.
- Requirements: build passes, no leaks, Norminette passes.

## Security & Configuration Tips
- Allowed libs: Libft, MLX (MLX42 here), GNL; no extra third-party deps.
- Do not commit binaries or `lib/MLX42` sources; rely on `make mx42`.
- Input safety: when re-enabling parsing, validate `.cub` fields and fail via `error_exit`.
- Portability: keep Makefile working on macOS (Brew GLFW) and Linux (system GLFW/X11).
