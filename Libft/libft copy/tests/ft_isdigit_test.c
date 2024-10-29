/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:23:48 by ayousr            #+#    #+#             */
/*   Updated: 2024/10/22 18:54:41 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	main(void)
{
	int		n;
	char	c;

	n = '5';
	c = '#';
	printf("are %i or %c a digit? 1 if true, 0 otherwise\n", n, c);
	printf("%d\n", ft_isdigit(n));
	printf("%d\n", ft_isdigit(c));
	return (0);
}