/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 03:52:37 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 07:59:37 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

float	get_delta(void)
{
	static struct timeval	last;
	struct timeval			now;
	float					delta;

	gettimeofday(&now, NULL);
	if (last.tv_sec == 0)
		last = now;
	delta = (now.tv_sec - last.tv_sec)
		+ ((now.tv_usec - last.tv_usec) / 1000000.0f);
	last = now;
	return (delta);
}

void	put_ship_to_frame(t_game *game)
{
	int	mod;

	mod = ((game->pc->y_old_dir + 1) * 3 + (game->pc->x_old_dir + 1)) % 2;
	if (game->pc->y_old_dir == -1 && game->pc->x_old_dir != 1)
		game->put_img[0](game->frame,
			game->pc->ship[mod],
			lroundf(game->pc->x), lroundf(game->pc->y));
	if (game->pc->y_old_dir != 1 && game->pc->x_old_dir == 1)
		game->put_img[1](game->frame,
			game->pc->ship[mod],
			lroundf(game->pc->x),
			lroundf(game->pc->y));
	if (game->pc->y_old_dir == 1 && game->pc->x_old_dir != -1)
		game->put_img[2](game->frame,
			game->pc->ship[mod],
			lroundf(game->pc->x),
			lroundf(game->pc->y));
	if (game->pc->y_old_dir != -1 && game->pc->x_old_dir == -1)
		game->put_img[3](game->frame,
			game->pc->ship[mod],
			lroundf(game->pc->x),
			lroundf(game->pc->y));
}

int	frame_update(t_game *game)
{
	game->delta = get_delta();
	game->put_img[0](game->frame, game->map->bkgd, 0, 0);
	player_update(game);
	if (!collectibles_update(game))
	{
		exit_update(game);
		if (is_on_exit(game, game->pc->x + IHB_SHIP, game->pc->y + IHB_SHIP)
			|| is_on_exit(game, game->pc->x + OHB_SHIP, game->pc->y + IHB_SHIP)
			|| is_on_exit(game, game->pc->x + IHB_SHIP, game->pc->y + OHB_SHIP)
			|| is_on_exit(game, game->pc->x + OHB_SHIP, game->pc->y + OHB_SHIP))
		{
			turbo_free(game);
			exit(0);
		}
	}
	put_ship_to_frame(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->frame->img, 0, 0);
	return (0);
}
