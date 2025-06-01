/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeck_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 03:58:58 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/27 03:59:28 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_over_char(t_char_count *count)
{
	if (count->player == 0)
		return (puterr(L_START_ERR), 0);
	if (count->player > 1)
		return (puterr(M_START_ERR), 0);
	if (count->exit == 0)
		return (puterr(L_EXIT_ERR), 0);
	if (count->exit > 1)
		return (puterr(M_EXIT_ERR), 0);
	if (count->item == 0)
		return (puterr(L_ITEM_ERR), 0);
	return (1);
}

int	check_char(t_map *map, int i, int j, t_char_count *count)
{
	if (map->grid[i][j] != '0' && map->grid[i][j] != '1'
			&& map->grid[i][j] != 'P' && map->grid[i][j] != 'C'
			&& map->grid[i][j] != 'E')
		return (puterr(CHR_ERR), 0);
	if ((!j || !i || j == (map->width -1) || i == (map->height -1))
		&& map->grid[i][j] != '1')
		return (puterr(BOR_ERR), 0);
	if (map->grid[i][j] == 'P')
		count->player++;
	if (map->grid[i][j] == 'E')
		count->exit++;
	if (map->grid[i][j] == 'C')
		count->item++;
	if (i == (map->height - 1))
		return (check_over_char(count));
	return (1);
}

int	check_map(t_map *map, t_char_count *count)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		if ((int)ft_strlen(map->grid[i]) != map->width)
			return (puterr(REC_ERR), 0);
		j = 0;
		while (map->grid[i][j])
		{
			if (!check_char(map, i, j, count))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
