/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:11:06 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/23 22:05:02 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base(char *base)
{
	int	i;
	int	j;
	int	base_len;

	base_len = ft_strlen(base, 0);
	if (base_len < 2 || base_len > 16)
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

static void	ft_putnbr_hex_upper(unsigned int nbr, const char *base)
{
	if (nbr >= 16)
	{
		ft_putnbr_hex_upper(nbr / 16, base);
		ft_putnbr_hex_upper(nbr % 16, base);
	}
	else
		ft_putchar(base[nbr]);
}

static int	nbr_len_base_hex_upper(long long nbr)
{
	int	count;

	count = (nbr == 0);
	while (nbr != 0)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

int	ft_printf_hex_upper(va_list val)
{
	unsigned int	nbr;
	const char		*base = "0123456789ABCDEF";

	nbr = va_arg(val, unsigned int);
	if (!check_base((char *)base))
		return (0);
	ft_putnbr_hex_upper(nbr, base);
	return (nbr_len_base_hex_upper(nbr));
}
