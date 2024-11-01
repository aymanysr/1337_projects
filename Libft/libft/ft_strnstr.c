/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 01:12:13 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/01 00:41:50 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[i])
		return ((char *)&haystack[i]);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
// int main()
// {
// 	char haystack[] = "salim";
// 	char needle[] = "lim";
// 	size_t	len;

// 	len = 5;
// 	printf("MINE: found : %s\n", ft_strnstr(haystack, needle, len));
// 	// printf("OG  : found : %s\n", strnstr(haystack, needle, len));
// 	return (0);
// }
