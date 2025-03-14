/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:34:14 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/24 10:54:03 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(va_list val)
{
	char	c;

	c = va_arg(val, int);
	if (ft_putchar(c) == -1)
		return (-1);
	return (1);
}

// int	ft_putnbr_base_x(va_list val)
// {
// 	int		ret;
// 	char	*set;
// 	int 	base;
// 	unsigned long n;

// 	set = "0123456789abcdef";
// 	base = ft_strlen(set, 0);
// 	ret = 0;
// 	n = va_arg(val, unsigned long);
// 	while (n >= base)
// 	{
// 		ret += ft_putchar(set[(n % base)]);
// 		n /= base;
// 	}
// 	ret += ft_putchar(set[(n % base)]);
// 	return (ret);
// }

// int	ft_putnbr_base_X(unsigned long n)
// {
// 	int		ret;
// 	char	*set;
// 	int 	base;

// 	set = "0123456789ABCDEF";
// 	base = ft_strlen(set, 0);
// 	ret = 0;
// 	if (n >= base)
// 		ret = ret + ft_putnbr_base_X(n / base);
// 	ret = ret + ft_putchar(set[(n % base)]);
// 	return (ret);
// }