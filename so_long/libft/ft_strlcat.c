/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:16:44 by aimaneysr         #+#    #+#             */
/*   Updated: 2025/03/21 02:06:57 by aimaneyousr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s_len;
	size_t	d_len;

	i = 0;
	s_len = ft_strlen(src);
	if (dstsize == 0)
		return (s_len);
	d_len = ft_strlen(dest);
	if (dstsize <= d_len)
	{
		return (s_len + dstsize);
	}
	while (src[i] && d_len + i < dstsize - 1)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}

// int main ()
// {
// 	char dst[]  = "world";
// 	char spr[] = "hello";
// 	char tst[]  = "world";
// 	char tpr[] = "hello";
// 	//ft_strlcat(dst,spr,0);
// 	printf("dest: %s\n",dst);
// 	printf("dest: %p\n",&dst);
// 	printf("%zu\n",strlcat(dst, spr, 5));
// 	printf("%zu\n",ft_strlcat(tst ,tpr, 5));
// }