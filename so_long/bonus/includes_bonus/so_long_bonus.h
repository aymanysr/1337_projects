#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/*
**	Included Libraries
// */
// # include "ft_printf.h"
// # include "get_next_line.h"
// # include "libft.h"
# include "structs.h"
# include "fcntl.h" 
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

/*
**	Macros and Constants
*/
# define MAX_WIDTH   40       /* Maximum width for the map */
# define MAX_HEIGHT  20       /* Maximum height for the map */
# define PIXELS      64       /* Pixel size for each tile */
# define WIN_W 500
# define WIN_H 500
# define TILE_SIZE 50
# define WINDOW_TITLE "so_long"

// String Colors
# define R "\x1B[31m"
# define B "\x1B[34m"
# define Y "\x1B[33m"
# define G "\x1B[32m" 
# define W "\x1B[37m"

# define BPP 4 // sizeof(int32_t)
# define GRAY_R 33
# define GRAY_G 33
# define GRAY_B 33

void    update_enemy_patrol(void *param);
void	init_enemies(t_game *game);
void    free_enemy_texture(t_game *game);
void    load_enemy_textures(t_game *game);
void	display_move_count(t_game *game);
void    vars_initializer_bonus(t_game *game);

#endif