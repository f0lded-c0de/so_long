/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:10:48 by bsamzun           #+#    #+#             */
/*   Updated: 2025/03/17 22:36:24 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, char c)
{
	unsigned int	size;
	char			*dst;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (c)
		size++;
	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
	if (c)
		ft_strlcat(dst, &c, ft_strlen(s1) + 2);
	ft_strlcat(dst, s2, size + 1);
	return (dst);
}
