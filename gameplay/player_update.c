/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 05:27:41 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 08:15:06 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	direction_update(t_game *game)
{
	game->pc->x_dir = 0;
	game->pc->y_dir = 0;
	if (game->key[KEY_W])
		game->pc->y_dir--;
	if (game->key[KEY_A])
		game->pc->x_dir--;
	if (game->key[KEY_S])
		game->pc->y_dir++;
	if (game->key[KEY_D])
		game->pc->x_dir++;
	if (game->pc->x_dir != 0 || game->pc->y_dir != 0)
	{
		game->pc->x_old_dir = game->pc->x_dir;
		game->pc->y_old_dir = game->pc->y_dir;
	}
}

void	descel_update(t_game *game)
{
	int	x_dir;
	int	y_dir;

	x_dir = game->pc->x_dir;
	y_dir = game->pc->y_dir;
	if (!x_dir && game->pc->spd_x < DEAD_ZONE
		&& game->pc->spd_x > -DEAD_ZONE
		&& !y_dir && game->pc->spd_y < DEAD_ZONE
		&& game->pc->spd_y > -DEAD_ZONE)
	{
		game->pc->spd_x = 0;
		game->pc->spd_y = 0;
	}
	game->pc->spd_x += (game->pc->spd_x * game->delta) * DESCELERATION;
	game->pc->spd_y += (game->pc->spd_y * game->delta) * DESCELERATION;
}

void	accel_update(t_game *game)
{
	int	x_dir;
	int	y_dir;

	x_dir = game->pc->x_dir;
	y_dir = game->pc->y_dir;
	if (x_dir != 0
		&& (x_dir == y_dir
			|| x_dir == -y_dir))
	{
		game->pc->spd_x += ((ACCELERATION * game->delta) * x_dir) / sqrt(2);
		game->pc->spd_y += ((ACCELERATION * game->delta) * y_dir) / sqrt(2);
	}
	else
	{
		game->pc->spd_x += ((ACCELERATION * game->delta) * x_dir);
		game->pc->spd_y += ((ACCELERATION * game->delta) * y_dir);
	}
}

void	data_update(t_game *game)
{
	char	*buf;

	ft_putstr_fd("\033[2A", 1);
	buf = ft_itoa((int)game->pc->steps);
	if (!buf)
	{
		puterr(MLC_ERR);
		turbo_exit(game);
	}
	ft_putstr_fd("Traveled ", 1);
	ft_putstr_fd(buf, 1);
	ft_putstr_fd(" pixels.\033[K\n", 1);
	free(buf);
	buf = ft_itoa((int)(ft_fabs(game->pc->spd_x) + (ft_fabs(game->pc->spd_x))));
	if (!buf)
	{
		puterr(MLC_ERR);
		turbo_exit(game);
	}
	ft_putstr_fd("Currently at : ", 1);
	ft_putstr_fd(buf, 1);
	ft_putstr_fd(" pixels per second\033[K\n", 1);
	free(buf);
}

void	player_update(t_game *game)
{
	direction_update(game);
	accel_update(game);
	descel_update(game);
	if (game->pc->spd_x != 0 || game->pc->spd_y != 0)
	{
		if (ft_fabs(game->pc->spd_x) > ft_fabs(game->pc->spd_y))
			traj_calc_x_over_y(game);
		else
			traj_calc_y_over_x(game);
	}
	data_update(game);
}
