/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:56:32 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/20 17:56:33 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Initialize basic player and game state */
static void	init_game_state(t_game *game)
{
	game->player.x_pos = 0;
	game->player.y_pos = 0;
	game->player.direction = 'd';
	game->exit.x_pos = 0;
	game->exit.y_pos = 0;
	game->collectibles = 0;
	game->players = 0;
	game->exits = 0;
	game->move_count = 0;
	game->animation_frame = 0;
	game->buffer = NULL;
	game->map = NULL;
	game->mlx.mlx_ptr = NULL;
}

/* Initialize texture XPM pointers */
static void	init_textures_xpm(t_game *game)
{
	game->textures.xpm_collectibles = NULL;
	game->textures.xpm_walls = NULL;
	game->textures.xpm_background = NULL;
	game->textures.xpm_exit = NULL;
	game->textures.xpm_player_right[0] = NULL;
	game->textures.xpm_player_right[1] = NULL;
	game->textures.xpm_player_left[0] = NULL;
	game->textures.xpm_player_left[1] = NULL;
	game->textures.xpm_player_front[0] = NULL;
	game->textures.xpm_player_front[1] = NULL;
	game->textures.xpm_player_back[0] = NULL;
	game->textures.xpm_player_back[1] = NULL;
}

/* Initialize image pointers */
static void	init_images(t_game *game)
{
	game->textures.img_collectibles = NULL;
	game->textures.img_walls = NULL;
	game->textures.img_background = NULL;
	game->textures.img_exit = NULL;
	game->move_text_img = NULL;
	game->buffer = NULL;
}

void	vars_initializer(t_game *game)
{
	init_game_state(game);
	init_textures_xpm(game);
	init_images(game);
}
