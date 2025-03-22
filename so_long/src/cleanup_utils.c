/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:33:45 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/22 00:08:38 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_free(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/* Helper to free player right/left animations */
void	free_player_horizontal_textures(t_game *game)
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
}

/* Helper to free player front/back animations */
void	free_player_vertical_textures(t_game *game)
{
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
}

/* Helper to free environment textures */
void	free_environment_textures(t_game *game)
{
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
