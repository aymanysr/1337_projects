/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:36:40 by aimaneysr         #+#    #+#             */
/*   Updated: 2024/11/11 19:54:25 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == src)
		return (dest);
	while (i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}
// int main(void)
// {
// 	const char src[] = "This is a test of memcpy.";
// 	char dest_ft[50];
// 	char dest_std[50];
// 	size_t n = 20;

// 	memcpy(dest_std, src, n);
// 	ft_memcpy(dest_ft, src, n);
// 	dest_ft[n] = '\0';
// 	dest_std[n] = '\0';
// 	printf("Source string:		\"%s\"\n", src);
// 	printf("sd_memcpy result:	\"%s\"\n", dest_std);
// 	printf("ft_memcpy result:	\"%s\"\n", dest_ft);
// 	if (strcmp(dest_ft, dest_std) == 0)
// 	{
// 		printf("ft_memcpy matches standard memcpy output.\n");
// 	}
// 	else
// 	{
// 		printf("ft_memcpy does NOT match standard memcpy output.\n");
// 	}
// 	return (0);
// }
