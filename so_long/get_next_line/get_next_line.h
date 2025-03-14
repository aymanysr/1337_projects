/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:34:23 by ayousr            #+#    #+#             */
/*   Updated: 2024/12/07 22:07:03 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_gnl_strdup(const char *s1);
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_substr(char *s, unsigned int start, size_t len);
char	*ft_gnl_strjoin(char *s1, char *s2);
void	fill_string(char *res, char *s1, char *s2);

#endif