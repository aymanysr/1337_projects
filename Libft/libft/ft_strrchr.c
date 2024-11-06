/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: aimaneysr <aimaneysr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:10:14 by aimaneysr         #+#    #+#             */
/*   Updated: 2024/11/01 04:17:02 by aimaneysr        ###   ########.fr       */
=======
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:51:18 by ayousr            #+#    #+#             */
/*   Updated: 2024/10/31 23:33:28 by ayousr           ###   ########.fr       */
>>>>>>> 3bff185574da8ef1167dea965eae5a212defa6f9
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
