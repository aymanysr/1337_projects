/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:31:49 by ayousr            #+#    #+#             */
/*   Updated: 2025/02/12 18:29:33 by aimaneyousr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
** ============================================================================
**	Included Libraries
** ============================================================================
*/
# include "MLX42/MLX42.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "structs.h"
# include "fcntl.h" 
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

/*
** ============================================================================
**	Macros and Constants
** ============================================================================
*/
# define MAX_WIDTH   40       /* Maximum width for the map */
# define MAX_HEIGHT  20       /* Maximum height for the map */
# define PIXELS      64       /* Pixel size for each tile */


// Keyboard Keycodes
# define K_RIGHT 124
# define A_RIGHT 2
# define K_LEFT 123
# define A_LEFT 0
# define K_UP 126
# define A_UP 13
# define K_DOWN 125
# define A_DOWN 1
# define ESC 53

/* Error Codes */
# define ERROR_MAP_NOT_RECTANGULAR        1
# define ERROR_MAP_NOT_SURROUNDED_BY_WALLS  2
# define ERROR_INVALID_NUMBER_OF_PLAYERS    3
# define ERROR_INVALID_NUMBER_OF_EXITS      4
# define ERROR_INVALID_NUMBER_OF_COLLECTIBLES 5
# define ERROR_INVALID_CHARACTER            6
# define ERROR_NO_VALID_PATH                7
# define ERROR_MAP_FILE_EMPTY               8
# define ERROR_FAILED_TO_OPEN_MAP_FILE      9
# define ERROR_INVALID_FILE_EXTENSION       10
# define ERROR_SIZE_MAP                     11

// Map components
# define EMPTY 0
# define WALL 1
# define PLAYER 2
# define COLLECTIBLE 3
# define EXIT 4

// Keyboard Keycodes
# define K_RIGHT 124
# define A_RIGHT 2
# define K_LEFT 123
# define A_LEFT 0
# define K_UP 126
# define A_UP 13
# define K_DOWN 125
# define A_DOWN 1
# define ESC 53


// String Colors
# define R "\x1B[31m"
# define B "\x1B[34m"
# define Y "\x1B[33m"
# define G "\x1B[32m" 
# define W "\x1B[37m"

/* Texture file paths */
// # define PLAYER_IMG_PATH "textures/player.png"

// Window settings
# define WIN_W 500
# define WIN_H 500
# define TILE_SIZE 32
# define WINDOW_TITLE "so_long"

// game banner
void    game_banner(void);

// map functions
int     parse_map(t_game *game);
int     components_checker(t_game *game);
void    map_size(t_game *game);
void    map_free(char **map);
int     check_rectangularity(t_game *game);
int     check_walls(t_game *game);
int     check_items(t_game *game);
void    cp_map(t_game *game);
void	fill_map(t_game *game, int y, int x);
int     checkunreached(t_game *game);
void    game_renderer(t_game *game);
void    load_elements(t_game *game);
void    load_player(t_game *game);
void    renderer(t_game *game, int x, int y);
int     key_hooks(int keycode, t_game *game);

// helper
int	    contains(char *s, char c);
void    put_image_on_window(t_game *game, void *img, int x, int y);

// mlx initializer
void	mlx_initializer(t_game *game);

// variables initializer
void    vars_initializer(t_game *game);

// game errors printer
void	ft_game_errors(char *s);

// path checking
int     is_ber_file(const char *path);

#endif