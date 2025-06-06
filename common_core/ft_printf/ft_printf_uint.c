/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:14:38 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/24 10:51:29 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base(char *base)
{
	int	i;
	int	j;
	int	base_len;

	base_len = ft_strlen(base, 0);
	if (base_len < 2 || base_len > 10)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	nbr_len_base_u(unsigned int nbr, int base_len)
{
	int	count;

	count = (nbr <= 0);
	while (nbr != 0)
	{
		nbr /= base_len;
		count++;
	}
	return (count);
}

static void	ft_putnbr_base_u(unsigned int nbr, const char *base, int base_len)
{
	if (!check_base((char *)base))
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= (unsigned int)base_len)
	{
		ft_putnbr_base_u(nbr / base_len, base, base_len);
		ft_putnbr_base_u(nbr % base_len, base, base_len);
	}
	else
		ft_putchar(base[nbr]);
}

int	ft_printf_uint(va_list args)
{
	unsigned int	num;
	const char		*base = "0123456789";
	int				base_len;

	base_len = 10;
	num = va_arg(args, int);
	if (!check_base((char *)base))
		return (0);
	ft_putnbr_base_u(num, base, base_len);
	return (nbr_len_base_u(num, base_len));
}
