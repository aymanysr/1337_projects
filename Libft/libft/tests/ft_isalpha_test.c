/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:31:28 by ayousr            #+#    #+#             */
/*   Updated: 2024/10/23 19:52:11 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	main(void)
{
	int	x;
	int	y;

	x = 'A';
	y = '1';

	printf("(%c) is alphabetic = %d, (%c) isnt alphabtic = %d", 
		x, ft_isalpha(x), y, ft_isalpha(y));
	return (0);
}
