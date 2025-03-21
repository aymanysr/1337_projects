/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:12:48 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/21 02:16:25 by aimaneyousr      ###   ########.fr       */
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
	char			direction;/* 'l' for left, 'r' for right */
	mlx_image_t		*img;
	int				steps;/* Counts how many cells moved in current direction */
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
	xpm_t			**xpm;// Array of two xpm pointers (normal and bw).
	mlx_image_t		**img;// Array of two images.
	mlx_texture_t	**texture;// Array of two texture pointers.
	char			*normal_path;// File path for normal asset.
	char			*bw_path;// File path for bw asset.
	char			*error_normal;// Error message for normal asset.
	char			*error_bw;// Error message for bw asset.
}				t_player_asset;

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct s_image
{
	void	*img_ptr;// MLX image pointer
	int		width;// Image width
	int		height;// Image height
}				t_image;

/*
** Player Structure
** Tracks player position and direction
*/
typedef struct s_player
{
	int		y_pos;// Player Y position
	int		x_pos;// Player X position
	char	direction;// Current facing direction
}				t_player;

typedef struct s_exit
{
	int	y_pos;// Exit Y position
	int	x_pos;// Exit X position
}				t_exit;

typedef struct s_mlx
{
	void	*mlx_ptr;// MLX instance pointer
	void	*win_ptr;// Window pointer
}				t_mlx;

typedef struct s_game
{
	char		*map_path;// Path to map file
	int			collectibles;// Number of collectibles
	int			players;// Number of players (should be 1)
	int			exits;// Number of exits (should be 1)
	int			map_length;// Map length
	int			file_descriptor;// Map file descriptor
	char		**map;// Current game map
	char		**copied_map;// Copy for pathfinding
	int			move_count;// Number of moves made
	int			animation_frame;// This will be used to cycle through frames
	mlx_image_t	*move_text_img;
	mlx_image_t	*buffer;
	t_textures	textures;// Game textures
	t_image		image;// Current image
	t_player	player;// Player info
	t_exit		exit;// Exit info
	t_mlx		mlx;/* MLX instance */
	t_enemy		*enemies;		/* Dynamic array of enemy patrols */
	int			enemy_count;
}				t_game;
#endif /* STRUCTS_H */