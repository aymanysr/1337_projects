/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:26:32 by ayousr            #+#    #+#             */
/*   Updated: 2025/02/05 18:09:03 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/structs.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("ERROR\nUsage: %s <map.ber>\n", av[0]);
		return (1);
	}
	else if (ac == 2 && !(is_ber_file(av[1])))
		ft_printf("ERROR\nUsage: %s <map.ber>\n", av[0]);
	game.map_data = *parse_map("maps/map1.ber");
	game.mlx = mlx_init(game.map_data->width * PIXELS,
			game.map_data->height * PIXELS, "so_long", false);
	mlx_loop(game.mlx);
}
