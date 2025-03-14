/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:40:32 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/07 01:18:42 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		len;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

// int	main(void)
// {
// 	t_list	*list;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*tmp;

// 	node1 = malloc(sizeof(t_list));
// 	node1->content = (void *)"1";
// 	node1->next = NULL;
// 	node2 = malloc(sizeof(t_list));
// 	node2->content = (void *)"2";
// 	node2->next = NULL;
// 	node3 = malloc(sizeof(t_list));
// 	node3->content = (void *)"3";
// 	node3->next = NULL;
// }
