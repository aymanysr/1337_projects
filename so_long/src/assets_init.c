#include "so_long.h"

void load_elements(t_game *game)
{
	load_basic_textures(game);
	convert_basic_textures_to_images(game);
	if (!game->textures.img_collectibles || !game->textures.img_walls ||
		!game->textures.img_background || !game->textures.img_exit)
	{
		ft_printf("Error: Failed to create one or more images from textures\n");
		cleanup_game(game);
		exit(EXIT_FAILURE);
	}
	// Keep underlying texture pointers for later use.
	game->textures.collectibles = &game->textures.xpm_collectibles->texture;
	game->textures.walls = &game->textures.xpm_walls->texture;
	game->textures.background = &game->textures.xpm_background->texture;
	game->textures.exit = &game->textures.xpm_exit->texture;
}


void load_player(t_game *game)
{
    load_all_player_assets(game);
	game->player.direction = 'd';
}

void	mlx_initializer(t_game *game)
{
    int rows = game->map_length;
    int cols = ft_strlen(game->map[0]);
    int width = cols * TILE_SIZE;
    int height = rows * TILE_SIZE;

	if (game->map_length > 15|| ft_strlen(game->map[0]) > 30)
    	ft_game_errors("Map dimensions exceed screen size", game);

	game->mlx.mlx_ptr = mlx_init(width, height, WINDOW_TITLE, true);
	if (!game->mlx.mlx_ptr)
		ft_game_errors("mlx_init failed", game);
    game->buffer = mlx_new_image(game->mlx.mlx_ptr, width, height);
    if (!game->buffer)
        ft_game_errors("mlx_new_image failed", game);
	/* Display the updated buffer on the window */
	if (mlx_image_to_window(game->mlx.mlx_ptr, game->buffer, 0, 0) < 0)
    	ft_game_errors("Failed to display image to window", game);
}


void    vars_initializer(t_game *game)
{
    game->player.x_pos = 0;
    game->player.y_pos = 0;
    game->player.direction = 'd';
    game->exit.x_pos = 0;
    game->exit.y_pos = 0;
    game->collectibles = 0;
    game->players = 0;
    game->exits = 0;
    game->move_count = 0;
    game->animation_frame = 0;
	game->buffer = NULL;
	game->map = NULL;
	// Make sure the MLX pointer is explicitly NULL
    game->mlx.mlx_ptr = NULL;
	// Initialize all texture pointers to NULL
    game->textures.xpm_collectibles = NULL;
    game->textures.xpm_walls = NULL;
    game->textures.xpm_background = NULL;
    game->textures.xpm_exit = NULL;
    
    game->textures.xpm_player_right[0] = NULL;
    game->textures.xpm_player_right[1] = NULL;
    game->textures.xpm_player_left[0] = NULL;
    game->textures.xpm_player_left[1] = NULL;
    game->textures.xpm_player_front[0] = NULL;
    game->textures.xpm_player_front[1] = NULL;
    game->textures.xpm_player_back[0] = NULL;
    game->textures.xpm_player_back[1] = NULL;
    
    game->textures.xpm_enemy_left = NULL;
    game->textures.xpm_enemy_right = NULL;
    
    // Image pointers should also be NULL
    game->textures.img_collectibles = NULL;
    game->textures.img_walls = NULL;
    game->textures.img_background = NULL;
    game->textures.img_exit = NULL;
    game->move_text_img = NULL;
    game->buffer = NULL;
}

void	initialize_game(t_game *game)
{
	load_elements(game);
	load_player(game);
	game_renderer(game);
}