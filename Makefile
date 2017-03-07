# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/07 18:38:35 by hel-hadi          #+#    #+#              #
#    Updated: 2017/03/07 18:38:55 by hel-hadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ljoly.filler
SRCS = main.c filler.c tactics.c check_and_set.c
FLAGS = -Wall -Werror -Wextra
LIBFT = -C ./libft/
HEADER = -I/includes
OBJ = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))
OBJ_PATH = ./obj/
SRCS_PATH = ./srcs/

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	@make $(LIBFT)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L./libft -lft
	@echo "$(GREEN)[✓]$(NC) Executable $(NAME) ready!"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -I./libft $(HEADER) -o $@ -c $<
	@echo "$(GREEN)[✓]$(NC) Compiling objects..."

clean:
	@make $(LIBFT) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[-]$(NC) Objects cleaned..."

fclean: clean
	@rm -f libft/libft.a
	@rm -f $(NAME)
	@echo "$(RED)[-]$(NC) Executable $(NAME) cleaned..."

re: fclean all

.PHONY: $(NAME) all clean fclean re
