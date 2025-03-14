/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:13:21 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/30 07:22:39 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line	*ft_lstnew(char *content)
{
	t_line	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->length = 0;
	new_node->next = NULL;
	return (new_node);
}

t_line	*ft_lstlast(t_line *lst)
{
	t_line	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_line **lst, t_line *new)
{
	t_line	*tmp;

	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

void	ft_lstclear(t_line **lst, void (*del)(void *))
{
	t_line	*tmp;

	if (!lst || !del)
		return ;
	if (*lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*arr;
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if (size != 0 && count > 18446744073709551615UL / size)
		return (NULL);
	if (count == 0 || size == 0)
		return (malloc(0));
	arr = malloc(count * size);
	if (!arr)
		return (NULL);
	tmp = arr;
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
