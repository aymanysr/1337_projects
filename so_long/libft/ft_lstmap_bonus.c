/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:51:25 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/21 02:09:12 by aimaneyousr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (lst == NULL || (f) == NULL || (del) == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			if (new_content)
				del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

// void	*double_value(void *content)
// {
// 	int	*val;

// 	val = (int *)content;
// 	*val *= 2;
// 	return (content); 
// }

// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d -> ", *(int *)lst->content);
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
// 	t_list	*to_free;
// 	long	*number;
// 	int		i;

// 	i = 1;
// 	list = NULL;
// 	while (i < ac)
// 	{
// 		number = malloc(sizeof(long));
// 		if (!number)
// 			return (1);
// 		*number = ft_atoi(av[i]);
// 		node = ft_lstnew((void *)number);
// 		ft_lstadd_back(&list, node);
// 		i++;
// 	}
// 	printf("Original List:\n");
// 	print_list(list);
// 	ft_lstmap(list, double_value, del);
// 	printf("List after mapping each value:\n");
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