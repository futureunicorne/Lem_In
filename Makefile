# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/07 18:38:35 by hel-hadi          #+#    #+#              #
#    Updated: 2017/03/16 16:35:25 by hel-hadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
PREF = ./srcs/
HEADER = ./includes/
SRCS =	srcs/main.c					\
		srcs/recup_info.c			\
		srcs/parse_info.c			\
		srcs/tools_parser.c			\
		srcs/tools_parser2.c		\
		srcs/sort_list.c			\
		srcs/solve.c				\

OBJ = $(SRCS:.c=.o)
OBJ1 = objets/*.o
FLAGS = -Wall -Werror -Wextra
CC = gcc
OPT1 = -c
OPT2 = -o

all: $(NAME)

$(NAME):
		make -C libft fclean && make -C libft
		$(CC) $(FLAGS) -I$(HEADER) -c $(SRCS)
		mv *.o srcs
		$(CC) $(OBJ) -L./libft/ -lft $(OPT2) $(NAME)
		@echo "\033[36m === Creation de l'executable filler ===\033[0m"


clean	:
	@make clean -C libft/
	@rm -rf objets
	rm -rf srcs/*.o
	@echo "\033[31m === Suppression des fichiers objets===\033[0m"

fclean: clean
	@make fclean -C libft/
	rm -f $(NAME)
	@echo "\033[31m === Suppression du fichier executable===\033[0m"


re: fclean all
	 @echo "\033[35m === Renouvellement executable ====\033[0m"

.PHONY: clean fclean re
