/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:54:14 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/21 01:37:28 by aimaneyousr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	blit_image(mlx_image_t *dest, mlx_image_t *src, int dx, int dy)
{
	int			y;
	t_offset	offset;

	offset.x = dx;
	offset.y = dy;
	y = 0;
	while (y < TILE_SIZE)
	{
		process_row(dest, src, offset, y);
		y++;
	}
}

/* Helper function to render one cell */
void	render_player(t_game *game, int dx, int dy)
{
	if (game->player.direction == 'r')
		blit_image(game->buffer,
			game->textures.player_right_img[game->animation_frame % 2],
			dx, dy);
	else if (game->player.direction == 'l')
		blit_image(game->buffer,
			game->textures.player_left_img[game->animation_frame % 2],
			dx, dy);
	else if (game->player.direction == 'u')
		blit_image(game->buffer,
			game->textures.player_back_img[game->animation_frame % 2],
			dx, dy);
	else
		blit_image(game->buffer,
			game->textures.player_front_img[game->animation_frame % 2],
			dx, dy);
}

void	render_cell(t_game *game, int x, int y)
{
	int	dx;
	int	dy;

	dx = x * TILE_SIZE;
	dy = y * TILE_SIZE;
	blit_image(game->buffer, game->textures.img_background, dx, dy);
	if (game->map[y][x] == '1')
		blit_image(game->buffer, game->textures.img_walls, dx, dy);
	else if (game->map[y][x] == 'E')
		blit_image(game->buffer, game->textures.img_exit, dx, dy);
	else if (game->map[y][x] == 'C')
		blit_image(game->buffer, game->textures.img_collectibles, dx, dy);
	else if (game->map[y][x] == 'P')
		render_player(game, dx, dy);
}

void	put_image_on_window(t_game *game, mlx_texture_t *texture,
	int tile_x, int tile_y)
{
	mlx_image_t	*img;

	img = mlx_texture_to_image(game->mlx.mlx_ptr, texture);
	if (mlx_image_to_window(game->mlx.mlx_ptr, img,
			tile_x * TILE_SIZE, tile_y * TILE_SIZE) < 0)
		return ;
}
