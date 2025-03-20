/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_ctrl_helper_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:20:29 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/20 18:21:14 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Helper: checks if the next position is valid for enemy movement */
int	is_valid_enemy_move(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1'
		|| game->map[y][x] == 'E'
		|| game->map[y][x] == 'C')
		return (0);
	return (1);
}

/* Helper: reverses enemy direction */
void	reverse_enemy_direction(t_enemy *enemy)
{
	if (enemy->direction == 'l')
		enemy->direction = 'r';
	else
		enemy->direction = 'l';
	enemy->steps = 0;
}
