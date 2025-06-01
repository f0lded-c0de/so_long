/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 04:28:58 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 08:11:34 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEPLAY_H
# define GAMEPLAY_H

// Structures Prototypes
typedef struct s_game		t_game;
typedef struct s_img		t_img;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_background	t_background;

// Structures
typedef struct s_step_pixel {
	int	cur_x;
	int	cur_y;
	int	nxt_x;
	int	nxt_y;
	int	cur_i;
	int	cur_j;
	int	nxt_i;
	int	nxt_j;
}	t_step_pixel;
/* x = j, y = i */

typedef struct s_player {
	t_img			*ship[2];
	float			x;
	float			y;
	long long int	steps;
	float			spd_x;
	float			spd_y;
	float			ratio;
	int				x_old_dir;
	int				y_old_dir;
	int				x_dir;
	int				y_dir;
}					t_player;

// Functions
// // frame_update.c
int		frame_update(t_game *game);

// // player_update.c
void	player_update(t_game *game);

// // position_update.c
void	position_update(t_game *game);

// // traj_calc.c
void	traj_calc_y_over_x(t_game *game);
void	traj_calc_x_over_y(t_game *game);

// // collect.c
void	check_collect(t_game *game);
int		collectibles_update(t_game *game);

// // exit.c
void	exit_update(t_game *game);
int		is_on_exit(t_game *game, int x, int y);

// // handles.c
int		key_press_handle(int keycode, t_game *game);
int		key_release_handle(int keycode, t_game *game);
int		win_close_handle(t_game *game);
void	gameplay_loop(t_game *game);

// Macros
// // Keycodes
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

// // Movement
# define BONK			-0.8f
# define ACCELERATION	300
# define DESCELERATION	-1.5f
# define DEAD_ZONE		15

// // Hitbox
# define IHB_SHIP	11
# define OHB_SHIP	20
# define IHB_ITEM	8
# define OHB_ITEM	23

#endif
