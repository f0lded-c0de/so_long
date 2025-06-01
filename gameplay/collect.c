/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:41:47 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 08:11:54 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_collectible(t_game *game, int x, int y)
{
	if (game->map->grid[y / game->tile_height][x / game->tile_width] == 'C'
		&& (x % game->tile_width) >= IHB_ITEM
		&& (x % game->tile_width) <= OHB_ITEM
		&& (y % game->tile_height) >= IHB_ITEM
		&& (y % game->tile_height) <= OHB_ITEM)
		game->map->grid[y / game->tile_height][x / game->tile_width] = '0';
}

void	check_collect(t_game *game)
{
	is_collectible(game,
		lroundf(game->pc->x) + IHB_SHIP,
		lroundf(game->pc->y) + IHB_SHIP);
	is_collectible(game,
		lroundf(game->pc->x) + IHB_SHIP,
		lroundf(game->pc->y) + OHB_SHIP);
	is_collectible(game,
		lroundf(game->pc->x) + OHB_SHIP,
		lroundf(game->pc->y) + IHB_SHIP);
	is_collectible(game,
		lroundf(game->pc->x) + OHB_SHIP,
		lroundf(game->pc->y) + OHB_SHIP);
}

int	collectibles_update(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	count;

	i = 0;
	count = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->grid[i][j] == 'C')
			{
				x = j * game->tile_width;
				y = i * game->tile_height;
				game->put_img[0](game->frame, game->item, x, y);
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}
