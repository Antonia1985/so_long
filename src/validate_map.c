/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:30:06 by apavlopo          #+#    #+#             */
/*   Updated: 2025/03/13 17:30:21 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	check_exits(t_game game)
{
	int	e;
	int	y;
	int	x;

	e = 0;
	y = 0;
	while (y < game.map_height)
	{
		x = 0;
		while (x < game.map_width)
		{
			if (game.map[y][x] == 'E')
				e++;
			x++;
		}
		y++;
	}
	return (e);
}

int	check_players(t_game game)
{
	int	p;
	int	y;
	int	x;

	p = 0;
	y = 0;
	while (y < game.map_height)
	{
		x = 0;
		while (x < game.map_width)
		{
			if (game.map[y][x] == 'P')
				p++;
			x++;
		}
		y++;
	}
	return (p);
}

void	free_copy_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**copy_the_map(t_game game)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = malloc((game.map_height + 1) * sizeof(char *));
	if (!map_copy)
	{
		ft_putstr_fd("Failed to allocate memory for map_copy", 1);
		exit(EXIT_FAILURE);
	}
	while (i < game.map_height)
	{
		map_copy[i] = ft_strdup(game.map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	validate_map(t_game game)
{
	char	**copy_map;
	int		exits;
	int		players;

	copy_map = copy_the_map(game);
	game.collected = 0;
	game.finished = 0;
	game.total_collectibles = count_collectibles(game);
	flood_fill(copy_map, &game, game.player_y, game.player_x);
	free_copy_map(copy_map);
	exits = check_exits(game);
	players = check_players(game);
	if (game.collected < game.total_collectibles || game.total_collectibles == 0
		|| check_exits(game) != 1 || check_players(game) != 1)
	{
		print_errors(&game, exits, players);
	}
}
