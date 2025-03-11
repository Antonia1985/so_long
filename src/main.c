/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:02:23 by apavlopo          #+#    #+#             */
/*   Updated: 2025/02/27 16:02:52 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	set_map_width(t_game *game)
{
	int	x;

	x = 0;
	while (game->map[0][x] != '\0')
		x++;
	game->map_width = x;
	return (game->map_width * TS);
}

int	set_map_height(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y] != NULL)
		y++;
	game->map_height = y;
	return (game->map_height * TS);
}

void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nFailed: to initialize MLX/to connect to X Server",
			1);
		return;
	}
}

void	initialize_win(t_game *game)
{
	game->win = mlx_new_window(game->mlx, set_map_width(game),
			set_map_height(game), "Mushroom Game");
	if (!game->win)
	{
		ft_putstr_fd("Error\nError in opening the window\n", 1);
		return;
	}
}

int	main(int ac, char **av)
{
	(void)av;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./so_long <map.ber>\n", 1);
		exit(0);
	}
	t_game game;
	initialize_mlx(&game);
	initialize_map(&game, av[1]);
	initialize_win(&game);
	load_textures(&game);
	mlx_clear_window(game.mlx, game.win);
	render_map(&game);
	initialize_game_members(&game);
	validate_map();
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_hook(game.win, 12, 1L << 15, handle_expose, &game);
	mlx_hook(game.win, 22, 1L << 17, handle_resize, &game);
	mlx_loop(game.mlx);
	return (0);
}
