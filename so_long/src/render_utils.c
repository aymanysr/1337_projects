/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:20:07 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/22 00:10:44 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process_row(mlx_image_t *dest, mlx_image_t *src, t_offset offset, int y)
{
	int	x;
	int	s_index;
	int	d_index;

	x = 0;
	while (x < TILE_SIZE)
	{
		s_index = (y * src->width + x) * BPP;
		if (!is_grey(src->pixels[s_index + 0],
				src->pixels[s_index + 1],
				src->pixels[s_index + 2]))
		{
			d_index = ((offset.y + y) * dest->width + (offset.x + x)) * BPP;
			dest->pixels[d_index + 0] = src->pixels[s_index + 0];
			dest->pixels[d_index + 1] = src->pixels[s_index + 1];
			dest->pixels[d_index + 2] = src->pixels[s_index + 2];
			dest->pixels[d_index + 3] = src->pixels[s_index + 3];
		}
		x++;
	}
}

int	is_grey(uint8_t r, uint8_t g, uint8_t b)
{
	const int	tol = 10;

	if (abs((int)r - (int)g) < tol && abs((int)r - (int)b) < tol
		&& abs((int)g - (int)b) < tol)
		return (1);
	return (0);
}
