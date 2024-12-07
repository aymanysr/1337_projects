/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:14:09 by ayousr            #+#    #+#             */
/*   Updated: 2024/11/27 16:40:23 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int				i;
// 	int				len;
// 	int				len2;
// 	unsigned	int	ui;
// 	void			*addr;
// 	char			*str = NULL;

// 	len = ft_printf("OG : Let's try to printf a simple sentence.\n");
// 	len2 = printf("Let's try to printf a simple sentence.\n");
// 	ui = (unsigned int)INT_MAX + 1024;
// 	addr = (void *)0x7ffe637541f0;
// 	ft_printf("MINE : Length:[%d, %i]\n", len2, len2);
// 	printf("Length:[%d, %i]\n", len2, len2);
// 	ft_printf("MINE : Negative:[%d]\n", -762534);
// 	printf("Negative:[%d]\n", -762534);
// 	ft_printf("MINE : Unsigned:[%u]\n", ui);
// 	printf("Unsigned:[%u]\n", ui);
// 	ft_printf("MINE : Unsigned hexadecimal:[%x, %X]\n", ui, ui);
// 	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
// 	ft_printf("MINE : Character:[%c]\n", 'H');
// 	printf("Character:[%c]\n", 'H');
// 	ft_printf("MINE : String:[%s]\n", "I am a string !");
// 	printf("String:[%s]\n", "I am a string !");
// 	ft_printf("MINE : Address:[%p]\n", addr);
// 	printf("Address:[%p]\n", addr);
// 	len = ft_printf("MINE : Percent:[%%]\n");
// 	len2 = printf("Percent:[%%]\n");
// 	ft_printf("MINE : Len:[%d]\n", len2);
// 	printf("Len:[%d]\n", len);
// 	ft_printf("MINE : %s\n", str);
// 	printf("%s\n", str);
// 	len = ft_printf("MINE : %");
// 	len2 = printf("%");
// 	printf("len[%d] == len[%d]\n", len, len2);
// 	len = ft_printf("MINE : %m\n");
// 	len2 = printf("OGOG : %m\n");
// 	printf("len[%d] == len[%d]\n", len, len2);
// 	printf ("\n-------test null-------\n");

// 	ft_printf("MINE : %s",NULL);
// 	printf ("\n%s", NULL);

// 	printf ("\n----test Address----\n");

// 	ft_printf("MINE : %p", NULL);
// 	printf ("\n%p", NULL);

// 	return (0);
// }

// #include "ft_printf.h"
// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	i;
// 	int	len;
// 	int	len2;

// 	len = ft_printf ("hello", NULL);
// 	len2 = ft_printf("\n%p", NULL);
// 	return (0);
// }