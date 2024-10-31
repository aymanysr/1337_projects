/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:11:20 by ayousr            #+#    #+#             */
/*   Updated: 2024/10/31 04:24:23 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	f;
	size_t	l;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (!*s1)
		return (ft_strdup(""));
	f = 0;
	l = ft_strlen(s1) - 1;
	while (s1[f] && ft_strchr(set, s1[f]))
		f++;
	if (!s1[f])
		return (ft_strdup(""));
	while (ft_strchr(set, s1[l]) && l > f)
		l--;
	return (ft_substr(s1, f, (l - f) + 1));
}

// int	main(void)
// {
// 	char	*s;
// 	char	*set;

// 	s = "cababaaaMy name is Simoncbbaaabba";
// 	set = "abc";
// 	printf("myfunc: %s\n", ft_strtrim(s, set));
// 	return (0);
// }
