/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 01:12:13 by ayousr            #+#    #+#             */
/*   Updated: 2024/10/28 19:11:13 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;
	char	*n;

	i = 0;
	h = (char *)haystack;
	n = (char *)needle;
	if (!n[i])
		return (&h[i]);
	while (h[i] && i < len)
	{
		if (h[i] == n[0])
		{
			j = 0;
			while (h[i + j] == n[j] && n[j])
				j++;
			if (!n[j])
				return (&h[i]);
		}
		i++;
	}
	return (0);
}
// int main()
// {
// 	char haystack[] = "HeWoxllo World!";
// 	char needle[] = "Wor";
// 	size_t	len;

// 	len = 16;
// 	printf("MINE: found : %s\n", ft_strnstr(haystack, needle, len));
// 	printf("OG  : found : %s\n", strnstr(haystack, needle, len));
// 	return (0);
// }
