/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:55:05 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/20 17:58:35 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_destroyer(t_game *game, char *s, char *c)
{
	ft_printf("%s%s%s\n", c, s, W);
	cleanup_game(game);
	exit(0);
}

void	ft_game_errors(char *s, t_game *game)
{
	ft_printf("Error\n%s\n", s);
	cleanup_game(game);
	exit(EXIT_FAILURE);
}

int	contains(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		++s;
	}
	return (0);
}
