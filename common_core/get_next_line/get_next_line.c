/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:49:40 by ayousr            #+#    #+#             */
/*   Updated: 2024/12/07 20:57:44 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static void	read_ln(t_line **cache, int fd);
// static int	contains_newline(t_line *cache);
// static void	build_line(t_line *cache, char **line);
// static void	shift_cache(t_line **cache);
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
		else if (is_read <= 0)
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
	static char	*content_left;
	char		*line;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
	{
		free(buffer);
		free(content_left);
		content_left = NULL;
		return (NULL);
	}
	line = read_fill_line(fd, content_left, buffer);
	free(buffer);
	if (!line)
	{
		free(content_left);
		content_left = NULL;
		return (NULL);
	}
	content_left = extract_update(line);
	return (line);
}

// // void hh(int fd)
// // {
// // 	system("a.out");
// // }
// int	main(void)
// {
// 	int		fd = open("nextline.txt", O_RDONLY, O_APPEND);
// 	// hh(fd);
// 	// char	*line;

// 	// if (fd < 0)
// 	// {
// 	// 	printf("Failed to open file\n");
// 	// 	return (1);
// 	// }
// 	// while ((line = get_next_line(fd)) != NULL)
// 	// {
// 	// 	printf("%s", line);
// 	// 	free(line);
// 	// }
// 	// close(fd);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// return (0);
// }