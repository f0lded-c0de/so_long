/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:13:03 by bsamzun           #+#    #+#             */
/*   Updated: 2024/11/12 23:05:29 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (ft_strlen(dst) >= size)
		len = size;
	else
	{
		len = ft_strlen(dst);
		while (src[i] && (i + len) < (size - 1))
		{
			dst[i + len] = src[i];
			i++;
		}
		dst[i + len] = '\0';
	}
	return (len + ft_strlen(src));
}
