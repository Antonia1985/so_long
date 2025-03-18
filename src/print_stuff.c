/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:04:50 by apavlopo          #+#    #+#             */
/*   Updated: 2025/02/27 16:05:00 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	add_and_print_move(void)
{
	static int	moves_counter = 0;
	char		*c;

	moves_counter++;
	c = ft_itoa(moves_counter);
	ft_putstr_fd("moves: ", 1);
	ft_putstr_fd(c, 1);
	ft_putstr_fd("\n", 1);
	free(c);
}

void	print_errors(t_game *game, int exits, int players)
{
	char	*str_collected;
	char	*str_total_collectibles;
	char	*str_exits;
	char	*str_players;

	str_collected = ft_itoa(game->collected);
	str_total_collectibles = ft_itoa(game->total_collectibles);
	str_exits = ft_itoa(exits);
	str_players = ft_itoa(players);
	ft_putstr_fd("Error\nThe map is invalid.", 1);
	ft_putstr_fd("\nAccessible Collectibles: ", 1);
	ft_putstr_fd(str_collected, 1);
	ft_putstr_fd("\nTotal Collectibles: ", 1);
	ft_putstr_fd(str_total_collectibles, 1);
	ft_putstr_fd("\nExits: ", 1);
	ft_putstr_fd(str_exits, 1);
	ft_putstr_fd("\nPlayers: ", 1);
	ft_putstr_fd(str_players, 1);
	ft_putstr_fd("\n", 1);
	free(str_collected);
	free(str_total_collectibles);
	free(str_exits);
	free(str_players);
	close_game(game);
}
