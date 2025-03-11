/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:26:32 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/11 13:38:06 by aimaneyousr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/structs.h"

int	main(int ac, char **av)
{
	t_game	*game;

	/* Immediately handle invalid arguments */
	if (ac != 2)
		ft_game_errors("Usage: ./so_long <map.ber>");
	
	/* Allocate and initialize game structure */
	game = malloc(sizeof(t_game));
	if (!game)
		ft_game_errors("Memory allocation error");
	vars_initializer(game);
	vars_initializer_bonus(game);
	game->map_path = av[1];

	/* Validate map and its components */
	if (!components_checker(game))
		ft_game_errors("[!!!] Map validation failed.");

	/* Initialize MLX, load assets, and display initial game state */
	mlx_initializer(game);
	game_banner();
	load_enemy_textures(game);
	init_enemies(game);
	initialize_game(game);
	

	/* Set up key and loop hooks */
	mlx_key_hook(game->mlx.mlx_ptr, player_moover, game);
	mlx_loop_hook(game->mlx.mlx_ptr, update_game, game);
	mlx_loop(game->mlx.mlx_ptr);
	return (0);
}

