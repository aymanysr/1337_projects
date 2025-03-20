/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:56:37 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/20 17:57:27 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_elements(t_game *game)
{
	load_basic_textures(game);
	convert_basic_textures_to_images(game);
	if (!game->textures.img_collectibles || !game->textures.img_walls
		|| !game->textures.img_background || !game->textures.img_exit)
	{
		ft_printf("Error: Failed to create one or more images from textures\n");
		cleanup_game(game);
		exit(EXIT_FAILURE);
	}
	game->textures.collectibles = &game->textures.xpm_collectibles->texture;
	game->textures.walls = &game->textures.xpm_walls->texture;
	game->textures.background = &game->textures.xpm_background->texture;
	game->textures.exit = &game->textures.xpm_exit->texture;
}

void	load_player(t_game *game)
{
	load_all_player_assets(game);
	game->player.direction = 'd';
}

void	mlx_initializer(t_game *game)
{
	int	rows;
	int	cols;
	int	width;
	int	height;

	rows = game->map_length;
	cols = ft_strlen(game->map[0]);
	width = cols * TILE_SIZE;
	height = rows * TILE_SIZE;
	if (game->map_length > 15 || ft_strlen(game->map[0]) > 30)
		ft_game_errors("Map dimensions exceed screen size", game);
	game->mlx.mlx_ptr = mlx_init(width, height, WINDOW_TITLE, true);
	if (!game->mlx.mlx_ptr)
		ft_game_errors("mlx_init failed", game);
	game->buffer = mlx_new_image(game->mlx.mlx_ptr, width, height);
	if (!game->buffer)
		ft_game_errors("mlx_new_image failed", game);
	if (mlx_image_to_window(game->mlx.mlx_ptr, game->buffer, 0, 0) < 0)
		ft_game_errors("Failed to display image to window", game);
}

void	initialize_game(t_game *game)
{
	load_elements(game);
	load_player(game);
	game_renderer(game);
}
