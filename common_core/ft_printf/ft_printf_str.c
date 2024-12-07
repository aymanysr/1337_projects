/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:51:54 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/24 11:26:37 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(va_list val)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(val, char *);
	if (!s)
		s = "(null)";
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
