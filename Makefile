# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 16:06:22 by apavlopo          #+#    #+#              #
#    Updated: 2025/02/27 16:06:55 by apavlopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
cc = cc
CFLAGS =  -Wall -Wextra -Werror -g -O0 -I./include -I./minilibx-linux -I./get_next_line -I./libft/include -I/usr/include/X11
C1FLAGS =  -L./minilibx-linux -lmlx -lXext -lX11 -lm

LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a
GNL_DIR = get_next_line/
GNL = $(GNL_DIR)libgnl.a

SRC = src/main.c src/events.c src/map.c src/load_textures.c \
		src/print_stuff.c src/initialize_game.c src/validate_map.c \
		src/flood_fill.c src/initialize_map.c
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(MINILIBX) $(GNL) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(MINILIBX):
	$(MAKE) -C minilibx-linux

$(GNL):
	$(MAKE) -C $(GNL_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX) $(GNL)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) $(GNL) -o $(NAME) $(C1FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C minilibx-linux clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C libft clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C minilibx-linux clean
	$(MAKE) -C $(GNL_DIR) fclean
	$(MAKE) -C libft fclean

re:	fclean all

.PHONY: all clean fclean re
