# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juveron <juveron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 12:13:48 by jvitry            #+#    #+#              #
#    Updated: 2019/05/15 11:19:33 by juveron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
SRC = vec1.c vec2.c mlx.c setting.c hit.c camera.c hit2.c hit3.c couleur.c main.c parseur.c free.c set2.c
OBJ = $(SRC:.c=.o)
CC = cc -g3
FLAGS = -Wall -Werror -Wextra
LIB = -Llibft -lft -lmlx

all : $(NAME)

$(NAME) : $(OBJ)
	@cd libft && make
	@cd minilibx_macos && make
	@$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIB) -framework OpenGL -framework Appkit
	@echo "Compilation termine"

%.o : %.c rtv1.h
	@echo "\033[0;36m\033[1ACompilation de $@\033[0m"
	@$(CC) $(FLAGS) -c $<

clean :
	@rm -rf $(OBJ)
	@cd libft && make clean
	@cd minilibx_macos && make clean
	@echo "\033[1;32mSuppresion des objets termine\033[0m"

fclean : clean
	@rm -rf $(NAME) $(LIB)
	@cd libft && make fclean
	@echo "\033[1;32mSuppresion du binaire\033[0m"

re : fclean all

.PHONY: clean fclean re
