/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:11:26 by aimaneysr         #+#    #+#             */
/*   Updated: 2024/10/25 20:03:29 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

// int main(void)
// {
// 	char			*src;
// 	char			dest[30];
// 	unsigned int	size;

// 	size = 20;
// 	src = "this is a test!";
// 	printf("%zu\n", ft_strlcpy(dest, src, size));
// 	printf("%s\n", dest);
// 	return 0;
// }
