/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:57:30 by ayousr            #+#    #+#             */
/*   Updated: 2024/12/03 12:53:24 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

typedef struct s_line
{
	char			*content;
	int				length;
	struct s_line	*next;
}	t_line;

char	*get_next_line(int fd);

/* utils */
t_line	*ft_lstnew(char *content);
t_line	*ft_lstlast(t_line *lst);
void	ft_lstadd_back(t_line **lst, t_line *new);
void	ft_lstclear(t_line **lst, void (*del)(void *));
void	*ft_calloc(size_t count, size_t size);
#endif