/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 06:16:52 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 06:28:43 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_grid_pos(t_map *map, char c, int *i, int *j)
{
	*i = 0;
	while (*i < map->height)
	{
		*j = 0;
		while (*j < map->width && map->grid[*i][*j] != c)
			(*j)++;
		if (map->grid[*i][*j] == c)
			break ;
		(*i)++;
	}
}

void	get_map_pos(t_game *game, char c, int *i, int *j)
{
	*i = 0;
	while (*i < game->map->height)
	{
		*j = 0;
		while (*j < game->map->width && game->map->grid[*i][*j] != c)
			(*j)++;
		if (game->map->grid[*i][*j] == c)
			break ;
		(*i)++;
	}
	*i *= game->tile_height;
	*j *= game->tile_width;
}
