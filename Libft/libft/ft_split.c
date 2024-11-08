/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:11:42 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/01 22:50:19 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	word_count(const char *s, char c);
static	char	**malloc_array(int w_count);
static	int	fill_array(char **arr, const char *s, char c, int w_count);

char	**ft_split(char const *s, char c)
{
	int		w_count;
	char	**arr;

	if (!s)
		return (NULL);
	w_count = word_count(s, c);
	if (!*s)
	{
		arr = (char **)malloc(sizeof(char *));
		if (!arr)
			return (NULL);
		arr[0] = NULL;
		return (arr);
	}
	arr = malloc_array(w_count);
	if (!arr)
		return (NULL);
	if (fill_array(arr, s, c, w_count) == -1)
		return (NULL);
	return (arr);
}

static	int	word_count(const char *s, char c)
{
	int		i;
	int		flag;
	int		w_count;

	i = 0;
	flag = 0;
	w_count = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			w_count++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (w_count);
}

static	char	**malloc_array(int w_count)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (!arr)
		return (NULL);
	arr[w_count] = NULL;
	return (arr);
}

static int	fill_array(char **arr, const char *s, char c, int w_count)
{
	int	i;
	int	start;
	int	end;

	start = 0;
	i = 0;
	while (i < w_count)
	{
		while (s[start] && c == s[start])
			start++;
		end = start;
		while (s[end] && c != s[end])
			end++;
		arr[i] = ft_substr(s, start, end - start);
		if (!arr[i])
		{
			while (--i >= 0)
				free(arr[i]);
			free(arr);
			return (-1);
		}
		start = end + 1;
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*s = "//Hello///sssss/world//!!//**//";
// 	char	**arr = ft_split(s,'/');
// 	int		i;

// 	i = 0;
// 	for(i = 0; i <= 5; i++ )
// 		printf("%s\n",arr[i]);
// 	return (0);
// }
