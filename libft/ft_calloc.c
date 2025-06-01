/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:22:21 by bsamzun           #+#    #+#             */
/*   Updated: 2024/11/17 13:23:18 by bsamzun          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	total_bytes;

	total_bytes = nmemb * size;
	res = malloc(total_bytes);
	if (!res)
		return (NULL);
	ft_bzero(res, total_bytes);
	return (res);
}
