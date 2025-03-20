/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:21:20 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/20 18:21:48 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	vars_initializer_bonus(t_game *game)
{
	game->textures.xpm_enemy_left = NULL;
	game->textures.xpm_enemy_right = NULL;
	game->move_text_img = NULL;
	game->copied_map = NULL;
	game->enemies = NULL;
}

/* Counts the number of enemy markers ('M') in the map */
static int	count_enemies(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'M')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

/* Fills the enemies array with their positions and sets default values.
   Each enemy is set with default direction 'l' and its image pointer to the */
/* enemy left image. */
static void	fill_enemies(t_game *game)
{
	int	i;
	int	j;
	int	index;

	index = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'M')
			{
				game->enemies[index].x_pos = j;
				game->enemies[index].y_pos = i;
				game->enemies[index].direction = 'l';
				game->enemies[index].steps = 0;
				game->enemies[index].img = game->textures.img_enemy_left;
				game->map[i][j] = '0';
				index++;
			}
			j++;
		}
		i++;
	}
}

void	init_enemies(t_game *game)
{
	int	count;

	count = count_enemies(game->map);
	game->enemy_count = count;
	if (count == 0)
		return ;
	game->enemies = malloc(sizeof(t_enemy) * count);
	if (!game->enemies)
		ft_game_errors("Memory allocation error for enemies", game);
	fill_enemies(game);
}
