/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:49:40 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/21 02:06:13 by aimaneyousr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	read_ln(t_line **cache, int fd);
static int	contains_newline(t_line *cache);
static void	build_line(t_line *cache, char **line);
static void	shift_cache(t_line **cache);

static void	shift_cache(t_line **cache)
{
	t_line	*temp;
	t_line	*new_node;
	char	*content;
	int		i;
	int		size;

	size = 0;
	temp = ft_lstlast(*cache);
	if (!temp)
		return ;
	content = temp->content;
	size = temp->length;
	temp->content = NULL;
	ft_lstclear(cache, free);
	i = 0;
	if (content[size] != '\0')
	{
		while (content[size] != '\0')
			content[i++] = content[size++];
		content[i] = '\0';
		new_node = ft_lstnew(content);
		ft_lstadd_back(cache, new_node);
	}
	else
		free(content);
}

static void	read_ln(t_line **cache, int fd)
{
	int		output;
	char	*buf;
	t_line	*new_node;

	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	output = read(fd, buf, BUFFER_SIZE);
	if (output <= 0)
	{
		free(buf);
		return ;
	}
	buf[output] = '\0';
	new_node = ft_lstnew(buf);
	if (!new_node)
	{
		free(buf);
		return ;
	}
	new_node->length = output;
	ft_lstadd_back(cache, new_node);
}

static int	contains_newline(t_line *cache)
{
	t_line	*current;
	int		i;

	current = cache;
	while (current)
	{
		if (current->content)
		{
			i = 0;
			while (current->content[i] != '\0')
			{
				if (current->content[i] == '\n')
				{
					current->length = i + 1;
					return (1);
				}
				i++;
			}
		}
		current = current->next;
	}
	return (0);
}

static void	build_line(t_line *cache, char **line)
{
	int		i;
	int		ln_size;
	t_line	*tmp;

	tmp = cache;
	ln_size = 0;
	while (tmp)
	{
		ln_size += tmp->length;
		tmp = tmp->next;
	}
	if (!ln_size)
		return ;
	*line = malloc(sizeof(**line) * (ln_size + 1));
	if (!*line)
		return ;
	ln_size = 0;
	while (cache && cache->content)
	{
		i = 0;
		while (cache->content[i] && i < cache->length)
			(*line)[ln_size++] = cache->content[i++];
		cache = cache->next;
	}
	(*line)[ln_size] = '\0';
}

char	*get_next_line(int fd)
{
	static t_line	*cache = NULL;
	char			*next_line;

	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	while (!contains_newline(cache))
	{
		read_ln(&cache, fd);
		if (!cache)
			break ;
	}
	if (!cache)
		return (NULL);
	build_line(cache, &next_line);
	shift_cache(&cache);
	return (next_line);
}

// int	main(void)
// {
// 	int		fd = open("nextline.txt", O_RDONLY, O_APPEND);
// 	char	*line;

// 	if (fd < 0)
// 	{
// 		printf("Failed to open file\n");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
