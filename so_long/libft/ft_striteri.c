/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:21:42 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/10 22:26:42 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		(i++);
	}
}

// void sample_function(unsigned int i, char *c)
// {
//     *c = *c + i;
// }

// int main()
// {
//     char s[] = "abcdef";

//     printf("Original string: %s\n", s);

//     ft_striteri(s, sample_function);

//     printf("Modified string: %s\n", s);

//     return 0;
// }