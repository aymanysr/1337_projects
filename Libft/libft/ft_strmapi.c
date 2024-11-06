/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:22:04 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/04 15:19:39 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res [i] = 0;
	return (res);
}

// char sample_function(unsigned int i, char c)
// {
// 	return c + i;
// }

// int main()
// {
// 	const char *s = "abcdef";
// 	char *result;

// 	result = ft_strmapi(s, sample_function);

// 	if (result)
// 	{
// 		printf("Original string: %s\n", s);
// 		printf("Modified string: %s\n", result);
// 		free(result);
// 	}
// 	else
// 		printf("Memory allocation failed\n");

// 	return 0;
// }
