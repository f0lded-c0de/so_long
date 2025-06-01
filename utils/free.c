/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:59:02 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 07:51:29 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_pc(t_game *game)
{
	if (game->pc->ship[0])
		free_img(game->mlx, game->pc->ship[0]);
	if (game->pc->ship[1])
		free_img(game->mlx, game->pc->ship[1]);
	free (game->pc);
}

void	free_tiles(t_game *game, t_background *tiles)
{
	int	i;
	int	j;

	if (tiles)
	{
		i = 0;
		while (i < 10)
		{
			j = 0;
			while (j < 4)
				free_img(game->mlx, tiles->space[i][j++]);
			i++;
		}
		i = 0;
		while (i < 4)
			free_img(game->mlx, tiles->rock[i++]);
		free_img(game->mlx, tiles->border);
		free_img(game->mlx, tiles->corner);
		free(tiles);
	}
}

void	turbo_free(t_game *game)
{
	if (game->frame)
		free_img(game->mlx, game->frame);
	if (game->item)
		free_img(game->mlx, game->item);
	if (game->exit)
		free_img(game->mlx, game->exit);
	if (game->map)
		free_map(game->map, game->mlx);
	if (game->pc)
		free_pc(game);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

void	turbo_exit(t_game *game)
{
	if (game->frame)
		free_img(game->mlx, game->frame);
	if (game->item)
		free_img(game->mlx, game->item);
	if (game->exit)
		free_img(game->mlx, game->exit);
	if (game->map)
		free_map(game->map, game->mlx);
	if (game->pc)
		free_pc(game);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(0);
}
