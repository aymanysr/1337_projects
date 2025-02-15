/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:23:23 by ayousr            #+#    #+#             */
/*   Updated: 2025/02/15 18:21:14 by aimaneyousr      ###   ########.fr       */
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

static int check_invalid_line(char *s)
{
	int len;
	int i;
	len = ft_strlen(s);
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
int	parse_map(t_game *game)
{
	char	*line;
	char	*lines;
	int		fd;
	
	lines = NULL;
	fd = open(game->map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		lines = ft_gnl_strjoin(lines, line);
		line = get_next_line(fd);
	}
	if (check_invalid_line(lines))
		return (0);
	game->map = ft_split(lines, '\n');
	free(lines);
	close (fd);
	return (1);
}
