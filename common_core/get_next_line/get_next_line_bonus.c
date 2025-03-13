/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:10:36 by ayousr            #+#    #+#             */
/*   Updated: 2024/12/07 22:14:57 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(char	*s, int c);
static char	*read_fill_line(int fd, char *content_left, char *buffer);
static char	*extract_update(char *buffer_line);

static char	*extract_update(char *line)
{
	char	*content_left;
	ssize_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	content_left = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*content_left == '\0')
	{
		free(content_left);
		content_left = NULL;
	}
	line[i + 1] = '\0';
	return (content_left);
}

static char	*ft_strchr(char	*s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}

static char	*read_fill_line(int fd, char *content, char *buffer)
{
	ssize_t	is_read;
	char	*tmp;

	is_read = 1;
	while (is_read > 0)
	{
		is_read = read(fd, buffer, BUFFER_SIZE);
		if (is_read == -1)
		{
			free(content);
			return (NULL);
		}
		else if (is_read == 0)
			break ;
		buffer[is_read] = '\0';
		if (!content)
			content = ft_strdup("");
		tmp = content;
		content = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!content || ft_strchr(buffer, '\n'))
			break ;
	}
	return (content);
}

char	*get_next_line(int fd)
{
	static char	*content_left[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
	{
		free(buffer);
		free(content_left[fd]); 
		content_left[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = read_fill_line(fd, content_left[fd], buffer);
	free(buffer);
	if (!line)
	{
		free(content_left[fd]);
		content_left[fd] = NULL;
		return (NULL);
	}
	content_left[fd] = extract_update(line);
	return (line);
}
