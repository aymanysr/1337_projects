#include "so_long.h"

void	blit_image_no_skip(mlx_image_t *dest, mlx_image_t *src, int dx, int dy)
{
	int	x;
	int	y;
	int	d_index;
	int	s_index;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			s_index = (y * src->width + x) * BPP;
			d_index = ((dy + y) * dest->width + (dx + x)) * BPP;
			dest->pixels[d_index + 0] = src->pixels[s_index + 0];
			dest->pixels[d_index + 1] = src->pixels[s_index + 1];
			dest->pixels[d_index + 2] = src->pixels[s_index + 2];
			dest->pixels[d_index + 3] = src->pixels[s_index + 3];
			x++;
		}
		y++;
	}
}

/*
** is_grey:
**   Returns 1 if the given RGB pixel is nearly grey.
**   Tolerance is defined by tol (e.g., 10).
*/
int	is_grey(uint8_t r, uint8_t g, uint8_t b)
{
	const int	tol = 10;

	if (abs((int)r - (int)g) < tol && abs((int)r - (int)b) < tol
		&& abs((int)g - (int)b) < tol)
		return (1);
	return (0);
}

/*
** blit_image:
**   Copies a TILE_SIZE x TILE_SIZE block from the source image to the
**   destination image at position (dx, dy) in pixels.
**   It skips copying any pixel that is nearly grey.
*/
void	blit_image(mlx_image_t *dest, mlx_image_t *src, int dx, int dy)
{
	int	x;
	int	y;
	int	d_index;
	int	s_index;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			s_index = (y * src->width + x) * BPP;
			/* If the pixel is nearly grey, skip copying it */
			if (is_grey(src->pixels[s_index + 0],
					src->pixels[s_index + 1],
					src->pixels[s_index + 2]))
			{
				x++;
				continue ;
			}
			d_index = ((dy + y) * dest->width + (dx + x)) * BPP;
			dest->pixels[d_index + 0] = src->pixels[s_index + 0];
			dest->pixels[d_index + 1] = src->pixels[s_index + 1];
			dest->pixels[d_index + 2] = src->pixels[s_index + 2];
			dest->pixels[d_index + 3] = src->pixels[s_index + 3];
			x++;
		}
		y++;
	}
}




// Helper function to render one cell
void render_cell(t_game *game, int x, int y)
{
	int dx = x * TILE_SIZE;
	int dy = y * TILE_SIZE;

	// Always draw background first
	blit_image(game->buffer, game->textures.img_background, dx, dy);
	if (game->map[y][x] == '1')
		blit_image(game->buffer, game->textures.img_walls, dx, dy);
	else if (game->map[y][x] == 'E')
		blit_image(game->buffer, game->textures.img_exit, dx, dy);
	else if (game->map[y][x] == 'C')
		blit_image(game->buffer, game->textures.img_collectibles, dx, dy);
	else if (game->map[y][x] == 'P')
	{
		if (game->player.direction == 'r')
			blit_image(game->buffer, game->textures.player_right_img[game->animation_frame % 2], dx, dy);
		else if (game->player.direction == 'l')
			blit_image(game->buffer, game->textures.player_left_img[game->animation_frame % 2], dx, dy);
		else if (game->player.direction == 'u')
			blit_image(game->buffer, game->textures.player_back_img[game->animation_frame % 2], dx, dy);
		else
			blit_image(game->buffer, game->textures.player_front_img[game->animation_frame % 2], dx, dy);
	}
}

void put_image_on_window(t_game *game, mlx_texture_t *texture, int tile_x, int tile_y)
{
	mlx_image_t *img = mlx_texture_to_image(game->mlx.mlx_ptr, texture);
	if (mlx_image_to_window(game->mlx.mlx_ptr, img, tile_x * TILE_SIZE, tile_y * TILE_SIZE) < 0)
		return ;
}