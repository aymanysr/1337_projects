/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:09:07 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/02 03:27:56 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (unsigned char *)malloc(count * size);
	if (tmp == NULL)
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
//     size_t count = sizeof(int);
//     size_t size = 10;
//     unsigned char *result = (unsigned char *)ft_calloc(count, size);

//     if (result != NULL)
//     {
//         for (size_t i = 0; i < count * size; i++)
//         {
//             printf("%d ", result[i]); // Should print 40 zeros
//         }
//         free(result);
//     }

//     return 0;
// }