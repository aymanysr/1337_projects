/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:54:39 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/22 00:09:04 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		++i ;
	game->map_length = i;
}

void	counter(t_game *game, char c, int i, int j)
{
	if (c == 'P')
	{
		game->player.y_pos = i;
		game->player.x_pos = j;
		game->players += 1;
	}
	else if (c == 'E')
	{
		game->exit.y_pos = i;
		game->exit.x_pos = j;
		game->exits += 1;
	}
	else if (c == 'C')
		game->collectibles += 1;
}

void	cp_map(t_game *game)
{
	int		i;

	game->copied_map = malloc(sizeof(char *) * (game->map_length + 1));
	if (!game->copied_map)
		return ;
	i = 0;
	while (i < game->map_length)
	{
		game->copied_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->copied_map[i] = NULL;
}

bool	is_valid_move(t_game *game, int y, int x)
{
	return (x >= 0 && x < ft_sl_strlen(game->copied_map[y])
		&& y >= 0 && y < game->map_length
		&& game->copied_map[y][x] != '1'
		&& game->copied_map[y][x] != 'M');
}

void	fill_map(t_game *game, int y, int x)
{
	if (is_valid_move(game, y, x + 1))
	{
		game->copied_map[y][x + 1] = '1';
		fill_map(game, y, x + 1);
	}
	if (is_valid_move(game, y, x - 1))
	{
		game->copied_map[y][x - 1] = '1';
		fill_map(game, y, x - 1);
	}
	if (is_valid_move(game, y + 1, x))
	{
		game->copied_map[y + 1][x] = '1';
		fill_map(game, y + 1, x);
	}
	if (is_valid_move(game, y - 1, x))
	{
		game->copied_map[y - 1][x] = '1';
		fill_map(game, y - 1, x);
	}
}
