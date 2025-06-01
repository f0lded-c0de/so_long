/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traj_calc_xoy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:16:21 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 08:10:39 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	assign_pixel(t_game *game, t_step_pixel *pxl, int os_x, int os_y)
{
	pxl->cur_x = lroundf(os_x + game->pc->x);
	pxl->cur_y = lroundf(os_y + game->pc->y);
	if (game->pc->spd_x < 0)
		pxl->nxt_x = lroundf(os_x + game->pc->x - 1);
	else
		pxl->nxt_x = lroundf(os_x + game->pc->x + 1);
	pxl->nxt_y = lroundf(os_y + game->pc->y + game->pc->ratio);
	pxl->cur_i = pxl->cur_y / game->tile_height;
	pxl->cur_j = pxl->cur_x / game->tile_width;
	pxl->nxt_i = pxl->nxt_y / game->tile_height;
	pxl->nxt_j = pxl->nxt_x / game->tile_width;
}

static void	process_step(t_game *game, int offset_x, int offset_y)
{
	t_step_pixel	pxl;

	assign_pixel(game, &pxl, offset_x, offset_y);
	if (pxl.cur_y == pxl.nxt_y
		&& game->map->grid[pxl.cur_i][pxl.nxt_j] == '1')
		game->pc->spd_x *= BONK;
	if (pxl.cur_y != pxl.nxt_y)
	{
		if (game->map->grid[pxl.nxt_i][pxl.nxt_j] == '1'
			&& game->map->grid[pxl.cur_i][pxl.nxt_j] != '1'
			&& game->map->grid[pxl.nxt_i][pxl.cur_j] != '1')
		{
			game->pc->spd_x *= BONK;
			game->pc->spd_y *= BONK;
		}
		if (game->map->grid[pxl.cur_i][pxl.nxt_j] == '1')
			game->pc->spd_x *= BONK;
		if (game->map->grid[pxl.nxt_i][pxl.cur_j] == '1')
			game->pc->spd_y *= BONK;
	}
}

static void	process_hurtbox(t_game *game)
{
	process_step(game, IHB_SHIP, IHB_SHIP);
	game->pc->ratio = game->pc->spd_y / ft_fabs(game->pc->spd_x);
	process_step(game, IHB_SHIP, OHB_SHIP);
	game->pc->ratio = game->pc->spd_y / ft_fabs(game->pc->spd_x);
	process_step(game, OHB_SHIP, IHB_SHIP);
	game->pc->ratio = game->pc->spd_y / ft_fabs(game->pc->spd_x);
	process_step(game, OHB_SHIP, OHB_SHIP);
	game->pc->ratio = game->pc->spd_y / ft_fabs(game->pc->spd_x);
}

static void	move_to_next_step(t_game *game)
{
	process_hurtbox(game);
	if (game->pc->spd_x < 0)
		game->pc->x--;
	else
		game->pc->x++;
	game->pc->y += game->pc->ratio;
}

void	traj_calc_x_over_y(t_game *game)
{
	int	old_x;
	int	old_y;
	int	steps;

	game->pc->ratio = game->pc->spd_y / ft_fabs(game->pc->spd_x);
	old_x = lroundf(game->pc->x);
	old_y = lroundf(game->pc->y);
	steps = -1;
	if (lroundf(ft_fabs(game->pc->spd_x * game->delta)) > 0)
	{
		while (++steps < lroundf(ft_fabs(game->pc->spd_x * game->delta)))
		{
			move_to_next_step(game);
			check_collect(game);
		}
	}
	else if (ft_fabs(game->pc->spd_x * game->delta) - ++steps)
	{
		process_hurtbox(game);
		game->pc->x += (game->pc->spd_x * game->delta);
		game->pc->y += (game->pc->spd_y * game->delta);
		check_collect(game);
	}
	game->pc->steps += ft_fabs(lroundf(game->pc->x) - old_x);
	game->pc->steps += ft_fabs(lroundf(game->pc->y) - old_y);
}
