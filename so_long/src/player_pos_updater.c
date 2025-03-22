/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos_updater.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:16:53 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/22 00:10:28 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_coordinates(t_game *game, char c)
{
	if (c == 'r')
	{
		game->player.x_pos++;
		game->player.direction = 'r';
	}
	else if (c == 'l')
	{
		game->player.x_pos--;
		game->player.direction = 'l';
	}
	else if (c == 'u')
	{
		game->player.y_pos--;
		game->player.direction = 'u';
	}
	else if (c == 'd')
	{
		game->player.y_pos++;
		game->player.direction = 'd';
	}
}

void	update_player_position(t_game *game, int x, int y, char direction)
{
	int	new_x;
	int	new_y;

	new_x = x;
	new_y = y;
	if (direction == 'r')
		new_x++;
	else if (direction == 'l')
		new_x--;
	else if (direction == 'u')
		new_y--;
	else if (direction == 'd')
		new_y++;
	game->map[y][x] = '0';
	game->map[new_y][new_x] = 'P';
	player_coordinates(game, direction);
}
