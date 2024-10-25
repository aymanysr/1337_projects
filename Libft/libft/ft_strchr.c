/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneysr <aimaneysr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:49:09 by aimaneysr         #+#    #+#             */
/*   Updated: 2024/10/26 00:52:50 by aimaneysr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    int i;
    
    i = 0;
    while (s[i])
    {
        if (s[i] == c)
        {
            return ((char *)&s[i]);
        }

        i++;
    }
    if (s[i] == '\0')
    {
        return ((char *)&s[i]);
    }
    return (NULL);
}