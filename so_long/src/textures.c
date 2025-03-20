#include "../includes/so_long.h"

void	load_basic_textures(t_game *game)
{
	game->textures.xpm_collectibles = mlx_load_xpm42("./textures/collectible1.xpm42");
	if (game->textures.xpm_collectibles)
		game->textures.collectibles = &game->textures.xpm_collectibles->texture;
	game->textures.xpm_walls = mlx_load_xpm42("./textures/wall.xpm42");
	if (game->textures.xpm_walls)
		game->textures.walls = &game->textures.xpm_walls->texture;
	game->textures.xpm_background = mlx_load_xpm42("./textures/background.xpm42");
	if (game->textures.xpm_background)
		game->textures.background = &game->textures.xpm_background->texture;
	game->textures.xpm_exit = mlx_load_xpm42("./textures/exit.xpm42");
	if (game->textures.xpm_exit)
		game->textures.exit = &game->textures.xpm_exit->texture;
}

// Convert the loaded textures into images.
void	convert_basic_textures_to_images(t_game *game)
{
	game->textures.img_collectibles = mlx_texture_to_image(
			game->mlx.mlx_ptr, &game->textures.xpm_collectibles->texture);
	if (!game->textures.img_collectibles)
		ft_game_errors("failed to create collectible image", game);
	game->textures.img_walls = mlx_texture_to_image(
			game->mlx.mlx_ptr, &game->textures.xpm_walls->texture);
	if (!game->textures.img_walls)
		ft_game_errors("failed to create wall image", game);
	game->textures.img_background = mlx_texture_to_image(
			game->mlx.mlx_ptr, &game->textures.xpm_background->texture);
	if (!game->textures.img_background)
		ft_game_errors("failed to create background image", game);
	game->textures.img_exit = mlx_texture_to_image(
			game->mlx.mlx_ptr, &game->textures.xpm_exit->texture);
	if (!game->textures.img_exit)
		ft_game_errors("failed to create exit image", game);
}
