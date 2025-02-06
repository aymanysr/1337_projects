/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:12:48 by ayousr            #+#    #+#             */
/*   Updated: 2025/02/05 17:55:05 by ayousr           ###   ########.fr       */
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

/*
 * Represents the game map.
 * Contains the grid of tiles, dimensions of the map,
	and various map properties.
 */
typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	int		num_players;
	int		num_collectibles;
	int		num_exits;
	bool	is_valid;
}				t_map;
/**
 * Holds the file paths for various game textures.
*/
typedef struct s_texture_paths
{
	char	*ground;
	char	*walls;
	char	*collectibles;
	char	*exit_idle;
	char	*exit_active;
	char	*player;
}				t_texture_paths;

/*
 * Represents a 2D point on the screen or map.
 * Used for player position, tile positions, etc.
 */

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

/*
** t_game_images
** -------------
** Holds pointers to the game images created by the MLX library.
** Fields:
**   - player: Image for the player.
**   - wall: Image for the wall.
**   - collectible: Image for a collectible.
**   - exit: Image for the exit.
*/
typedef struct s_game_images
{
	mlx_image_t	*player;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
}				t_game_images;

/*
** t_game
** ------
** Main structure holding all game-related data.
** Fields:
**   - mlx: Pointer to the MLX instance.
**   - map_data: Pointer to the map configuration.
**   - images: Game images.
**   - player_pos: Current position of the player.
**   - textures: Paths to the textures used in the game.
*/
typedef struct s_game
{
	mlx_t				*mlx;
	t_map				*map_data;
	t_game_images		images;
	t_position			player_pos;
	t_texture_paths		*textures;
}				t_game;
#endif /* STRUCTS_H */