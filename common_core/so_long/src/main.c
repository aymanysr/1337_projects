/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:26:32 by ayousr            #+#    #+#             */
/*   Updated: 2025/02/15 18:24:27 by aimaneyousr      ###   ########.fr       */
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
	else if (ac == 2)
	{
		game.map_path = av[1];
		vars_initializer(&game);
		if (components_checker(&game))
		{
			game_banner();
			mlx_initializer(&game);
			game_renderer(&game);
		}
	}
	ft_game_errors("[!!!] Invalid arguments");
	return (0);
}
