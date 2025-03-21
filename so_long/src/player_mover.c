/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:55:20 by aimaneyousr       #+#    #+#             */
/*   Updated: 2025/03/21 01:55:21 by aimaneyousr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_collectible(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		game->collectibles--;
}

static void	handle_move_normal(t_game *game, int x, int y, char direction)
{
	check_collectible(game, x + (direction == 'r') - (direction == 'l'),
		y + (direction == 'd') - (direction == 'u'));
	update_player_position(game, x, y, direction);
	game->move_count++;
	ft_printf("Move count increased to: %d\n", game->move_count);
}

static void	handle_move_exit(t_game *game)
{
	if (game->collectibles == 0)
	{
		game->move_count++;
		game_renderer(game);
		img_destroyer(game, "[***] You won!", G);
	}
}

void	move_player(t_game *game, int dx, int dy, char direction)
{
	int	x;
	int	y;
	int	next_x;
	int	next_y;

	x = game->player.x_pos;
	y = game->player.y_pos;
	next_x = x + dx;
	next_y = y + dy;
	if (game->map[next_y][next_x] != '1')
	{
		if (game->map[next_y][next_x] == 'C'
			|| game->map[next_y][next_x] == '0')
			handle_move_normal(game, x, y, direction);
		else if (game->map[next_y][next_x] == 'E')
			handle_move_exit(game);
	}
	else
		game->player.direction = direction;
}
