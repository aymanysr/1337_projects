/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:52:55 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/10 19:29:31 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del || !lst)
		return ;
	del(lst->content);
	free(lst);
}

// // Function to print the list
// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d -> ", (int)(long)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// void	del(void *content)
// {
// 	(void)content;
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
// 		t_list	*tmp;

// 		print_list(list);
// 		tmp = list->next;
// 		ft_lstdelone(list, del);
// 		list = tmp;
// 	}
// 	printf("List after deleting the nodes:\n");
// 	print_list(list);
// 	while (list)
// 	{
// 		to_free = list;
// 		list = list->next;
// 		free(to_free);
// 	}
// 	return (0);
// }
