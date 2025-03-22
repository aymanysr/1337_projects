/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:12:48 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/22 00:07:51 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include "MLX42/MLX42.h"

/*
** Enemy Patrol Structure
** Represents an enemy that moves horizontally.
*/

typedef struct s_offset
{
	int	x;
	int	y;
}				t_offset;

typedef struct s_enemy
{
	int				x_pos;
	int				y_pos;
	char			direction;
	mlx_image_t		*img;
	int				steps;
}					t_enemy;

typedef struct s_textures
{
	mlx_texture_t	*collectibles;
	xpm_t			*xpm_collectibles;
	mlx_image_t		*img_collectibles;

	mlx_texture_t	*walls;
	xpm_t			*xpm_walls;
	mlx_image_t		*img_walls;

	mlx_texture_t	*background;
	xpm_t			*xpm_background;
	mlx_image_t		*img_background;

	mlx_texture_t	*player_front[2];
	xpm_t			*xpm_player_front[2];
	mlx_image_t		*player_front_img[2];

	mlx_texture_t	*player_back[2];
	xpm_t			*xpm_player_back[2];
	mlx_image_t		*player_back_img[2];

	mlx_texture_t	*exit;
	xpm_t			*xpm_exit;
	mlx_image_t		*img_exit;

	mlx_texture_t	*player_right[2];
	xpm_t			*xpm_player_right[2];
	mlx_image_t		*player_right_img[2];

	mlx_texture_t	*player_left[2];
	xpm_t			*xpm_player_left[2];
	mlx_image_t		*player_left_img[2];

	mlx_texture_t	*enemy_left;
	xpm_t			*xpm_enemy_left;
	mlx_image_t		*img_enemy_left;

	mlx_texture_t	*enemy_right;
	xpm_t			*xpm_enemy_right;
	mlx_image_t		*img_enemy_right;
}				t_textures;

/*
 * Player Asset Descriptor
 * Groups parameters needed for loading one orientation.
 */
typedef struct s_player_asset
{
	xpm_t			**xpm;
	mlx_image_t		**img;
	mlx_texture_t	**texture;
	char			*normal_path;
	char			*bw_path;
	char			*error_normal;
	char			*error_bw;
}				t_player_asset;

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct s_image
{
	void	*img_ptr;
	int		width;
	int		height;
}				t_image;

/*
** Player Structure
** Tracks player position and direction
*/
typedef struct s_player
{
	int		y_pos;
	int		x_pos;
	char	direction;
}				t_player;

typedef struct s_exit
{
	int	y_pos;
	int	x_pos;
}				t_exit;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

typedef struct s_game
{
	char		*map_path;
	int			collectibles;
	int			players;
	int			exits;
	int			map_length;
	int			file_descriptor;
	char		**map;
	char		**copied_map;
	int			move_count;
	int			animation_frame;
	mlx_image_t	*move_text_img;
	mlx_image_t	*buffer;
	t_textures	textures;
	t_image		image;
	t_player	player;
	t_exit		exit;
	t_mlx		mlx;
	t_enemy		*enemies;
	int			enemy_count;
}				t_game;
#endif /* STRUCTS_H */