/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:54:31 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/20 17:54:32 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** load_player_asset:
**   Loads one asset given a t_player_asset descriptor.
**   Exits on error.
*/
static void	load_player_asset(t_game *game, t_player_asset asset)
{
	asset.xpm[0] = mlx_load_xpm42(asset.normal_path);
	if (!asset.xpm[0] || asset.xpm[0]->texture.width == 0)
		ft_game_errors(asset.error_normal, game);
	asset.xpm[1] = mlx_load_xpm42(asset.bw_path);
	if (!asset.xpm[1] || asset.xpm[1]->texture.width == 0)
		ft_game_errors(asset.error_bw, game);
	asset.img[0] = mlx_texture_to_image(game->mlx.mlx_ptr,
			&asset.xpm[0]->texture);
	asset.img[1] = mlx_texture_to_image(game->mlx.mlx_ptr,
			&asset.xpm[1]->texture);
	asset.texture[0] = &asset.xpm[0]->texture;
	asset.texture[1] = &asset.xpm[1]->texture;
}

/*
** load_player_assets_horizontal:
**   Loads the right and left oriented player assets.
*/
static void	load_player_assets_horizontal(t_game *game)
{
	t_player_asset	asset;

	asset.xpm = game->textures.xpm_player_right;
	asset.img = game->textures.player_right_img;
	asset.texture = game->textures.player_right;
	asset.normal_path = "./textures/player_right.xpm42";
	asset.bw_path = "./textures/player_right_bw.xpm42";
	asset.error_normal = "Error: Failed to load player_right.xpm42";
	asset.error_bw = "Error: Failed to load player_right_bw.xpm42";
	load_player_asset(game, asset);
	asset.xpm = game->textures.xpm_player_left;
	asset.img = game->textures.player_left_img;
	asset.texture = game->textures.player_left;
	asset.normal_path = "./textures/player_left.xpm42";
	asset.bw_path = "./textures/player_left_bw.xpm42";
	asset.error_normal = "Error: Failed to load player_left.xpm42";
	asset.error_bw = "Error: Failed to load player_left_bw.xpm42";
	load_player_asset(game, asset);
}

/*
** load_player_assets_vertical:
**   Loads the front and back oriented player assets.
*/
static void	load_player_assets_vertical(t_game *game)
{
	t_player_asset	asset;

	asset.xpm = game->textures.xpm_player_front;
	asset.img = game->textures.player_front_img;
	asset.texture = game->textures.player_front;
	asset.normal_path = "./textures/player_down.xpm42";
	asset.bw_path = "./textures/player_down_bw.xpm42";
	asset.error_normal = "Error: Failed to load player_down.xpm42";
	asset.error_bw = "Error: Failed to load player_down_bw.xpm42";
	load_player_asset(game, asset);
	asset.xpm = game->textures.xpm_player_back;
	asset.img = game->textures.player_back_img;
	asset.texture = game->textures.player_back;
	asset.normal_path = "./textures/player_up.xpm42";
	asset.bw_path = "./textures/player_up_bw.xpm42";
	asset.error_normal = "Error: Failed to load player_up.xpm42";
	asset.error_bw = "Error: Failed to load player_up_bw.xpm42";
	load_player_asset(game, asset);
}

/*
** load_all_player_assets:
**   Calls the two groups to load all four player asset orientations.
*/
void	load_all_player_assets(t_game *game)
{
	load_player_assets_horizontal(game);
	load_player_assets_vertical(game);
}
