/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 04:28:33 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/27 04:31:44 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press_handle(int keycode, t_game *game)
{
	if (keycode < 256)
		game->key[keycode] = 1;
	if (keycode == KEY_ESC)
	{
		turbo_free(game);
		exit(0);
	}
	return (0);
}

int	key_release_handle(int keycode, t_game *game)
{
	if (keycode < 256)
		game->key[keycode] = 0;
	return (0);
}

int	win_close_handle(t_game *game)
{
	turbo_free(game);
	exit(0);
}

void	gameplay_loop(t_game *game)
{
	mlx_hook(game->mlx_win, 2, 1L << 0, key_press_handle, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, key_release_handle, game);
	mlx_hook(game->mlx_win, 17, 1L << 17, win_close_handle, game);
	mlx_loop_hook(game->mlx, frame_update, game);
	mlx_loop(game->mlx);
}
