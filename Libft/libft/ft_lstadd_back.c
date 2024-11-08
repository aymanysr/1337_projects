/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:54:45 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/07 20:45:56 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

// Function to print the list
// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d -> ", (int)(long)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }
// int	main(int ac, char **av)
// {
// 	t_list	*list;
// 	t_list	*node;
// 	int		i;
// 	int		number;
// 	t_list	*to_free;

// 	list = NULL;
// 	i = 1;
// 	while (i < ac)
// 	{
// 		number = ft_atoi(av[i]);
// 		node = malloc(sizeof(t_list));
// 		if (!node)
// 			return (1);
// 		node->content = (void *)(long)number;
// 		node->next = NULL;
// 		ft_lstadd_back(&list, node);
// 		i++;
// 	}
// 	print_list(list);
// 	while (list)
// 	{
// 		to_free = list;
// 		list = list->next;
// 		free(to_free);
// 	}
// 	return (0);
// }
