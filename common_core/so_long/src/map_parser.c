/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:23:23 by ayousr            #+#    #+#             */
/*   Updated: 2025/02/05 18:07:18 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/so_long.h"

// function to check if a file has .ber extension

int	is_ber_file(const char *path)
{
	size_t	len;

	len = libft_ft_strlen(path);
	if (len < 4)
		return (0);
	return (strcmp(path + len - 4, ".ber") == 0);
}

// Function to count lines in file (to deterine map height)
size_t	count_map_lines(const char *path)
{
	int	fd;
}

// Initialize the map structure
void	init_map(t_map *map, const char *path)
{
	map->path = ft_strdup(path);
	map->height = 0;
	map->width = 0;
	map->grid = NULL;
	map->tiles = NULL;
	map->exit_accessible = 0;
	map->fd = -1;
	map->accessible_collectibles = 0;
}

// main function to parse the map
t_map	parse_map(const char *path)
{
	t_map	map;

	if (!path || !is_ber_file(path))
		return ;
	map = malloc(sizeof(t_map));
	if (!map)
		return ;
	init_map(map, path);
	return (map);
}
