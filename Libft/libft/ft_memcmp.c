/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 00:31:22 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/01 00:29:29 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	p_s1 = (unsigned char *) s1;
	p_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) p_s1[i] != (unsigned char) p_s2[i])
		{
			return ((unsigned char) p_s1[i] - (unsigned char) p_s2[i]);
		}
		i++;
	}
	return (0);
}
