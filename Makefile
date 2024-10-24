# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 15:01:53 by ayarab            #+#    #+#              #
#    Updated: 2024/10/24 19:58:29 by ayarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRCS = $(addprefix src/,  so_long.c get_next_line.c get_next_line_utils.c ft_check_map.c ft_check_valid.c ft_check_char.c ft_parsing1.c ft_fonction.c ft_open_win.c ft_init_image.c )

INCLUDES = ./includes -I ./libft/includes/

LIBFT = libft.a
LIB_DIR = ./libft
MINI_LIBX_DIR = ./minilibx-linux
MINI_LIBX = libmlx.a
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

NAME = so_long

all : $(MINI_LIBX) $(LIBFT) $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c  $< -o $@ 

$(LIBFT):
	make -C ./libft

$(MINI_LIBX) :
	make -C $(MINI_LIBX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES)  $(OBJS) -o $(NAME) -L$(LIB_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext

clean:
	rm -f $(OBJS)
	make clean -C ./libft
	make clean -C $(MINI_LIBX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re