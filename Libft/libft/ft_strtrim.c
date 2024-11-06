/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:11:20 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/02 00:13:31 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (!*s1)
		return (ft_strdup(""));
	start = 0;
	len = ft_strlen(s1);
	end = len;
	while (start < len && ft_strchr(set, s1[start]))
		start++;
	if (start == len)
		return (ft_strdup(""));
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}

// int main()
// {
// 	char *s1 = "123d";
// 	char *set = "d";
// 	char *result = ft_strtrim(s1, set);
// 	printf("Result: '%s'\n", result); // Expected: "123"
// 	free(result);

// 	s1 = "d123d";
// 	result = ft_strtrim(s1, set);
// 	printf("Result: '%s'\n", result); // Expected: "123"
// 	free(result);

// 	return 0;
// }