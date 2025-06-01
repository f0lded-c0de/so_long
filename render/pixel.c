/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:33:32 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/27 04:26:38 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pxl_to_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll) + (x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pxl(t_img	*img, int x, int y)
{
	return (*(int *)(img->addr + (y * img->ll) + (x * (img->bpp / 8))));
}
