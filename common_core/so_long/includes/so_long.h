/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:31:49 by ayousr            #+#    #+#             */
/*   Updated: 2025/02/05 17:40:48 by ayousr           ###   ########.fr       */
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
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "structs.h"
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

/* Texture file paths */
// # define PLAYER_IMG_PATH "textures/player.png"

// Window settings
# define WIN_W 500
# define WIN_H 500
# define TILE_SIZE 32
# define WINDOW_TITLE "so_long"

// map functions
t_map	*parse_map(const char *path);

// utils.c
int		is_ber_file(const char *path);

#endif