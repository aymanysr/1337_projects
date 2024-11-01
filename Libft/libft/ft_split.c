/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:11:42 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/01 00:35:07 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

static	int	word_count(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	int w_count;
	char **arr;
	
	w_count = word_count(s, c);
	if (!s)
		return (NULL);
	if (!*s)
	{
		arr = (char **)malloc(sizeof(char *));
		if (!arr)
			return (NULL);
		arr[0] = NULL;
		return (arr);
	}
	arr = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (!arr)
		return (NULL);

	
	int i;
	int start;
	int end;

	start = 0;
	i = 0;
	while (i < w_count)
	{
		while (s[start] && c == s[start])
			start++;
		end = start;
		while (s[end] && c != s[end])
			end++;
		arr[i] = ft_substr((const char *)s, start, (size_t)(end - start));
		if (!arr[i])
		{
			while (--i >= 0)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		start = end + 1;
		i++;
	}
	arr[i] =  NULL;
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

int main(void)
{
	char *s = "/////sssss/sss";
	char **arr = ft_split(s,'/');

	int i = 0;
	for(i = 0; i <= 4; i++ )
		printf("%s\n",arr[i]);
	return (0);
}
