/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_control_helper_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:53:42 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/16 18:03:18 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_valid_enemy_move(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'E'
		|| game->map[y][x] == 'C')
		return (0);
	return (1);
}

void	reverse_enemy_direction(t_enemy *enemy)
{
	if (enemy->direction == 'l')
		enemy->direction = 'r';
	else
		enemy->direction = 'l';
	enemy->steps = 0;
}
