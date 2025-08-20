# Cub3D Project Hints

These hints bridge the current repo state (default scene, no .cub parser) to a complete Cub3D per the subject. Keep 42 Norminette in mind at every step (no ternary/for/switch/goto; ≤25 lines per function; ≤5 functions per file).

## 1) Introduce Parsing Incrementally
- Read → Stage → Parse: first read all lines with `get_next_line` into `t_list`. Then:
  1) Parse elements (NO/SO/WE/EA, F/C) in any order, skipping empty lines.
  2) Remaining lines form the map block.
- API surface: add `parse_and_validate(game, path)` that fills `scene`, `map`, spawns the player, and runs validation before textures load.

## 2) Validation Essentials
- Arguments: single `.cub` argument; extension check; meaningful errors prefixed with “Error”.
- Scene: exactly 6 identifiers, no duplicates; `open()` each texture path to verify.
- Map: characters only in set ` 01NSEW`; exactly one player; closed by walls.
- Flood fill: copy map; start at player cell; if fill touches edges or spaces, it’s open.

## 3) Textured Rendering Notes
- Wall face: need vertical vs horizontal hit and ray direction to pick NO/SO/WE/EA.
- Texture X: use fractional wall-hit coordinate vs texture width.
- Texture Y: `step = tex_h / wall_h`; y-accumulator increases per pixel.
- Fallback: if textures are missing, keep flat shading (already implemented).

## 4) Memory + Errors
- Central cleanup already in place. Always use `error_exit()` to print and free.
- Free order: scene paths → textures (mlx_delete_texture) → map (rows then array) → player → mlx → game.

## 5) Step-by-Step Implementation Plan
1. Reintroduce `parsing/` with `parse_and_validate`, `parser_utils` split.
2. Reintroduce `validation/` with argument, scene, map checks and flood fill.
3. Wire `init_game()` to use parser when an argument is present; fallback to default scene if none (dev convenience).
4. Set player spawn/angle from map N/S/E/W.
5. Enable `load_textures()` only after valid paths; otherwise run flat.
6. Add MLX window-close hook to call `cleanup()`.
7. Remove `-fsanitize=address` for final submission build.
8. Run Norminette and leaks checks (`valgrind`/`leaks`) until clean.
