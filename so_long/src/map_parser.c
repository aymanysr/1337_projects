/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>			    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:23:23 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/20 20:21:34 by ayousr		      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/so_long.h"

int	check_invalid_line(char *s)
{
	int	len;
	int	i;

	len = ft_sl_strlen(s);
	if (s[len - 1] == '\n' || s[0] == '\n')
		return (1);
	i = 1;
	while (i < len - 1)
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (1);
		++i;
	}
	return (0);
}

// main function to parse the map
static char	*read_map_file(int fd)
{
	char	*line;
	char	*all;
	char	*tmp;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	all = ft_strdup(line);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		tmp = all;
		all = ft_strjoin(all, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	return (all);
}

int	parse_map(t_game *game)
{
	char	*lines;
	int		fd;

	fd = open(game->map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	lines = read_map_file(fd);
	if (!lines)
		return (0);
	if (check_invalid_line(lines))
	{
		free(lines);
		return (0);
	}
	game->map = ft_split(lines, '\n');
	free(lines);
	close(fd);
	return (1);
}
