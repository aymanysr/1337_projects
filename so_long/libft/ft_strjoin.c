/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 04:56:45 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/11 19:54:28 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*mstr;
	size_t			i;
	size_t			j;

	i = 0;
	mstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!mstr)
		return (NULL);
	while (s1[i])
	{
		mstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		mstr[i] = s2[j];
		i++;
		j++;
	}
	mstr[i] = '\0';
	return (mstr);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "hello ";
// 	s2 = "world!";
// 	printf("myfunc: %s\n", ft_strjoin(s1, s2));
// 	printf("myfunc: %zu\n", ft_strlen(ft_strjoin(s1, s2)));
// 	return (0);
// }