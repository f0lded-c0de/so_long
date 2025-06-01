/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:25:10 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 07:31:25 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile_to_background(t_game *game, t_img *tile[4], int x, int y)
{
	int	pixel_x;
	int	pixel_y;
	int	index;

	pixel_x = x * game->tile_width;
	pixel_y = y * game->tile_height;
	index = ((y % 2) << 1) | x % 2;
	game->put_img[0](game->map->bkgd, tile[index], pixel_x, pixel_y);
}

void	assign_walls(t_game *game, int walls[4], int x, int y)
{
	walls[0] = (y == 0 || game->map->grid[y - 1][x] != '1');
	walls[1] = (x == (game->map->width - 1)
			|| game->map->grid[y][x + 1] != '1');
	walls[2] = (y == (game->map->height - 1)
			|| game->map->grid[y + 1][x] != '1');
	walls[3] = (x == 0 || game->map->grid[y][x - 1] != '1');
}
/* walls is an array storing the information about which bordering
 * tiles are also walls
 * 1 if it's a wall, 0 if it's not
 * Its respective directions are as followed :
 * 0 = top,
 * 1 = right,
 * 2 = bot,
 * 3 = left */

void	put_wall_to_background(t_game *game, t_background *tiles, int x, int y)
{
	int	walls[4];
	int	pxl_x;
	int	pxl_y;
	int	i;

	pxl_x = x * game->tile_width;
	pxl_y = y * game->tile_height;
	put_tile_to_background(game, tiles->rock, x, y);
	assign_walls(game, walls, x, y);
	i = -1;
	while (++i < 4)
		if (walls[i])
			game->put_img[i](game->map->bkgd, tiles->border, pxl_x, pxl_y);
	i = -1;
	while (++i < 4)
		if (walls[i] && walls[(i + 1) % 4])
			game->put_img[i](game->map->bkgd, tiles->corner, pxl_x, pxl_y);
}

void	fill_background(t_game *game, t_background *tiles)
{
	int	y;
	int	x;

	y = 0;
	srand(time(NULL));
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == '1')
				put_wall_to_background(game, tiles, x, y);
			else
				put_tile_to_background(game, tiles->space[rand() % 10], x, y);
			x++;
		}
		y++;
	}
	free_tiles(game, tiles);
}
