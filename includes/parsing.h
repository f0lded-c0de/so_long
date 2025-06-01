/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 03:05:47 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 07:34:48 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

// Structures Prototypes
typedef struct s_game		t_game;
typedef struct s_img		t_img;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_background	t_background;

// Structures
typedef struct s_map {
	char	**grid;
	t_img	*bkgd;
	int		width;
	int		height;
}			t_map;

typedef struct s_char_count {
	int	player;
	int	exit;
	int	item;
}		t_char_count;

typedef struct s_background {
	t_img	*space[10][4];
	t_img	*rock[4];
	t_img	*border;
	t_img	*corner;
}			t_background;

// Functions
// // parser.c
int		map_init(t_game *game, int ac, char **av);
void	free_map(t_map *map, void *mlx);

// // check_map.c
int		check_map(t_map *map, t_char_count *count);

// // check_path.c
int		check_path(t_map *map, t_char_count *count);

// // get_pos.c
void	get_map_pos(t_game *game, char c, int *i, int *j);
void	get_grid_pos(t_map *map, char c, int *i, int *j);

// // tiles.c
int		tiles_init(t_game *game, t_background *tiles);

// // fill_background.c
void	fill_background(t_game *game, t_background *tiles);

// // ft_split_join.c
char	**ft_split_join(char **split, char *str);
int		ft_split_size(char **split);
void	free_split(char **split);

// // get_next_line.c
char	*get_next_line(int fd);

// Macros
// // GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

#endif
