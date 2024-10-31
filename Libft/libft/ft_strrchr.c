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
/*   Updated: 2024/10/31 04:11:28 by ayousr           ###   ########.fr       */
>>>>>>> 1a8cb47ae31ca73401ed04af56296bc814b6a713
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
	size_t	s_len;

	s_len = ft_strlen(s);
	while (s_len >= 0)
	{
		if (s[s_len] == (char)c)
		{
			return ((char *)s + s_len);
		}
		s_len--;
	}
	return (0);
}
>>>>>>> 1a8cb47ae31ca73401ed04af56296bc814b6a713
