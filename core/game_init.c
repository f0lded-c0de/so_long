/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 06:31:49 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 07:21:07 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_init(t_game *game)
{
	int	i;
	int	j;

	game->pc = (t_player *)malloc(sizeof(t_player));
	if (!game->pc)
		return (puterr(MLC_ERR), turbo_free(game), 0);
	game->pc->ship[0] = img_init(game, "sprites/ship/space-ship-diag.xpm");
	if (!game->pc->ship[0])
		return (turbo_free(game), 0);
	game->pc->ship[1] = img_init(game, "sprites/ship/space-ship-straight.xpm");
	if (!game->pc->ship[1])
		return (turbo_free(game), 0);
	get_map_pos(game, 'P', &i, &j);
	game->pc->x = j;
	game->pc->y = i;
	game->pc->steps = 0;
	game->pc->spd_x = 0;
	game->pc->spd_y = 0;
	game->pc->x_old_dir = 0;
	game->pc->y_old_dir = -1;
	return (1);
}

void	game_null_init(t_game *game)
{
	int		i;

	game->frame = NULL;
	game->map = NULL;
	game->pc = NULL;
	game->item = NULL;
	game->exit = NULL;
	game->mlx = NULL;
	game->mlx_win = NULL;
	i = -1;
	while (++i < 256)
		game->key[i] = 0;
}

int	game_init(t_game *game, int ac, char **av)
{
	game_null_init(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (puterr(MLX_ERR), turbo_free(game), 0);
	put_img_funcs_init(game);
	if (!map_init(game, ac, av))
		return (0);
	game->frame = win_img_init(game);
	if (!game->frame)
		return (puterr(MLC_ERR), turbo_free(game), 0);
	game->mlx_win = mlx_new_window(game->mlx,
			game->frame->width, game->frame->height, "so_long");
	if (!game->mlx_win)
		return (puterr(MLX_ERR), turbo_free(game), 0);
	if (!player_init(game))
		return (0);
	game->item = img_init(game, "sprites/collectible.xpm");
	if (!game->item)
		return (turbo_free(game), 0);
	game->exit = img_init(game, "sprites/blackhole.xpm");
	if (!game->exit)
		return (turbo_free(game), 0);
	return (1);
}
