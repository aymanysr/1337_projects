/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:00:55 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/11 00:25:07 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 1 && res > 9223372036854775807)
			return (-1);
		if (sign == -1 && res > 9223372036854775807)
			return (0);
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return ((int)res * sign);
}
// int main(void)
// {
// 	char	str[] = "	 -123afs";

// 	printf("mine : %i\n", ft_atoi(str));
// 	printf("lib : %i\n", atoi(str));
// }
