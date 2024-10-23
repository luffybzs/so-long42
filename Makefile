# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 15:01:53 by ayarab            #+#    #+#              #
#    Updated: 2024/10/23 19:22:09 by ayarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	get_next_line.c get_next_line_utils.c so_long.c \
		ft_check_map.c ft_parsing1.c fonction.c ft_error.c \
		ft_check_char.c ft_check_valid.c \
					
LIBFT_DIR       = libft/
LIBFT			= $(LIBFT_DIR)libft.a
OBJS			= $(SRCS:.c=.o)

CC				= cc -g3
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= SO_LONG


all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
clean:
				$(RM) $(OBJS)
				make clean -sC $(LIBFT_DIR)

fclean:			clean
				$(RM) $(NAME)
				make fclean -sC $(LIBFT_DIR)

re:				fclean $(NAME)

$(LIBFT): 			
				make -sC $(LIBFT_DIR)

%.o : %c
				$(CC) $(CFLAGS) -c $< -o $@
				
  
.PHONY:			all clean fclean re bonus