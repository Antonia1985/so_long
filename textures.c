/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:05:20 by apavlopo          #+#    #+#             */
/*   Updated: 2025/02/27 16:05:31 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &w, &h);
	if (!game->wall)
		{
		printf("Error\nError: Failed to load wall texture.\n");
		exit(EXIT_FAILURE);
	}

	game->floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &w, &h);
	if (!game->floor)
		{
		printf("Error\nError: Failed to load floor texture.\n");
		exit(EXIT_FAILURE);
	}
	
	game->player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &w,
			&h);
	if (!game->player)
	{
		printf("Error\nError: Failed to load player texture.\n");
		exit(EXIT_FAILURE);
	}

	game->collect = mlx_xpm_file_to_image(game->mlx, "assets/collect.xpm", &w, &h);
	if (!game->collect)
	{
		printf("Error\nError: Failed to load collectible texture.\n");
		exit(EXIT_FAILURE);
	}

	game->exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &w, &h);
	if (!game->exit)
	{
		printf("Error\nError: Failed to load exit texture.\n");
		exit(EXIT_FAILURE);
	}
}
