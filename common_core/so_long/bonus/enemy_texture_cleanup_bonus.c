#include "so_long.h"

void    free_enemy_texture(t_game *game)
{
	if (game->textures.xpm_enemy_left)
	{
		mlx_delete_xpm42(game->textures.xpm_enemy_left);
		game->textures.xpm_enemy_left = NULL;
	}
	if (game->textures.xpm_enemy_right)
	{
		mlx_delete_xpm42(game->textures.xpm_enemy_right);
		game->textures.xpm_enemy_right = NULL;
	}
}
