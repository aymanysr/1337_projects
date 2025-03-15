#include "../includes/so_long.h"

/* Helper: update a single enemy's position and step count.
   The enemy moves one cell horizontally if its step count is less than 2.
   Otherwise, it resets the step count and reverses direction. */
static void	update_single_enemy(t_enemy *enemy, t_game *game)
{
	int	next_x;

	if (enemy->steps < 2)
	{
		if (enemy->direction == 'l')
			next_x = enemy->x_pos - 1;
		else
			next_x = enemy->x_pos + 1;
		if (game->map[enemy->y_pos][next_x] != '1' &&
			game->map[enemy->y_pos][next_x] != 'E' &&
			game->map[enemy->y_pos][next_x] != 'C')
		{
			enemy->x_pos = next_x;
			enemy->steps++;
		}
		else
		{
			enemy->steps = 0;
			enemy->direction = (enemy->direction == 'l') ? 'r' : 'l';
		}
	}
	else
	{
		enemy->steps = 0;
		enemy->direction = (enemy->direction == 'l') ? 'r' : 'l';
	}
}

/* Updates all enemy positions with a delay so that they move slowly */
static void	update_enemy_positions(t_game *game)
{
	static int	delay = 0;
	int			i;

	if (++delay < 20)  /* Only update every 20 frames (adjust threshold as needed) */
		return;
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
	int	i = 0;
	while (i < game->enemy_count)
	{
		if (game->player.x_pos == game->enemies[i].x_pos &&
			game->player.y_pos == game->enemies[i].y_pos)
			img_destroyer(game, "[!!!] Game Over: Caught by an enemy!", R);
		i++;
	}
}

/* Renders enemy images using left/right textures based on direction */
static void	render_enemies(t_game *game)
{
	int i;
	int dx;
	int dy;
	mlx_image_t *enemy_img;

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
	t_game	*game = (t_game *)param;
	update_enemy_positions(game);
	check_enemy_collision(game);
	render_enemies(game);
}
