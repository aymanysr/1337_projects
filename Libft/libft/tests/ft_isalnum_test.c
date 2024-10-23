/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:53:16 by ayousr            #+#    #+#             */
/*   Updated: 2024/10/23 19:58:27 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	main(void)
{
	int	x;
	int	y;

	x = 'A';
	y = 126;

	printf("(%c) is alphanum = %d, (%c) isnt alphanum = %d", 
		x, ft_isalnum(x), y, ft_isalnum(y));
	return (0);
}