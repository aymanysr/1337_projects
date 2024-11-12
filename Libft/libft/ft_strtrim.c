/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:11:20 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/11 00:16:18 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1);
	while (start < end && ft_strchr(set, s1[start]))
		start++;
	if (start == end)
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