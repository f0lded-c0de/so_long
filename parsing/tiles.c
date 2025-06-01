/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:32:55 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 07:48:22 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tiles_null_init(t_background *tiles)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 4)
			tiles->space[i][j++] = NULL;
		i++;
	}
	i = 0;
	while (i < 4)
		tiles->rock[i++] = NULL;
	tiles->border = NULL;
	tiles->corner = NULL;
}

int	space_create_imgs(t_game *game, t_background *tiles)
{
	char	*buffer;
	char	*quarter[4];
	int		i;
	int		j;

	quarter[0] = "/top-left.xpm";
	quarter[1] = "/top-right.xpm";
	quarter[2] = "/bot-left.xpm";
	quarter[3] = "/bot-right.xpm";
	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 4)
		{
			buffer = ft_strjoin("sprites/space/", quarter[j], i + 48);
			if (!buffer)
				return (0);
			tiles->space[i][j] = img_init(game, buffer);
			free(buffer);
			if (!tiles->space[i][j])
				return (0);
		}
	}
	return (1);
}

int	rock_create_imgs(t_game *game, t_background *tiles)
{
	char	*quarter[4];
	int		i;

	quarter[0] = "sprites/alt-rock/alt-rock-tile-top-left.xpm";
	quarter[1] = "sprites/alt-rock/alt-rock-tile-top-right.xpm";
	quarter[2] = "sprites/alt-rock/alt-rock-tile-bot-left.xpm";
	quarter[3] = "sprites/alt-rock/alt-rock-tile-bot-right.xpm";
	i = 0;
	while (i < 4)
	{
		tiles->rock[i] = img_init(game, quarter[i]);
		if (!tiles->rock[i])
			return (i);
		tiles->rock[i]->name = quarter[i];
		i++;
	}
	tiles->border = img_init(game, "sprites/alt-rock/alt-border.xpm");
	if (!tiles->border)
		return (0);
	tiles->corner = img_init(game, "sprites/alt-rock/alt-corner.xpm");
	if (!tiles->corner)
		return (0);
	return (1);
}

int	tiles_init(t_game *game, t_background *tiles)
{
	tiles_null_init(tiles);
	if (!space_create_imgs(game, tiles))
		return (free_tiles(game, tiles), 0);
	if (!rock_create_imgs(game, tiles))
		return (free_tiles(game, tiles), 0);
	return (1);
}
