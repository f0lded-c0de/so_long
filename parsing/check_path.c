/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 03:09:32 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 06:36:17 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_tile(char **grid_cpy, t_char_count *count, int x, int y)
{
	if (grid_cpy[y][x] == 'C')
		count->item--;
	if (grid_cpy[y][x] == 'E')
		count->exit--;
	grid_cpy[y][x] = '1';
	if (grid_cpy[y][x + 1] && grid_cpy[y][x + 1] != '1')
		check_tile(grid_cpy, count, x + 1, y);
	if (grid_cpy[y + 1] && grid_cpy[y + 1][x] != '1')
		check_tile(grid_cpy, count, x, y + 1);
	if (grid_cpy[y][x - 1] && grid_cpy[y][x - 1] != '1')
		check_tile(grid_cpy, count, x - 1, y);
	if (grid_cpy[y - 1] && grid_cpy[y - 1][x] != '1')
		check_tile(grid_cpy, count, x, y - 1);
}

void	fill_grid(t_map *map, char **grid_cpy)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (map->height))
	{
		j = -1;
		while (++j < map->width)
			grid_cpy[i][j] = map->grid[i][j];
		grid_cpy[i][j] = map->grid[i][j];
	}
}

int	check_path(t_map *map, t_char_count *count)
{
	char	**grid_cpy;
	int		i;
	int		j;

	grid_cpy = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!grid_cpy)
		return (puterr(MLC_ERR), 0);
	i = -1;
	while (++i < (map->height))
	{
		grid_cpy[i] = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!grid_cpy[i])
			return (free_split((char **)grid_cpy), puterr(MLC_ERR), 0);
	}
	grid_cpy[i] = NULL;
	fill_grid(map, grid_cpy);
	i = 0;
	j = 0;
	get_grid_pos(map, 'P', &i, &j);
	check_tile(grid_cpy, count, j, i);
	if (count->exit != 0)
		return (free_split(grid_cpy), puterr(P_EXIT_ERR), 0);
	if (count->item != 0)
		return (free_split(grid_cpy), puterr(P_ITEM_ERR), 0);
	return (free_split((char **)grid_cpy), 1);
}
