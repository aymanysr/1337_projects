/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:37:02 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/11 23:45:16 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		(f)(tmp->content);
		tmp = tmp->next;
	}
}

// void	double_value(void *content)
// {
// 	int	*val;

// 	val = (int *)content;
// 	*val *= 2;
// }

// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d -> ", *(int *)(lst->content));
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// int	main(int ac, char**av)
// {
// 	t_list	*list;
// 	t_list	*node;
// 	t_list	*to_free;
// 	int		i;
// 	long	*number;

// 	list = NULL;
// 	i = 1;
// 	while (i < ac)
// 	{
// 		number = malloc(sizeof(long));
// 		if (!number)
// 			return (1);
// 		*number = atoi(av[i]);
// 		node = ft_lstnew((void *)number);
// 		ft_lstadd_back(&list, node);
// 		i++;
// 	}
// 	printf("Original list:\n");
// 	print_list(list);
// 	ft_lstiter(list, double_value);
// 	printf("List after doubling each value:\n");
// 	print_list(list);
// 	while (list)
// 	{
// 		to_free = list;
// 		free(list->content);
// 		list = list->next;
// 		free(to_free);
// 	}
// 	return (0);
// }
