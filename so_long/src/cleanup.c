#include "../includes/so_long.h"

void cleanup_game(t_game *game)
{
	static int already_called = 0;
	
	if (!game || already_called)
		return;
		
	already_called = 1;
	free_textures(game);
	free_images(game);
	free_map_data(game);
	free_enemy_texture(game);
	if (game->enemies)
	{
		free(game->enemies);
		game->enemies = NULL;
	}
	terminate_mlx_instance(game);
	free(game);
}

void free_textures(t_game *game)
{
	if (game->textures.xpm_player_right[0])
	{
		mlx_delete_xpm42(game->textures.xpm_player_right[0]);
		game->textures.xpm_player_right[0] = NULL;
	}
	if (game->textures.xpm_player_right[1])
	{
		mlx_delete_xpm42(game->textures.xpm_player_right[1]);
		game->textures.xpm_player_right[1] = NULL;
	}
	if (game->textures.xpm_player_left[0])
	{
		mlx_delete_xpm42(game->textures.xpm_player_left[0]);
		game->textures.xpm_player_left[0] = NULL;
	}
	if (game->textures.xpm_player_left[1])
	{
		mlx_delete_xpm42(game->textures.xpm_player_left[1]);
		game->textures.xpm_player_left[1] = NULL;
	}
	if (game->textures.xpm_player_front[0])
	{
		mlx_delete_xpm42(game->textures.xpm_player_front[0]);
		game->textures.xpm_player_front[0] = NULL;
	}
	if (game->textures.xpm_player_front[1])
	{
		mlx_delete_xpm42(game->textures.xpm_player_front[1]);
		game->textures.xpm_player_front[1] = NULL;
	}
	if (game->textures.xpm_player_back[0])
	{
		mlx_delete_xpm42(game->textures.xpm_player_back[0]);
		game->textures.xpm_player_back[0] = NULL;
	}
	if (game->textures.xpm_player_back[1])
	{
		mlx_delete_xpm42(game->textures.xpm_player_back[1]);
		game->textures.xpm_player_back[1] = NULL;
	}
	if (game->textures.xpm_collectibles)
	{
		mlx_delete_xpm42(game->textures.xpm_collectibles);
		game->textures.xpm_collectibles = NULL;
	}
	if (game->textures.xpm_walls)
	{
		mlx_delete_xpm42(game->textures.xpm_walls);
		game->textures.xpm_walls = NULL;
	}
	if (game->textures.xpm_background)
	{
		mlx_delete_xpm42(game->textures.xpm_background);
		game->textures.xpm_background = NULL;
	}
	if (game->textures.xpm_exit)
	{
		mlx_delete_xpm42(game->textures.xpm_exit);
		game->textures.xpm_exit = NULL;
	}
}

void free_images(t_game *game)
{
	if (game->move_text_img && game->mlx.mlx_ptr)
	{
		mlx_delete_image(game->mlx.mlx_ptr, game->move_text_img);
		game->move_text_img = NULL;
	}
	if (game->buffer && game->mlx.mlx_ptr)
	{
		mlx_delete_image(game->mlx.mlx_ptr, game->buffer);
		game->buffer = NULL;
	}
}

void free_map_data(t_game *game)
{
	char **temp_map = game->map;
	char **temp_copied_map = game->copied_map;

	game->map = NULL;
	game->copied_map = NULL;
	if (temp_map)
		map_free(temp_map);
	if (temp_copied_map)
		map_free(temp_copied_map);
}

void terminate_mlx_instance(t_game *game)
{
	if (!game)
		return;
		
	void *temp_mlx = game->mlx.mlx_ptr;
	game->mlx.mlx_ptr = NULL;
	if (temp_mlx)
		mlx_terminate(temp_mlx);
}
