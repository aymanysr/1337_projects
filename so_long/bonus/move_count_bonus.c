/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:23:17 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/20 18:23:20 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_move_count(t_game *game)
{
	char	*move_text;
	char	*moves_str;

	if (game->move_text_img && game->mlx.mlx_ptr)
	{
		mlx_delete_image(game->mlx.mlx_ptr, game->move_text_img);
		game->move_text_img = NULL;
	}
	moves_str = ft_itoa(game->move_count);
	if (!moves_str)
		return ;
	move_text = ft_strjoin("Moves: ", moves_str);
	free(moves_str);
	if (!move_text)
		return ;
	game->move_text_img = mlx_put_string(game->mlx.mlx_ptr, move_text, 10, 10);
	free(move_text);
}
