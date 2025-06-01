/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traj_calc_yox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:27:50 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 08:11:18 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	assign_pixel(t_game *game, t_step_pixel *pxl, int os_x, int os_y)
{
	pxl->cur_x = lroundf(os_x + game->pc->x);
	pxl->cur_y = lroundf(os_y + game->pc->y);
	pxl->nxt_x = lroundf(os_x + game->pc->x + game->pc->ratio);
	if (game->pc->spd_y < 0)
		pxl->nxt_y = lroundf(os_y + game->pc->y - 1);
	else
		pxl->nxt_y = lroundf(os_y + game->pc->y + 1);
	pxl->cur_i = pxl->cur_y / game->tile_height;
	pxl->cur_j = pxl->cur_x / game->tile_width;
	pxl->nxt_i = pxl->nxt_y / game->tile_height;
	pxl->nxt_j = pxl->nxt_x / game->tile_width;
}

static void	process_step(t_game *game, int offset_x, int offset_y)
{
	t_step_pixel	pxl;

	assign_pixel(game, &pxl, offset_x, offset_y);
	if (pxl.cur_x == pxl.nxt_x
		&& game->map->grid[pxl.nxt_i][pxl.cur_j] == '1')
		game->pc->spd_y *= BONK;
	if (pxl.cur_x != pxl.nxt_x)
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
	process_step(game, 11, 11);
	game->pc->ratio = game->pc->spd_x / ft_fabs(game->pc->spd_y);
	process_step(game, 11, 21);
	game->pc->ratio = game->pc->spd_x / ft_fabs(game->pc->spd_y);
	process_step(game, 21, 11);
	game->pc->ratio = game->pc->spd_x / ft_fabs(game->pc->spd_y);
	process_step(game, 21, 21);
	game->pc->ratio = game->pc->spd_x / ft_fabs(game->pc->spd_y);
}

static void	move_to_next_step(t_game *game)
{
	process_hurtbox(game);
	if (game->pc->spd_y < 0)
		game->pc->y--;
	else
		game->pc->y++;
	game->pc->x += game->pc->ratio;
}

void	traj_calc_y_over_x(t_game *game)
{
	int	old_x;
	int	old_y;
	int	steps;

	game->pc->ratio = game->pc->spd_x / ft_fabs(game->pc->spd_y);
	old_x = lroundf(game->pc->x);
	old_y = lroundf(game->pc->y);
	steps = -1;
	if (lroundf(ft_fabs(game->pc->spd_y * game->delta)) > 0)
	{
		while (++steps < lroundf(ft_fabs(game->pc->spd_y * game->delta)))
		{
			move_to_next_step(game);
			check_collect(game);
		}
	}
	else if (ft_fabs(game->pc->spd_y * game->delta) - ++steps)
	{
		process_hurtbox(game);
		game->pc->y += (game->pc->spd_y * game->delta);
		game->pc->x += (game->pc->spd_x * game->delta);
		check_collect(game);
	}
	game->pc->steps += ft_fabs(lroundf(game->pc->x) - old_x);
	game->pc->steps += ft_fabs(lroundf(game->pc->y) - old_y);
}
