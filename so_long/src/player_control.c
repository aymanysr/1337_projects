/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:54:28 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/21 01:53:59 by aimaneyousr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hooks(int keycode, t_game *game)
{
	if (keycode == MLX_KEY_RIGHT || keycode == MLX_KEY_D)
		move_player(game, 1, 0, 'r');
	else if (keycode == MLX_KEY_LEFT || keycode == MLX_KEY_A)
		move_player(game, -1, 0, 'l');
	else if (keycode == MLX_KEY_UP || keycode == MLX_KEY_W)
		move_player(game, 0, -1, 'u');
	else if (keycode == MLX_KEY_DOWN || keycode == MLX_KEY_S)
		move_player(game, 0, 1, 'd');
	else if (keycode == MLX_KEY_ESCAPE)
		img_destroyer(game, "[.] You have pressed ESC", R);
	game_renderer(game);
	return (1);
}

void	player_controller(mlx_key_data_t key_data, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key_data.action != MLX_PRESS)
		return ;
	if (key_data.key == MLX_KEY_ESCAPE)
		img_destroyer(game, "[.] You have pressed ESC", R);
	else
		key_hooks(key_data.key, game);
}
