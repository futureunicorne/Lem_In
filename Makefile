# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/07 18:38:35 by hel-hadi          #+#    #+#              #
#    Updated: 2017/03/21 14:37:49 by hel-hadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/
SRC_NAME =	main.c					\
			recup_info.c			\
			parse_info.c			\
			tools_parser.c			\
			tools_parser2.c			\
			sort_list.c				\
			solve.c					\
			tools_sort.c			\
			tools_solve.c			\

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LDFLAGS = -L./libft/
LFT = -lft
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ) $(INC_PATH)
	make -C libft fclean && make -C libft
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	$(CC) -I$(INC_PATH) -c $(SRC)
	$(CC) $(OBJ_NAME) -L./libft/ -lft -o $(NAME)
	@rm $(OBJ_NAME)
	@echo "\033[36m === Creation de l'executable Lem-In ===\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I$(INC_PATH) -o $@ -c $<

clean:
	@make clean -C libft/
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ_NAME)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31m === Suppression des fichiers objets===\033[0m"

fclean: clean fcleanlib
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[31m === Suppression du fichier executable===\033[0m"

fcleanlib:
	@make fclean -C ./libft/

re : fclean all
	@echo "\033[35m === Renouvellement executable ====\033[0m"

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY : all clean fclean re

