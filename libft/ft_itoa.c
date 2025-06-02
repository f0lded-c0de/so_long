/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:31:22 by bsamzun           #+#    #+#             */
/*   Updated: 2024/11/18 17:15:58 by bsamzun          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	how_long(int n)
{
	int	c;

	c = 1;
	if (n < 0)
		c++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		c++;
	}
	return (c);
}

static void	assign_nb(char *str, int n, int i)
{
	while (i >= 0)
	{
		if (n < 0)
			str[i] = -(n % 10) + 48;
		else
			str[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = how_long(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = 0;
	if (n < 0)
	{
		str[0] = '-';
		assign_nb(str + 1, n, len - 2);
	}
	else
		assign_nb(str, n, len - 1);
	return (str);
}
