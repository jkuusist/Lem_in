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

SRCS = main.c 

OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
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
