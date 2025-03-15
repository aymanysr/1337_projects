/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:58:33 by ayousr            #+#    #+#             */
/*   Updated: 2025/02/07 16:31:28 by aimaneyousr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_match_conv
{
	char	*specifier;
	int		(*func_pointer)(va_list);
}				t_match_conv;

typedef struct s_print
{
	va_list			args;
	t_match_conv	*spcfrs_arr;
	const char		*str;
	int				i;
	int				spcfrs_count;
	int				output_len;
}				t_print;

int		ft_printf_strlen(char *str, int i);
int		ft_putchar(char c);

int		ft_printf(const char *str, ...);
int		ft_printf_char(va_list val);
int		ft_printf_str(va_list val);
int		ft_printf_pointer(va_list val);
int		ft_printf_int(va_list val);
int		ft_printf_uint(va_list val);
int		ft_printf_hex(va_list val);
int		ft_printf_hex_upper(va_list val);
int		ft_printf_percent(va_list val);

#endif