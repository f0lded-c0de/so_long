/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:34:30 by bsamzun           #+#    #+#             */
/*   Updated: 2024/11/13 20:13:16 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*buf;

	i = 0;
	buf = NULL;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			buf = (char *)&s[i];
		i++;
	}
	if (s[i] == (unsigned char)c)
		buf = (char *)&s[i];
	return (buf);
}
