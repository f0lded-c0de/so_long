/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:36:10 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 07:34:35 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// Structures Prototypes
typedef struct s_game		t_game;
typedef struct s_img		t_img;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_background	t_background;

// Functions
// // errors.c
void	puterr(char *error);
void	puterrno(char *error);

// // math.c
int		abs(int n);
float	ft_fabs(float f);

// // free.c
void	free_pc(t_game *game);
void	free_tiles(t_game *game, t_background *tiles);
void	turbo_free(t_game *game);
void	turbo_exit(t_game *game);

// Macros
// // Errors
/* Args */
# define L_ARG_ERR "Error\nNot enough arguments."
# define M_ARG_ERR "Error\nToo much arguments."
/* File */
# define F_NAM_ERR "Error\nPlease enter a .ber file for the map."
# define OPN_ERR "Error\nCould not open file: "
# define EMP_ERR "Error\nEmpty file."
/* Sys */
# define MLC_ERR "Error\nMalloc failed."
# define MLX_ERR "Error\nMiniLibX call failed."
/* Format */
/* * * File Check * * */
# define CHR_ERR "Error\nForbidden characters in map."
# define FRM_ERR "Error\nMap file does not fit required format."
/* * * Map Check * * */
# define REC_ERR "Error\nMap not rectangular."
# define BOR_ERR "Error\nMap not surrounded by walls."
# define L_START_ERR "Error\nYou need 1 starting point for the player."
# define M_START_ERR "Error\nToo many starting points for the player. Max 1."
# define L_EXIT_ERR "Error\nYou need 1 exit."
# define M_EXIT_ERR "Error\nToo many exits. Max 1."
# define L_ITEM_ERR "Error\nYou need at least 1 collectible."
/* * * Path Check * * */
# define P_EXIT_ERR "Error\nCannot access the exit from starting point."
# define P_ITEM_ERR "Error\nCannot collect all items."

#endif
