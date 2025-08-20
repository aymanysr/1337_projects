# Cub3D Project TODO

Status-driven plan to finish the project according to the 42 subject.

## Done
- [x] MLX window, frame loop, ESC quit.
- [x] Raycast and render wall slices (flat-shaded fallback).
- [x] Floor/ceiling fill via scene colors.
- [x] Player movement + rotation with collision checks.
- [x] Centralized cleanup and error handling.
- [x] Norminette compliance for current modules (no ternaries; small functions).

## Milestone 1 — Restore CLI + Parser Shell
- [x] Re-enable one-argument `.cub` requirement in `init_game`.
- [x] Add `parsing/parser.c` with `parse_and_validate(game, path)`.
- [x] Add `parsing/parser_utils.c` for element helpers.
- [x] Add `validation/validator.c` skeleton with prototypes.
- [x] Update `Makefile` to include new sources.

## Milestone 2 — Parse Elements (NO/SO/WE/EA, F, C)
- [x] Read file with `get_next_line` → `t_list` of lines.
- [x] Iterate lines, skipping empties, parse 6 identifiers, no duplicates.
- [x] Validate RGB in [0,255]; store as `rgb_to_int(r,g,b,255)`.
- [x] `open()` each texture path to ensure the file exists (and `.png` ext).
- [x] Stop when first non-element line is reached; hand remaining lines to map parser.
 - [x] F/C: RGB only (no texture paths for floor/ceiling).

## Milestone 3 — Parse Map + Spawn
- [x] Copy remaining lines into `game->map` (null-terminated).
- [x] Find exactly one `N|S|E|W`; set `player->x,y,angle`.
- [x] Normalize rows (handle spaces) without altering geometry.

## Milestone 4 — Validate Map
- [x] Characters allowed: `' '` `0` `1` (spawn converted to `0`).
- [x] Closed map check: any `0` on edges or touching space → error.
- [x] Error messages start with `Error` and are descriptive.

## Milestone 5 — Textures in Renderer
- [x] Load textures after successful parsing (guard in `load_textures`).
- [x] Determine wall face (vertical/horizontal + ray direction) to choose NO/SO/WE/EA.
- [x] Compute texture X from hit coordinate; Y via step accumulator.
- [x] Keep flat-shaded fallback if any texture load fails.

## Milestone 6 — UX + Cleanup
- [x] Add window-close hook (red cross) to call `cleanup()`.
- [x] Add small sample `.cub` maps for manual testing.
- [x] Run leak checks (`valgrind`/`leaks`) and fix issues (delete MLX image, free all paths/arrays).

## Milestone 7 — Submission Prep
- [x] Remove `-fsanitize=address` from release build (added `dev` target for ASAN).
- [x] Ensure only allowed libs are linked; release build is clean.
- [x] Final Norminette pass on `src`, `includes`, `libft`.
