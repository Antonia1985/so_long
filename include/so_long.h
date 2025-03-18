/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:49:39 by apavlopo          #+#    #+#             */
/*   Updated: 2025/02/27 15:49:50 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TS 64

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_height;
	int		map_width;
	int		player_x;
	int		player_y;
	int		total_collectibles;
	int		collected;
	int		finished;
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*exit;
}			t_game;

int			close_game(t_game *game);
char		**read_map(char *filename);
void		render_map(t_game *game);
int			handle_key(int key, t_game *game);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void		load_textures(t_game *game);
void		add_and_print_move(void);
void		print_errors(t_game *game, int exits, int players);
int			handle_expose(t_game *game);
int			handle_resize(t_game *game);
int			count_collectibles(t_game game);
int			map_1st_column_height(char **map);
int			map_1st_line_width(char **map);
int			set_map_height(t_game *game);
void		validate_map(t_game game);
void		flood_fill(char **copy_map, t_game *game, int y, int x);
void		initialize_game_members(t_game *game);
void		initial_player_position(t_game *game);
void		initialize_mlx(t_game *game);
void		initialize_map(t_game *game, char *filename);
void		initialize_win(t_game *game);
void		free_map(char **map);
#endif
