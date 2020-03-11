# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseema <lseema@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/23 20:51:35 by lseema            #+#    #+#              #
#    Updated: 2020/02/23 20:55:35 by lseema           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAG = -Wall -Werror -Wextra -O3
SRC = fractol.c fractals.c draw.c color.c events.c mouse_events.c utils.c
INCLUDE = ./includes
SRO = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(SRO)
	make -C ./libft/
	$(CC) $(FLAG) -I$(INCLUDE) $(SRC) -lmlx -framework OpenGL -framework Appkit\
	 ./libft/libft.a -o $(NAME)

%.o: %.c ./includes/fractol.h
	$(CC) $(FLAG) -c -o $@ $<

clean:
	make -C libft/ clean
	rm -f $(SRO)

fclean: clean
	make -C libft/ fclean
	rm -Rf $(NAME)

re: fclean all
	