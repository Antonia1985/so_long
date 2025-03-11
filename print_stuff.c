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
}
