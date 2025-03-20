/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:54:17 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/20 17:54:18 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	renderer(t_game *game)
{
	int	x;
	int	y;

	ft_memset(game->buffer->pixels, 0xFF,
		game->buffer->width * game->buffer->height * BPP);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_cell(game, x, y);
			x++;
		}
		y++;
	}
	update_enemy_patrol(game);
}

void	game_renderer(t_game *game)
{
	renderer(game);
	display_move_count(game);
}

void	update_animation(void *param)
{
	static int	counter = 0;
	t_game		*game;

	game = (t_game *)param;
	counter++;
	if (counter >= 10)
	{
		game->animation_frame = !game->animation_frame;
		counter = 0;
	}
}
