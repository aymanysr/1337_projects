# Cub3D Structure Guide

This guide captures the current repo structure and the target final structure for a full 42-compliant Cub3D (with parsing, validation, and textured rendering).

## 1. Final Data Structures (`includes/game.h`)

To support parsing and texturing, your core data structures should be expanded as follows.

```c
// In includes/game.h

// Holds the parsed information from the .cub file before textures are loaded.
typedef struct s_scene
{
	char	*no_texture_path;
	char	*so_texture_path;
	char	*we_texture_path;
	char	*ea_texture_path;
	int	floor_color;
	int	ceiling_color;
	// Counter to ensure all 6 elements are found and are not duplicated.
	int	elements_found;
} 	t_scene;

// Holds the MLX texture pointers after they are loaded from the paths.
typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
} 	t_textures;

// The main game struct, expanded to hold all project data.
typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		**map;
	t_player	*player;
	t_scene		*scene;
	t_textures	*textures;
} 	t_game;
```

## 2. File Structure

Current modules, then target additions for parsing/validation.

```
```
/src/
├── core/
│  ├── main.c          # init_game, loop hooks
│  ├── default_scene.c # dev fallback scene/colors
│  ├── cleanup.c       # cleanup_* and cleanup()
│  ├── utils.c         # ft_arrlen, free_string_array
│  └── error_exit.c    # error_exit()
│
├── rendering/
│  ├── renderer.c      # cast_rays, render_frame, load_textures
│  ├── drawing_utils.c # floor/ceiling fill, rgb_to_int
│  ├── raycast.c       # is_wall, cast_ray
│  └── wall_slice.c    # draw_textured_wall_slice
│
└── player/
   ├── player.c        # init_player
   ├── movement.c      # move_player wrapper
   ├── move_logic.c    # rotation/strafe/forward logic
   └── controls.c      # key handling

# Target additions to restore subject flow
/src/
├── parsing/
│  ├── parser.c        # parse_and_validate, read_file_lines, parse_map
│  └── parser_utils.c  # parse_single_element, parse_texture, parse_color
└── validation/
   └── validator.c     # validate_arguments/scene/map, flood_fill
```
```

## 3. Key Function Prototypes

Current functions plus target ones to add back for parsing/validation.

### `src/core/main.c`
```c
// Initializes the t_game struct, MLX, and all sub-modules.
void	init_game(t_game *game, int argc, char **argv);
// The main game loop hook for MLX.
void	game_loop(void *param);
```

### `src/core/cleanup.c`
```c
// Central function to free all allocated memory before exiting.
void	cleanup(t_game *game);
// Helper to free a null-terminated string array.
void	free_string_array(char **arr);
// Centralized error handling function.
void	error_exit(char *message, t_game *game);
```

### `src/parsing/parser.c` (to add back)
```c
// Main function that orchestrates the entire parsing and validation process.
void	parse_and_validate(t_game *game, const char *file_path);
// Reads the file into a t_list.
t_list	*read_file_lines(int fd);
// Parses the scene elements (textures, colors) from the linked list.
void	parse_scene_elements(t_list **lines_ptr, t_game *game);
// Parses the map grid from the remaining lines.
void	parse_map(t_list *lines, t_game *game);
```

### `src/parsing/parser_utils.c` (to add back)
```c
// Dispatcher that identifies and parses a single element line.
int		parse_single_element(char *line, t_game *game);
// Parses a texture identifier and path.
int		parse_texture(char **parts, char **dest, t_game *game);
// Parses a color identifier and RGB value.
int		parse_color(char **parts, int *dest, t_game *game);
// (Optional) Helper to check if a line is empty or only whitespace.
bool	is_line_empty(char *line);
```

### `src/validation/validator.c` (to add back)
```c
// Validates the command-line arguments.
void	validate_arguments(int argc, char **argv);
// Checks if all scene elements are valid (e.g., texture files exist).
void	validate_scene(t_game *game);
// Checks if the map is valid (characters, player count, enclosed by walls).
void	validate_map(t_game *game);
// Flood-fill algorithm to check if the map is enclosed.
void	flood_fill(char **map_copy, int x, int y, int map_height);
```

### `src/rendering/renderer.c`
```c
// Main rendering function called every frame.
void	render_frame(t_game *game);
// Casts all rays and calls the wall drawing function for each screen column.
void	cast_rays(t_game *game);
// Draws a single textured (or flat-shaded) vertical wall slice.
void	draw_textured_wall_slice(t_game *game, t_ray *ray, int screen_x);
// Loads all textures from paths into mlx_texture_t objects.
void	load_textures(t_game *game);
```

### `src/rendering/drawing_utils.c`
```c
// Draws the floor and ceiling on the main image.
void	draw_floor_and_ceiling(t_game *game);
// Converts RGB components to a single integer color.
int		rgb_to_int(int r, int g, int b, int a);
// Raycast helpers (in raycast.c)
t_ray	cast_ray(t_player *player, t_game *game, float angle);
bool	is_wall(t_game *game, float x, float y);
```

### `src/player/player.c` & `src/player/movement.c`
```c
// (Existing functions for player initialization, movement, and input handling)
```

## 4. Makefile Notes

Current sources and where parsing/validation will be re-added.

```makefile
SRC = src/core/main.c \
      src/core/cleanup.c \
      src/core/default_scene.c \
      src/core/utils.c \
      src/core/error_exit.c \
      src/rendering/renderer.c \
      src/rendering/drawing_utils.c \
      src/rendering/raycast.c \
      src/rendering/wall_slice.c \
      src/player/player.c \
      src/player/movement.c \
      src/player/move_logic.c \
      src/player/controls.c

# To be re-added when parser returns:
#   src/parsing/parser.c src/parsing/parser_utils.c src/validation/validator.c
```
