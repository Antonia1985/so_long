/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:09:02 by apavlopo          #+#    #+#             */
/*   Updated: 2025/03/18 17:09:28 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	check_map_shape(int map_height, char **map)
{
	int		y;
	size_t	len;

	y = 0;
	while (y < map_height)
	{
		len = ft_strlen(map[0]);
		if (len != ft_strlen(map[y]))
			return (0);
		y++;
	}
	return (1);
}

int	map_1st_column_height(char **map)
{
	int	x;

	x = 0;
	while (map[x] != NULL)
		x++;
	return (x);
}

int	map_1st_line_width(char **map)
{
	int	x;

	x = 0;
	while (map[0][x] != '\0')
		x++;
	return (x);
}

void	initialize_map(t_game *game, char *filename)
{
	game->map = read_map(filename);
	if (!game->map)
	{
		ft_putstr_fd("Error\nFailed to load the map\n", 1);
		exit(1);
	}
	game->map_height = map_1st_column_height(game->map);
	game->map_width = map_1st_line_width(game->map);
	if (!check_map_shape(game->map_height, game->map))
	{
		ft_putstr_fd("Error\nWrong shape of map\n", 1);
		exit(1);
	}
}
