# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 11:35:00 by jkuusist          #+#    #+#              #
#    Updated: 2020/09/10 11:35:00 by jkuusist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

HEDR = 

LIBFT = ./libft

SRCS = create_ant.c create_lem_in.c create_map_link.c create_path.c destroy_lem_in.c find_path.c ft_atoi_error.c handle_error.c handle_input.c handle_link.c handle_num_ants.c handle_room.c has_digit.c main.c make_connections.c move_ants.c

OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra -g
all: $(NAME)

$(NAME):
	make -C $(LIBFT) fclean
	make -C $(LIBFT)
	gcc -c $(FLAGS) $(SRCS)
	gcc -o $(NAME) $(OBJS) $(LIBFT)/libft.a

.PHONY: clean fclean re

clean:
	rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
