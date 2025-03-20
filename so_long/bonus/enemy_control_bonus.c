/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_control_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:20:03 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/20 18:20:15 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Helper: update a single enemy's position and step count.
   The enemy moves one cell horizontally if its step count is less than 2.
   Otherwise, it resets the step count and reverses direction. */
static void	update_single_enemy(t_enemy *enemy, t_game *game)
{
	int	next_x;

	if (enemy->steps >= 2)
	{
		reverse_enemy_direction(enemy);
		return ;
	}
	if (enemy->direction == 'l')
		next_x = enemy->x_pos - 1;
	else
		next_x = enemy->x_pos + 1;
	if (is_valid_enemy_move(game, enemy->y_pos, next_x))
	{
		enemy->x_pos = next_x;
		enemy->steps++;
	}
	else
		reverse_enemy_direction(enemy);
}

/* Updates all enemy positions with a delay so that they move slowly */
static void	update_enemy_positions(t_game *game)
{
	static int	delay;
	int			i;

	if (++delay < 20)
		return ;
	delay = 0;
	i = 0;
	while (i < game->enemy_count)
	{
		update_single_enemy(&game->enemies[i], game);
		i++;
	}
}

/* Checks collision with the player */
static void	check_enemy_collision(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		if (game->player.x_pos == game->enemies[i].x_pos
			&&game->player.y_pos == game->enemies[i].y_pos)
			img_destroyer(game, "[!!!] Game Over: Caught by an enemy!", R);
		i++;
	}
}

/* Renders enemy images using left/right textures based on direction */
static void	render_enemies(t_game *game)
{
	int			i;
	int			dx;
	int			dy;
	mlx_image_t	*enemy_img;

	i = 0;
	while (i < game->enemy_count)
	{
		dx = game->enemies[i].x_pos * TILE_SIZE;
		dy = game->enemies[i].y_pos * TILE_SIZE;
		if (game->enemies[i].direction == 'l')
			enemy_img = game->textures.img_enemy_left;
		else
			enemy_img = game->textures.img_enemy_right;
		blit_image_no_skip(game->buffer, enemy_img, dx, dy);
		i++;
	}
}

/* Public function: updates enemy patrols */
void	update_enemy_patrol(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	update_enemy_positions(game);
	check_enemy_collision(game);
	render_enemies(game);
}
