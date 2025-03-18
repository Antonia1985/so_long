/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:03:24 by apavlopo          #+#    #+#             */
/*   Updated: 2025/02/27 16:04:36 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "so_long.h"

char	**increase_map_size(char **map, int *num_line_ptr)
{
	char	**new_map;

	new_map = ft_realloc(map, sizeof(char *) * (*num_line_ptr), sizeof(char *)
			* (*num_line_ptr) * 2);
	if (!new_map)
	{
		perror("Error\nError reallocating memory for map\n");
		free(map);
		exit(EXIT_FAILURE);
	}
	(*num_line_ptr) *= 2;
	return (new_map);
}

void	fill_the_map(char **map, int num_l, int fd)
{
	char	*line;
	char	*trimmed_line;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line)
		{
			trimmed_line = ft_strtrim(line, "\n\r");
			free(line);
			line = trimmed_line;
		}
		if (i >= num_l - 1)
			map = increase_map_size(map, &num_l);
		map[i] = line;
		i++;
	}
	map[i] = NULL;
}

char	**read_map(char *filename)
{
	int		fd;
	int		num_l;
	char	**map;

	num_l = 100;
	map = malloc(sizeof(char *) * num_l);
	if (!map)
	{
		perror("Error\nError allocating memory for map\n");
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nError opening map file");
		free(map);
		exit(EXIT_FAILURE);
	}
	fill_the_map(map, num_l, fd);
	close(fd);
	return (map);
}

void	render_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				img = game->wall;
			else if (game->map[y][x] == '0')
				img = game->floor;
			else if (game->map[y][x] == 'P')
				img = game->player;
			else if (game->map[y][x] == 'C')
				img = game->collect;
			else if (game->map[y][x] == 'E')
				img = game->exit;
			mlx_put_image_to_window(game->mlx, game->win, img, x * TS, y * TS);
			x++;
		}
		y++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
