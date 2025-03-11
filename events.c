/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:57:28 by apavlopo          #+#    #+#             */
/*   Updated: 2025/02/27 15:57:38 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	handle_expose(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	return (0);
}

int	handle_resize(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

static void	move_player(t_game *game, int new_y, int new_x)
{
	if (game->map[new_y][new_x] == '1' || (game->map[new_y][new_x] == 'E'
			&& game->total_collectibles > game->collected))
		return ;
	if (game->map[new_y][new_x] == 'E'
		&& game->total_collectibles == game->collected)
	{
		game->finished = 1;
		ft_putstr_fd("Finish!", 1);
		ft_putstr_fd("\n", 1);
		exit(0);
	}
	else if (game->map[new_y][new_x] == 'C')
	{
        game->collected++;
        char		*coll;
		coll = ft_itoa(game->collected);
		ft_putstr_fd("collected = ", 1);
		ft_putstr_fd(coll, 1);
		ft_putstr_fd("\n", 1);
        free(coll);
    }
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	add_and_print_move();
	mlx_clear_window(game->mlx, game->win);
}

int	handle_key(int key, t_game *game)
{
	if (key == XK_Escape) // 65307)
	{
		close_game(game);
	}
	else if (key == XK_W || key == XK_w || key == XK_Up)
	{
		move_player(game, game->player_y - 1, game->player_x);
	}
	else if (key == XK_S || key == XK_s || key == XK_Down)
	{
		move_player(game, game->player_y + 1, game->player_x);
	}
	else if (key == XK_A || key == XK_a || key == XK_Left)
	{
		move_player(game, game->player_y, game->player_x - 1);
	}
	else if (key == XK_D || key == XK_d || key == XK_Right)
	{
		move_player(game, game->player_y, game->player_x + 1);
	}
	render_map(game);
	return (0);
}