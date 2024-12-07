/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:42:30 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/27 16:38:37 by ayousr           ###   ########.fr       */
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

static void	ft_putnbr_pointer(unsigned long nbr, const char *base)
{
	if (nbr >= 16)
	{
		ft_putnbr_pointer(nbr / 16, base);
		ft_putnbr_pointer(nbr % 16, base);
	}
	else
		ft_putchar(base[nbr]);
}

static int	nbr_len_base_pointer(unsigned long nbr)
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

int	ft_printf_pointer(va_list val)
{
	void			*ptr;
	unsigned long	nbr;
	const char		*base = "0123456789abcdef";
	int				output_len;

	ptr = va_arg(val, void *);
	if (!ptr)
		return (write(1, "0x0", 3));
	if (!check_base((char *)base))
		return (-1);
	nbr = (unsigned long)ptr;
	output_len = write(1, "0x", 2);
	if (output_len == -1)
		return (-1);
	ft_putnbr_pointer(nbr, base);
	output_len += nbr_len_base_pointer(nbr);
	return (output_len);
}
