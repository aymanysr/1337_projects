/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneysr <aimaneysr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:51:18 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/06 16:27:48 by aimaneysr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;
	char	chr;

	chr = (char) c;
	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == chr)
			res = (char *)&s[i];
		i++;
	}
	if (s[i] == chr)
		res = (char *)&s[i];
	return (res);
}
