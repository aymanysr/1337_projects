/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:02:53 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/11 00:21:36 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_s;

	i = 0;
	p_s = (unsigned char *)s;
	while (i < n)
	{
		if (p_s[i] == (unsigned char)c)
			return ((void *)&p_s[i]);
		i++;
	}
	return (NULL);
}
// int main(void)
// {
// 	const char str[] = "Hello, world!";
// 	int	c = 'w';
// 	size_t n = 12;

// Call memchr to find the frst occurr of 'o' within the frst 13 bytes of str
// 	char *result = ft_memchr(str, c, n);

// 	// Check if result is NULL or points to a valid memory location
// 	if (result != NULL)
// 	{
// 		printf("Character '%c' found at position: %ld\n", c, result - str);
// 		printf("Pointer address: %p\n", result);
// 		printf("Remaining string from found character: %s\n", result);
// 	}
// 	else
// 	{
// 		printf("Character '%c' not found in the first %zu bytes.\n", c, n);
// 	}
// 	return (0);
// }
