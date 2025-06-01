/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:25:04 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/27 03:53:34 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

int	ft_split_size(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
}

char	*ft_strcpy_nonl(char *str)
{
	char				*dst;
	unsigned long int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 0 && str[i - 1] == '\n')
	{
		dst = (char *)malloc(sizeof(char) * ft_strlen(str));
		if (!dst)
			return (NULL);
		i = -1;
		while (++i < (ft_strlen(str) - 1))
			dst[i] = str[i];
		dst[i] = '\0';
		free(str);
	}
	else
		dst = str;
	return (dst);
}

char	**ft_split_join(char **split, char *str)
{
	unsigned int	size;
	unsigned int	i;
	char			**dst;

	size = ft_split_size(split);
	dst = (char **)malloc(sizeof(char *) * (size + 2));
	if (!dst)
		return (free_split(split), free(str), NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = ft_strcpy_nonl(split[i]);
		if (!dst[i])
			return (free_split(dst), free(str), NULL);
		i++;
	}
	dst[i] = ft_strcpy_nonl(str);
	if (!dst[i])
		return (free_split(dst), free(str), NULL);
	dst[++i] = NULL;
	if (split)
		free(split);
	return (dst);
}
