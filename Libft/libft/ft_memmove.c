/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:42:42 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/01 01:07:58 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (!dst && !src)
		return (NULL);
	index = 0;
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (index < len)
		{
			d[index] = s[index];
			index++;
		}
	}
	return (dst);
}

// int	main(void)
// {
// 	char str1[] = "Hello World";
// 	char str2[] = "Hello World";

// 	printf("Example 1 - Forward copy:\n");
// 	printf("Before: %s\n", str1);
// 	ft_memmove(str1, str1 + 6, 5);
// 	printf("After:  %s\n\n", str1);
// 	printf("Example 2 - Backward copy:\n");
// 	printf("Before: %s\n", str2);
// 	ft_memmove(str2 + 6, str2, 5);
// 	printf("After:  %s\n", str2);
// 	return (0);
// }
