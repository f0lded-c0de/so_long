/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 04:15:36 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 07:50:38 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(void *mlx, t_img *img)
{
	if (img && img->img)
		mlx_destroy_image(mlx, img->img);
	free(img);
}

t_img	*img_init(t_game *game, char *sprite)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (puterr(MLC_ERR), NULL);
	img->img = mlx_xpm_file_to_image(game->mlx, sprite,
			&img->width, &img->height);
	if (!img->img)
		return (puterr(MLX_ERR), free(img), NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ll, &img->ed);
	img->name = sprite;
	return (img);
}

t_img	*win_img_init(t_game *game)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (puterr(MLC_ERR), NULL);
	img->width = game->tile_width * game->map->width;
	img->height = game->tile_height * game->map->height;
	img->img = mlx_new_image(game->mlx, img->width, img->height);
	if (!img->img)
		return (puterr(MLX_ERR), NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ll, &img->ed);
	return (img);
}
