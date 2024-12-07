/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:11:26 by aimaneysr         #+#    #+#             */
/*   Updated: 2024/11/10 23:44:39 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize != 0)
	{
		i = 0;
		while (src[i] && i < (dstsize - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

//  int main(void)
// {
// 	char			*src;
//  	char			dest[30];
//  	unsigned int	size;

//  	size = 3;
//  	src = "this is a test!";
//  	printf("%zu\n", ft_strlcpy(dest, src, size));
//  	printf("%s %s\n", dest, src); 	
// 	printf("%zu\n", strlcpy(dest, src, size));
//  	printf("%s %s\n", dest , src);

//  	return 0;
// }
