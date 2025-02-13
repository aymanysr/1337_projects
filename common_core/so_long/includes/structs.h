/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:12:48 by ayousr            #+#    #+#             */
/*   Updated: 2025/02/12 20:30:13 by aimaneyousr      ###   ########.fr       */
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

/*
 * Represents a sprite (image) used for objects like the player or collectibles.
 */
typedef struct s_sprite
{
	int		width;
	int		height;
	void	*img;
}				t_sprite;

/**
 * Holds the file paths for various game textures.
*/
typedef struct s_textures
{
	void	*collectibles;
	void	*walls;
	void    *player_front;  // Player facing front
    void    *player_back;   // Player facing back
    void    *player_left;   // Player facing left
    void    *player_right;  // Player facing right
    void    *exit;          // Exit texture
    void    *background;    // Background texture
}				t_textures;

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;


typedef struct s_image
{
    void    *img_ptr;      // MLX image pointer
    int     width;         // Image width
    int     height;        // Image height
}				t_image;

/*
** Player Structure
** Tracks player position and direction
*/
typedef struct s_player
{
    int     y_pos;         // Player Y position
    int     x_pos;         // Player X position
    char    direction;     // Current facing direction
}   t_player;

typedef struct s_exit
{
    int y_pos;            // Exit Y position
    int x_pos;            // Exit X position
}				t_exit;

typedef struct s_mlx
{
    void    *mlx_ptr;     // MLX instance pointer
    void    *win_ptr;     // Window pointer
}				t_mlx;

typedef struct s_game
{
    char        *map_path;          // Path to map file
    int         collectibles;       // Number of collectibles
    int         players;            // Number of players (should be 1)
    int         exits;              // Number of exits (should be 1)
    int         map_length;         // Map length
    int         file_descriptor;    // Map file descriptor
    char        **map;             // Current game map
    char        **copied_map;      // Copy for pathfinding
    int         move_count;        // Number of moves made
    t_textures  textures;          // Game textures
    t_image     image;             // Current image
    t_player    player;            // Player info
    t_exit      exit;              // Exit info
    t_mlx       mlx;              // MLX instance
}				t_game;
#endif /* STRUCTS_H */