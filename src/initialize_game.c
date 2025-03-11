/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:30:17 by apavlopo          #+#    #+#             */
/*   Updated: 2025/03/11 15:30:24 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "so_long.h"

void	count_collectibles(t_game *game)
{
	int	x;
	int	y;
	int	counter;

	counter = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
			{
				counter++;
			}
			x++;
		}
		y++;
	}
	game->total_collectibles = counter;
}

void	initial_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_y = y;
				game->player_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	initialize_map(t_game *game, char *filename)
{
	game->map = read_map(filename);
	if (!game->map)
	{
		ft_putstr_fd("Error\nFailed to load the map\n", 1);
		exit(1);
	}
}

void	initialize_game_members(t_game *game)
{
	initial_player_position(game);
	game->collected = 0;
	game->finished = 0;
	count_collectibles(game);
}
