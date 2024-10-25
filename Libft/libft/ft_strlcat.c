/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimaneysr <aimaneysr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:16:44 by aimaneysr         #+#    #+#             */
/*   Updated: 2024/10/25 02:15:19 by aimaneysr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t i;
    size_t j;
    size_t s_len;
    size_t d_len;

    i = 0;
    j = 0;
    d_len = strlen(dest);
    s_len = strlen(src);
    while (dest[j] != '\0')
    {
        j++;
    }
    if (size == 0 || size < d_len)
    {
        return (s_len + size);
    }
    while (src[i] != '\0' && i < size - d_len - 1)
    {
        dest[i] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (d_len + s_len); 
}