/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:09:07 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/10 18:55:56 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if (size != 0 && count > 18446744073709551615UL / size)
		return (NULL);
	if (count == 0 || size == 0)
		return (malloc(0));
	tmp = (unsigned char *)malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

// int main()
// {
// 	size_t			count = 10;
// 	size_t			size = 1;
// 	unsigned char	*result = (unsigned char *)ft_calloc(count, size);
// 	unsigned char	*ogRes = (unsigned char *)calloc(count , size);
// 	if (result != NULL)
// 	{
// 		for (size_t i = 0; i < count * size; i++)
// 		{
// 			printf("myFunc -> %d | ", result[i]);
// 			printf("ogFunc -> %d ", ogRes[i]);
// 			printf("\n");
// 		}
// 		free(result);
// 	}
// 	return (0);
// }