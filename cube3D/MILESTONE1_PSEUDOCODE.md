# Milestone 1 — CLI + Parser Shell (Pseudo Code)

Goal: Restore 42-compliant CLI (single `.cub` argument) and scaffold a minimal parser pipeline that reads lines and splits them into elements vs. map. Keep it Norm-friendly and memory-safe; detailed validation and semantics come in later milestones.

## Overview
- Enforce CLI: `./cub3d file.cub` only; otherwise print `Error: ...` and exit via `error_exit`.
- Read file into `t_list *lines` using `get_next_line`.
- Stage parsing in two phases: scene elements first, then map block.
- Produce: `game->scene` filled (paths/colors may remain placeholders) and `game->map` allocated; player spawn/validation deferred to later milestones.

## init_game (in src/core/main.c)
Pseudo code
```
function init_game(game, argc, argv):
    if argc != 2:
        error_exit("Invalid number of arguments", game)
    if not ends_with(argv[1], ".cub"):
        error_exit("Invalid file extension", game)

    game->scene = calloc(1, sizeof(t_scene))
    if not game->scene: error_exit("Memory allocation failed", game)

    game->player = calloc(1, sizeof(t_player))
    if not game->player: error_exit("Memory allocation failed", game)

    parse_and_validate(game, argv[1])

    // continue with MLX init, image creation, textures, hooks, etc.
```

## parse_and_validate (src/parsing/parser.c)
Pseudo code
```
function parse_and_validate(game, file_path):
    fd = open(file_path, O_RDONLY)
    if fd < 0: error_exit("Failed to open map file", game)

    lines = read_file_lines(fd)
    close(fd)
    if lines == NULL: error_exit("Empty or unreadable file", game)

    cursor = lines
    // Phase 1: scene elements (NO/SO/WE/EA, F, C)
    parse_scene_elements(&cursor, game)

    // Phase 2: map block (remaining lines)
    parse_map(cursor, game)

    // ownership of cursor's content duplicated into game->map
    // free list lines after use
    lstclear(&lines, free)
```

## read_file_lines (src/parsing/parser.c)
Pseudo code
```
function read_file_lines(fd) -> t_list*:
    list = NULL
    line = get_next_line(fd)
    while line is not NULL:
        lstadd_back(&list, lstnew(line)) // store line as-is; free later via lstclear
        line = get_next_line(fd)
    return list
```

## parse_scene_elements (src/parsing/parser.c)
Rules (skeleton):
- Skip blank/whitespace-only lines.
- Accept up to 6 identifiers: `NO`, `SO`, `WE`, `EA`, `F`, `C`.
- Stop at first non-empty line that is not a valid element; that node is the start of the map.
Pseudo code
```
function parse_scene_elements(&cursor, game):
    elements_parsed = 0
    while cursor != NULL and elements_parsed < 6:
        trimmed = strtrim(cursor->content, " ")
        if trimmed == NULL: error_exit("Memory allocation failed", game)

        if length(trimmed) == 0:
            free(trimmed)
            cursor = cursor->next
            continue

        if parse_single_element(trimmed, game) == 0:
            elements_parsed += 1
            free(trimmed)
            cursor = cursor->next
            continue

        // Not an element → map starts here
        free(trimmed)
        break

    // Hand back updated position
    set_out_param(cursor)
```

## parse_map (src/parsing/parser.c)
Skeleton intent (no deep validation yet):
- Count remaining list nodes → allocate `game->map` with `count + 1`.
- Duplicate each `content` (line) into `game->map[i]` (keep spaces; do not trim).
- Null-terminate `game->map`.
Pseudo code
```
function parse_map(cursor, game):
    if cursor == NULL: error_exit("Map is missing", game)

    h = lstsize(cursor)
    game->map = calloc(h + 1, sizeof(char*))
    if not game->map: error_exit("Memory allocation failed", game)

    i = 0
    node = cursor
    while node != NULL:
        game->map[i] = strdup(node->content)
        if not game->map[i]: error_exit("Memory allocation failed", game)
        i += 1
        node = node->next
    game->map[i] = NULL
```

## parser_utils (src/parsing/parser_utils.c)
Recognize identifiers and dispatch to simple setters. Full validation comes later.
Pseudo code
```
function parse_single_element(line, game) -> int:
    // return 0 if 'line' is a valid element; else non-zero
    parts = split(line, ' ')
    if parts == NULL: error_exit("Memory allocation failed", game)

    if parts[0] == NULL or parts[1] == NULL or parts[2] != NULL:
        free_string_array(parts)
        return 1

    if strncmp(parts[0], "NO", 3) == 0:
        res = parse_texture(parts, &game->scene->no_texture_path, game)
    else if strncmp(parts[0], "SO", 3) == 0:
        res = parse_texture(parts, &game->scene->so_texture_path, game)
    else if strncmp(parts[0], "WE", 3) == 0:
        res = parse_texture(parts, &game->scene->we_texture_path, game)
    else if strncmp(parts[0], "EA", 3) == 0:
        res = parse_texture(parts, &game->scene->ea_texture_path, game)
    else if strncmp(parts[0], "F", 2) == 0:
        res = parse_color(parts, &game->scene->floor_color, game)
    else if strncmp(parts[0], "C", 2) == 0:
        res = parse_color(parts, &game->scene->ceiling_color, game)
    else:
        free_string_array(parts)
        return 1

    free_string_array(parts)
    return res

function parse_texture(parts, *dest, game) -> int:
    if *dest != NULL: error_exit("Duplicate texture identifier", game)
    *dest = strdup(parts[1])
    if *dest == NULL: error_exit("Memory allocation failed", game)
    return 0

function parse_color(parts, *dest, game) -> int:
    rgb_parts = split(parts[1], ',')
    if rgb_parts == NULL: error_exit("Memory allocation failed", game)
    if rgb_parts[0] == NULL or rgb_parts[1] == NULL or rgb_parts[2] == NULL or rgb_parts[3] != NULL:
        free_string_array(rgb_parts)
        return 1
    r = atoi(rgb_parts[0]); g = atoi(rgb_parts[1]); b = atoi(rgb_parts[2])
    free_string_array(rgb_parts)
    // Range checks and exact format validation deferred to Milestone 2
    *dest = rgb_to_int(r, g, b, 255)
    return 0
```

## validate_arguments (src/validation/validator.c)
Keep it minimal for M1: argument count and extension only.
```
function validate_arguments(argc, argv):
    if argc != 2:
        print to stderr("Error: Invalid number of arguments")
        exit(1) // or error_exit
    if not ends_with(argv[1], ".cub"):
        print to stderr("Error: Invalid file extension")
        exit(1)
```

## Error Handling
- Use `error_exit(msg, game)` for any memory or file-related failure.
- Ensure all allocations are checked; never proceed on NULL.
- After duplicating map lines, `lstclear(&lines, free)` to avoid leaks.

## Makefile (what to add)
```
# Add these sources back for M1 skeleton
SRC += \
  src/parsing/parser.c \
  src/parsing/parser_utils.c \
  src/validation/validator.c
```

## Sanity Test (manual)
- Create `maps/minimal.cub` with only the 6 identifiers and a tiny map.
- Run `./cub3d maps/minimal.cub`.
- For M1: textures may not load; engine should still start and render flat walls using defaults or later milestones.

## Next Milestones Hook
- M2: strengthen `parse_color` and add duplicate/complete checks.
- M3: implement player spawn from map and normalize rows.
- M4: run flood fill and error on open maps.
- M5: enable textures only after successful parsing + validation.
