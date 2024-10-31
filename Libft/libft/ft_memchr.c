/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:02:53 by ayousr            #+#    #+#             */
/*   Updated: 2024/10/28 00:14:59 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_s;

	i = 0;
	p_s = (unsigned char *)s;
	if (n > 0)
	{
		while (i < n)
		{
			if (p_s[i] == (unsigned char)c)
			{
				return ((void *)&p_s[i]);
			}
			i++;
		}
	}
	return (NULL);
}
// 
