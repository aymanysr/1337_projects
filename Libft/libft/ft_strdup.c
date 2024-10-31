/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:16:39 by ayousr            #+#    #+#             */
/*   Updated: 2024/10/28 20:49:17 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = 0;
	if (!tmp)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
// int main(void)
// {
// 	char	*s = "aimeyez";
// 	char	*dup;
// 	dup = ft_strdup(s);
// 	printf("%s\n", dup);
// }