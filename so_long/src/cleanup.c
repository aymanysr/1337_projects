/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:55:08 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/20 20:39:58 by aimaneyousr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	cleanup_game(t_game *game)
{
	static int	already_called = 0;

	if (!game || already_called)
		return ;
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

void	free_textures(t_game *game)
{
	free_player_horizontal_textures(game);
	free_player_vertical_textures(game);
	free_environment_textures(game);
}

void	free_images(t_game *game)
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

void	free_map_data(t_game *game)
{
	char	**temp_map;
	char	**temp_copied_map;

	temp_map = game->map;
	temp_copied_map = game->copied_map;
	game->map = NULL;
	game->copied_map = NULL;
	if (temp_map)
		map_free(temp_map);
	if (temp_copied_map)
		map_free(temp_copied_map);
}

void	terminate_mlx_instance(t_game *game)
{
	void	*temp_mlx;

	if (!game)
		return ;
	temp_mlx = game->mlx.mlx_ptr;
	game->mlx.mlx_ptr = NULL;
	if (temp_mlx)
		mlx_terminate(temp_mlx);
}
