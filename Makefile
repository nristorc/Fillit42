# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 12:44:05 by bvigne            #+#    #+#              #
#    Updated: 2017/12/04 11:31:00 by bvigne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAG = -Wall -Wextra -Werror
SRC = capture.c fill_map.c fill_tetri.c main.c new_map.c save_tetri.c \
	test_capture.c
OBJ = $(SRC:.c=.o)
LIB = Libft/libft.a
OPTION = -c -include fillit.h

all: $(NAME)

$(NAME): $(OBJ)
		@$(MAKE) -C ./Libft/ MAKEFLAGS=
		@gcc $(FLAG) $(SRC) $(OPTION)
		@gcc $(OBJ) $(LIB) -o $(NAME)

clean:
		@$(MAKE) clean -C ./Libft/
		@rm -rf $(OBJ)

fclean: clean
		@$(MAKE) fclean -C ./Libft/
		@rm -rf $(NAME)

re: fclean all
