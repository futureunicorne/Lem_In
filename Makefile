# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/07 18:38:35 by hel-hadi          #+#    #+#              #
#    Updated: 2017/03/12 11:19:46 by hel-hadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SRCS =	main.c				\
		recup_info.c		\
		parse_info.c		\


CC = gcc
FLAGS = -Wall -Werror -Wextra
HEADER = -I/includes
OBJ = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))
OBJ_PATH = ./objets/
SRCS_PATH = ./srcs/


all: $(NAME)

$(NAME): $(OBJ)
	make -C libft fclean && make -C libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L./libft -lft
	@echo "\033[36m === Creation de l'executable Lem-in ===\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -I./libft $(HEADER) -o $@ -c $<
	@echo "\033[32m === Modification de fichier -- Recompilation ===\033[0m"

clean:
	@make clean -C libft/
	@rm -rf objets
	@rm -rf *.o
	@echo "\033[34m === Suppression des fichiers objets===\033[0m"

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@echo "\033[34m === Suppression du fichier executable===\033[0m"

re: fclean all
	@echo "\033[35m === Renouvellement executable ====\033[0m"

.PHONY: $(NAME) all clean fclean re
