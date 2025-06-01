/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 03:25:55 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 08:16:31 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
// // Standard
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/time.h>
# include <time.h>
# include <math.h>

// // Custom
# include "libft.h"
# include "mlx.h"
# include "parsing.h"
# include "render.h"
# include "gameplay.h"
# include "utils.h"

// Structures
typedef struct s_game {
	void		(*put_img[4])(t_img*, t_img*, int, int);
	t_img		*frame;
	t_map		*map;
	t_player	*pc;
	t_img		*item;
	t_img		*exit;
	void		*mlx;
	void		*mlx_win;
	int			key[256];
	int			tile_width;
	int			tile_height;
	float		delta;
}					t_game;

// Functions
// // game_init.c
int		game_init(t_game *game, int ac, char **av);

#endif
