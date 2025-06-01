/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 04:09:45 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 07:30:06 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// Structures Prototypes
typedef struct s_game		t_game;
typedef struct s_img		t_img;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_background	t_background;

// Structures
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		ed;
	int		width;
	int		height;
	char	*name;
}			t_img;

// Functions
// // img.c
t_img	*img_init(t_game *game, char *sprite);
t_img	*win_img_init(t_game *game);
void	free_img(void *mlx, t_img *img);

// // pixel.c
int		get_pxl(t_img	*img, int x, int y);
void	put_pxl_to_img(t_img *img, int x, int y, int color);

// // put_img_to_img.c
void	put_img_funcs_init(t_game *game);

#endif
