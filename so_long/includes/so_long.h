/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:31:49 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/22 00:07:47 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
**	Included Libraries
*/
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../bonus/includes_bonus/so_long_bonus.h"
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

/*
	 Game Initialization and Asset Loading (assets_init.c)
 */
void	vars_initializer(t_game *game);
void	mlx_initializer(t_game *game);
void	load_elements(t_game *game);
void	load_player(t_game *game);
void	initialize_game(t_game *game);

/*
	 Map Parsing (map_parser.c)
 */
int		parse_map(t_game *game);
void	map_size(t_game *game);
void	cp_map(t_game *game);
bool	is_valid_move(t_game *game, int y, int x);
void	fill_map(t_game *game, int y, int x);

/*
	 Map Validation (map_validation.c)
 */
int		check_rectangularity(t_game *game);
int		check_walls(t_game *game);
int		check_items(t_game *game);
int		check_unreached(t_game *game);
int		components_checker(t_game *game);

/*
	 Map Utilities (map_utils.c)
 */
int		check_invalid_line(char *s);
void	counter(t_game *game, char c, int i, int j);

/*
	 Texture and Player Assets Loading
	 (textures.c & player_assets.c)
 */
// Basic Textures (textures.c)
void	load_basic_textures(t_game *game);
void	convert_basic_textures_to_images(t_game *game);
// Player Assets (player_assets.c)
void	load_all_player_assets(t_game *game);
void	load_player(t_game *game);

/*
	 Rendering Functions
	 (render_core.c & render_manager.c)
 */
// Low-level Rendering (render_core.c)
int		is_grey(uint8_t r, uint8_t g, uint8_t b);
void	process_row(mlx_image_t *dest, mlx_image_t *src,
			t_offset offset, int y);
void	blit_image(mlx_image_t *dest, mlx_image_t *src, int dx, int dy);
/* NEW: blit_image_no_skip copies every pixel without skipping grey pixels */
void	blit_image_no_skip(mlx_image_t *dest, mlx_image_t *src, int dx, int dy);
void	render_player(t_game *game, int dx, int dy);
void	render_cell(t_game *game, int x, int y);
void	put_image_on_window(t_game *game, mlx_texture_t *texture, int x, int y);
// High-level Rendering (render_manager.c)
void	renderer(t_game *game);
void	game_renderer(t_game *game);
void	update_animation(void *param);

/*
	 Player Control (player_control.c) & (enemy_control.c) & (enemy_init.c)
 */
void	player_coordinates(t_game *game, char c);
void	update_player_position(t_game *game, int x, int y, char direction);
int		key_hooks(int keycode, t_game *game);
void	player_controller(mlx_key_data_t key_data, void *param);
void	move_player(t_game *game, int dx, int dy, char direction);

/*
	 Cleanup and Error Handling
	 (cleanup.c & error_handling.c)
 */
// Cleanup (cleanup.c)
void	cleanup_game(t_game *game);
void	map_free(char **map);
void	free_player_horizontal_textures(t_game *game);
void	free_player_vertical_textures(t_game *game);
void	free_environment_textures(t_game *game);
void	free_textures(t_game *game);
void	free_images(t_game *game);
void	free_map_data(t_game *game);
void	terminate_mlx_instance(t_game *game);
// Error Handling and gracious exits (error_handling.c)
void	img_destroyer(t_game *game, char *s, char *c);
void	ft_game_errors(char *s, t_game *game);
int		contains(char *s, char c);

int		ft_sl_strlen(const char *str);

// update_game.c
void	update_game(void *param);
/*
	 Miscellaneous
 */
void	game_banner(void);
#endif