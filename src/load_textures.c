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

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w,
			&h);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &w,
			&h);
	game->collect = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm", &w,
			&h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);
	if (!game->exit || !game->wall || !game->floor || !game->player
		|| !game->collect)
	{
		printf("Error\nError: Failed to load texture/es.\n");
		exit(1);
	}
}
