/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: aimaneysr <aimaneysr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:10:14 by aimaneysr         #+#    #+#             */
/*   Updated: 2024/10/26 10:58:36 by aimaneysr        ###   ########.fr       */
=======
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:51:18 by ayousr            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/31 23:33:28 by ayousr           ###   ########.fr       */
=======
/*   Updated: 2024/10/31 04:11:28 by ayousr           ###   ########.fr       */
>>>>>>> 1a8cb47ae31ca73401ed04af56296bc814b6a713
>>>>>>> 8bad30f261258758363ff972064e63f5e4a858c5
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
char *ft_strrchr(const char *s, int c)
{
    int i;

    i = ft_strlen(s);
    while (i > 0)
    {
        if (s[i] == c)
        {
            return((char *)&s[i]);
        }
        i--;
    }
    if (s[i] == "\0")
        return ((char *)&s[i]);
    return (NULL);
}
=======
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
>>>>>>> 1a8cb47ae31ca73401ed04af56296bc814b6a713
