/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 01:38:30 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/27 06:25:38 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_spr_to_img_0(t_img *img, t_img *spr, int x, int y)
{
	int	s_x;
	int	s_y;
	int	color;

	s_y = 0;
	while (s_y < spr->height)
	{
		s_x = 0;
		while (s_x < spr->width)
		{
			color = get_pxl(spr, s_x, s_y);
			if (color != -16777216)
				put_pxl_to_img(img, x + s_x, y + s_y, color);
			s_x++;
		}
		s_y++;
	}
}

void	put_spr_to_img_90(t_img *img, t_img *spr, int x, int y)
{
	int	s_x;
	int	s_y;
	int	color;

	x += (spr->width - 1);
	s_y = 0;
	while (s_y < spr->height)
	{
		s_x = 0;
		while (s_x < spr->width)
		{
			color = get_pxl(spr, s_x, s_y);
			if (color != -16777216)
				put_pxl_to_img(img, x - s_y, y + s_x, color);
			s_x++;
		}
		s_y++;
	}
}

void	put_spr_to_img_180(t_img *img, t_img *spr, int x, int y)
{
	int	s_x;
	int	s_y;
	int	color;

	x += (spr->width - 1);
	y += (spr->height - 1);
	s_y = 0;
	while (s_y < spr->height)
	{
		s_x = 0;
		while (s_x < spr->width)
		{
			color = get_pxl(spr, s_x, s_y);
			if (color != -16777216)
				put_pxl_to_img(img, x - s_x, y - s_y, color);
			s_x++;
		}
		s_y++;
	}
}

void	put_spr_to_img_270(t_img *img, t_img *spr, int x, int y)
{
	int	s_x;
	int	s_y;
	int	color;

	y += (spr->height - 1);
	s_y = 0;
	while (s_y < spr->height)
	{
		s_x = 0;
		while (s_x < spr->width)
		{
			color = get_pxl(spr, s_x, s_y);
			if (color != -16777216)
				put_pxl_to_img(img, x + s_y, y - s_x, color);
			s_x++;
		}
		s_y++;
	}
}

void	put_img_funcs_init(t_game *game)
{
	game->put_img[0] = put_spr_to_img_0;
	game->put_img[1] = put_spr_to_img_90;
	game->put_img[2] = put_spr_to_img_180;
	game->put_img[3] = put_spr_to_img_270;
}
