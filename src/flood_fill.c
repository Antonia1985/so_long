/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:22:19 by apavlopo          #+#    #+#             */
/*   Updated: 2025/03/18 14:22:34 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	flood_fill(char **copy_map, t_game *game, int y, int x)
{
	if (copy_map[y][x] == '1' || copy_map[y][x] == 'V' || y >= game->map_height
		|| x >= game->map_width || y < 0 || x < 0)
		return ;
	if (copy_map[y][x] == 'C')
	{
		game->collected++;
	}
	if (copy_map[y][x] == 'E')
	{
		game->finished++;
	}
	copy_map[y][x] = 'V';
	flood_fill(copy_map, game, y + 1, x);
	flood_fill(copy_map, game, y, x + 1);
	flood_fill(copy_map, game, y - 1, x);
	flood_fill(copy_map, game, y, x - 1);
}
