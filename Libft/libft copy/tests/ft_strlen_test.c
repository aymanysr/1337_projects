/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:54:47 by ayousr            #+#    #+#             */
/*   Updated: 2024/10/22 19:13:43 by ayousr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	main(void)
{
	const char	*s;

	s = "Hello word!";

	printf("the length of %s is %zu\n",s, ft_strlen(s));
	return (0);
}