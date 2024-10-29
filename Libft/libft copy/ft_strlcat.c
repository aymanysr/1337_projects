/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:16:44 by aimaneysr         #+#    #+#             */
/*   Updated: 2024/10/25 19:43:57 by ayousr           ###   ########.fr       */
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
	d_len = strlen(dest);
	s_len = strlen(src);
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
		dest[i] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (d_len + s_len); 
}
