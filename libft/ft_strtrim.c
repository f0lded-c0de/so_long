/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:09:54 by bsamzun           #+#    #+#             */
/*   Updated: 2024/11/14 02:01:38 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		i;
	int		start;
	int		end;

	start = -1;
	end = -1;
	i = -1;
	while (s1[++i])
		if (start == -1 && !is_charset(s1[i], set))
			start = i;
	if (start == -1)
		return (ft_strdup("\0"));
	while (--i >= 0)
		if (end == -1 && !is_charset(s1[i], set))
			end = i;
	dst = (char *)malloc(((end - start) + 2) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, &s1[start], (end - start) + 2);
	return (dst);
}
