/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:23:23 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/20 18:06:33 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/so_long.h"

void	map_size(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		++i ;
	game->map_length = i;
}

void	map_free(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	cp_map(t_game *game)
{
	int		i;
	size_t	j;
	size_t	len;

	game->copied_map = malloc(sizeof(char *) * (game->map_length + 1));
	i = 0;
	while (i < game->map_length)
	{
		len = ft_strlen(game->map[i]);
		j = 0;
		game->copied_map[i] = malloc(sizeof(char) * (len + 1));
		while (j < len)
		{
			game->copied_map[i][j] = game->map[i][j];
			j++;
		}
		game->copied_map[i][j] = '\0';
		i++;
	}
	game->copied_map[i] = NULL;
}

void	fill_map(t_game *game, int y, int x)
{
	int	row_length;

	row_length = ft_strlen(game->copied_map[y]);
	if (x + 1 < row_length && game->copied_map[y][x + 1] != '1' &&
		game->copied_map[y][x + 1] != 'M')
	{
		game->copied_map[y][x + 1] = '1';
		fill_map(game, y, x + 1);
	}
	if (x - 1 >= 0 && game->copied_map[y][x - 1] != '1' &&
		game->copied_map[y][x - 1] != 'M')
	{
		game->copied_map[y][x - 1] = '1';
		fill_map(game, y, x - 1);
	}
	if (y + 1 < game->map_length && game->copied_map[y + 1][x] != '1'
		&& game->copied_map[y + 1][x] != 'M')
	{
		game->copied_map[y + 1][x] = '1';
		fill_map(game, y + 1, x);
	}
	if (y - 1 >= 0 && game->copied_map[y - 1][x] != '1'
		&& game->copied_map[y - 1][x] != 'M')
	{
		game->copied_map[y - 1][x] = '1';
		fill_map(game, y - 1, x);
	}
}

// main function to parse the map
int	parse_map(t_game *game)
{
	char	*line;
	char	*lines;
	int		fd;
	char	*tmp;

	fd = open(game->map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	lines = ft_strdup(line);
	free(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = lines;
		lines = ft_strjoin(lines, line);
		free(tmp);
		free(line);
	}
	if (check_invalid_line(lines))
		return (0);
	game->map = ft_split(lines, '\n');
	free(lines);
	close (fd);
	return (1);
}
