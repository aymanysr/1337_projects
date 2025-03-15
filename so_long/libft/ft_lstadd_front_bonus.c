/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:18:11 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/11 19:54:05 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*list;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*current_ptr;

// 	node1 = malloc(sizeof(t_list));
// 	node2 = malloc(sizeof(t_list));
// 	node3 = malloc(sizeof(t_list));
// 	if (!node1 || !node2 || !node3)
// 		return (1);
// 	list = NULL;
// 	node1->content = (void *)"1";
// 	node1->next = NULL;
// 	node2->content = (void *)"2";
// 	node2->next = NULL;
// 	node3->content = (void *)"3";
// 	node3->next = NULL;
// 	ft_lstadd_front(&list, node1);
// 	ft_lstadd_front(&list, node2);
// 	ft_lstadd_front(&list, node3);
// 	current_ptr = list;
// 	while (current_ptr != NULL)
// 	{
// 		printf("%s -> ", (char *)current_ptr->content);
// 		current_ptr = current_ptr->next;
// 	}
// 	printf("NULL\n");
// 	while (list != NULL)
// 	{
// 		t_list	*temp = list;

// 		list = list->next;
// 		free(temp);
// 	}
// }
