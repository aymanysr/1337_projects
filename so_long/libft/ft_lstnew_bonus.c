/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:33:48 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/06 21:41:33 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

// int	main(void)
// {
// 	char	*content;
// 	t_list	*new_elem;

// 	content = "Hello, World!";
// 	new_elem = ft_lstnew(content);
// 	if (new_elem)
// 	{
// 		printf("Content: %s\n", (char *)new_elem->content);
// 		printf("Next: %p\n", (void *)new_elem->next);
// 	}
// 	else
// 		printf("Failed to create new list element.\n");
// 	free(new_elem);
// 	return (0);
// }
