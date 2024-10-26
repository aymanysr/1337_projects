/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneysr <aimaneysr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:10:14 by aimaneysr         #+#    #+#             */
/*   Updated: 2024/10/26 10:58:36 by aimaneysr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i;

    i = ft_strlen(s);
    while (i > 0)
    {
        if (s[i] == c)
        {
            return((char *)&s[i]);
        }
        i--;
    }
    if (s[i] == "\0")
        return ((char *)&s[i]);
    return (NULL);
}