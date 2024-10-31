/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:16:44 by aimaneysr         #+#    #+#             */
/*   Updated: 2024/10/31 04:02:02 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	size_t	d_len;

	i = 0;
	j = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	while (dest[j] != '\0')
	{
		j++;
	}
	if (dstsize == 0 || dstsize < d_len)
	{
		return (s_len + dstsize);
	}
	while (src[i] != '\0' && i < dstsize - d_len - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (d_len + s_len); 
}
// int main ()
// {
//     char dst[7]  = "world";
//     char spr[] = "hello";
//     char tst[7]  = "world";
//     char tpr[] = "hello";
//     //ft_strlcat(dst,spr,0);
//     printf("%zu\n",ft_strlcat(dst,spr, 7));
//     printf("%s\n",dst);
//     printf("%zu\n",strlcat(tst,tpr, 7));
//     printf("%s\n",tst);
// }