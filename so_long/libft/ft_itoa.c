/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneyousr <aimaneyousr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:42:27 by ayousr            #+#    #+#             */
/*   Updated: 2025/03/21 02:06:48 by aimaneyousr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		d_len(long nbr);
static char		*preconv_alloc(int len);

char	*ft_itoa(int n)
{
	int		digit_len;
	int		i;
	char	*res;
	long	nbr;

	nbr = n;
	digit_len = d_len(nbr);
	res = preconv_alloc(digit_len);
	if (!res)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = digit_len - 1;
	while (nbr != 0)
	{
		res[i] = ((nbr % 10) + 48);
		nbr /= 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	res[digit_len] = 0;
	return (res);
}

static int	d_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static char	*preconv_alloc(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
}

// int	main(void)
// {
// 	char	*res;
// 	int		n;

// 	n = -1337;
// 	res = ft_itoa(n);
// 	printf("%s\n", res);
// 	free (res);
// 	return (0);
// }
