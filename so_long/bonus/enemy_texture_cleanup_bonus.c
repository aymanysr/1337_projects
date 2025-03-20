/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_texture_cleanup_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:21:57 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/20 18:22:02 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_enemy_texture(t_game *game)
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
