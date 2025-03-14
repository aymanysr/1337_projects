/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:22:05 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/26 18:54:32 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Array of structs, each defining a format specifier
// and a corresponding function that handles that specifier
static t_match_conv	*initialize_specifiers(int *count)
{
	static t_match_conv	specifiers_array[] = {
	{"%c", ft_printf_char}, {"%s", ft_printf_str}, {"%d", ft_printf_int},
	{"%i", ft_printf_int}, {"%u", ft_printf_uint}, {"%x", ft_printf_hex},
	{"%X", ft_printf_hex_upper}, {"%%", ft_printf_percent},
	{"%p", ft_printf_pointer}
	};

	*count = sizeof(specifiers_array) / sizeof(specifiers_array[0]);
	return (specifiers_array);
}

static void	init_printf_counters(t_print *tab)
{
	tab->i = 0;
	tab->output_len = 0;
}

static int	handle_specifier(t_print *tab)
{
	int	j;
	int	res;

	j = tab->spcfrs_count - 1;
	while (j >= 0)
	{
		if (tab->spcfrs_arr[j].specifier[0] == tab->str[tab->i]
			&& tab->spcfrs_arr[j].specifier[1] == tab->str[tab->i + 1])
		{
			tab->i += 2;
			res = tab->spcfrs_arr[j].func_pointer(tab->args);
			if (res >= 0)
				return (res);
			else
				return (-1);
		}
		j--;
	}
	tab->i += 1;
	return (0);
}

static int	process_format(t_print *tab)
{
	int	res;

	res = handle_specifier(tab);
	if (res == -1)
		return (-1);
	tab->output_len += res;
	return (0);
}

int	ft_printf(const char *s, ...)
{
	t_print		tab;

	if (write(1, "", 0) == -1)
		return (-1);
	tab.str = s;
	tab.spcfrs_arr = initialize_specifiers(&tab.spcfrs_count);
	init_printf_counters(&tab);
	va_start(tab.args, s);
	while (tab.str[tab.i])
	{
		if (tab.str[tab.i] == '%')
		{
			if (tab.str[tab.i + 1] == '\0')
				return (0);
			else if (process_format(&tab) == -1)
				return (va_end(tab.args), -1);
		}
		else
			tab.output_len += write(1, &tab.str[tab.i++], 1);
	}
	return (va_end(tab.args), tab.output_len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	len;
// 	len = 57;
// 	// int	*ptr;

// 	// ptr = &len;
// 	// len = ft_printf("Pointer test: %p", ptr);
// 	// printf("\nExpected pointer: %pvdhfghfgh\n", ptr);
// 	// printf("Length returned by ft_printf: %d\n", len);
// 	len = printf("Hello %s World / %p /\n", "Aimane", &len);
// 	printf("\nExpected pointer: %p\n", &len);
// 	printf("length: %d\n", len);
// 	return (0);
// }