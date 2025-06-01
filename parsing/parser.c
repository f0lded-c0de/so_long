/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:35:09 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/31 07:49:39 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map, void *mlx)
{
	if (map->grid)
		free_split(map->grid);
	if (map->bkgd && mlx)
		free_img(mlx, map->bkgd);
	free(map);
}

int	background_init(t_game *game)
{
	t_background	*tiles;

	tiles = (t_background *)malloc(sizeof(t_background));
	if (!tiles)
		return (puterr(MLC_ERR), 0);
	if (!tiles_init(game, tiles))
		return (0);
	game->tile_width = tiles->space[0][0]->width;
	game->tile_height = tiles->space[0][0]->height;
	game->map->bkgd = win_img_init(game);
	if (!game->map->bkgd)
		return (free_tiles(game, tiles), 0);
	return (fill_background(game, tiles), 1);
}

t_map	*parse_map(int fd, t_char_count *count)
{
	t_map	*map;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (puterr(EMP_ERR), NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (puterr(MLC_ERR), free(line), NULL);
	map->grid = NULL;
	map->bkgd = NULL;
	while (line)
	{
		map->grid = ft_split_join(map->grid, line);
		if (!map->grid)
			return (free_map(map, NULL), puterr(MLC_ERR), NULL);
		line = get_next_line(fd);
	}
	map->width = ft_strlen(map->grid[0]);
	map->height = ft_split_size(map->grid);
	if (!check_map(map, count) || !check_path(map, count))
		return (free_map(map, NULL), NULL);
	return (map);
}

int	map_init(t_game *game, int ac, char **av)
{
	t_char_count	count;
	int				len;
	int				fd;

	if (ac == 1)
		return (puterr(L_ARG_ERR), turbo_free(game), 0);
	if (ac > 2)
		return (puterr(M_ARG_ERR), turbo_free(game), 0);
	len = ft_strlen(av[1]);
	if (ft_strncmp((av[1] + (len - 4)), ".ber", 5))
		return (puterr(F_NAM_ERR), turbo_free(game), 0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (puterrno(OPN_ERR), turbo_free(game), 0);
	count.item = 0;
	count.exit = 0;
	count.player = 0;
	game->map = parse_map(fd, &count);
	close(fd);
	if (!game->map)
		return (turbo_free(game), 0);
	if (!background_init(game))
		return (turbo_free(game), 0);
	return (1);
}
