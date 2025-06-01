/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 06:10:02 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 07:10:24 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_update(t_game *game)
{
	int	x;
	int	y;

	get_map_pos(game, 'E', &y, &x);
	game->put_img[0](game->frame, game->exit, x, y);
}

int	is_on_exit(t_game *game, int x, int y)
{
	int	exit_x;
	int	exit_y;

	get_map_pos(game, 'E', &exit_y, &exit_x);
	exit_x += 9;
	exit_y += 9;
	if (x >= exit_x && x <= (exit_x + 13)
		&& y >= exit_y && y <= (exit_y + 13))
		return (1);
	return (0);
}
