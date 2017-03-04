# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 09:17:24 by hel-hadi          #+#    #+#              #
#    Updated: 2017/01/24 11:52:21 by hel-hadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PREF = ./srcs/
HEADER = ./include/
SRCS = 	ft_atoi.c						\
		ft_bzero.c						\
		ft_count_len.c					\
		ft_count_num.c					\
		ft_count_words.c				\
		ft_del_elem.c					\
		ft_free_lst.c					\
		ft_get_elem.c					\
		ft_init_lst.c					\
		ft_isalnum.c					\
		ft_isalpha.c					\
		ft_isascii.c					\
		ft_isdigit.c					\
		ft_isprint.c					\
		ft_itoa.c						\
		ft_len_space_out.c				\
		ft_lstadd.c						\
		ft_lstdel.c						\
		ft_lstdelone.c					\
		ft_lstiter.c					\
		ft_lstmap.c						\
		ft_lstnew.c						\
		ft_memalloc.c					\
		ft_memccpy.c					\
		ft_memchr.c						\
		ft_memcmp.c						\
		ft_memcpy.c						\
		ft_memdel.c						\
		ft_memmove.c					\
		ft_memset.c						\
		ft_memset_base.c				\
		ft_print_lst.c					\
		ft_putchar.c					\
		ft_putchar_fd.c					\
		ft_putendl.c					\
		ft_putendl_fd.c					\
		ft_putnbr.c						\
		ft_putnbr_fd.c					\
		ft_putstr.c						\
		ft_putstr_fd.c					\
		ft_strcat.c						\
		ft_strchr.c						\
		ft_strclr.c						\
		ft_strcmp.c						\
		ft_strcpy.c						\
		ft_strdel.c						\
		ft_strdup.c						\
		ft_strequ.c						\
		ft_striter.c					\
		ft_striteri.c					\
		ft_strjoin.c					\
		ft_strlcat.c					\
		ft_strlen.c						\
		ft_strmap.c						\
		ft_strmapi.c					\
		ft_strncat.c					\
		ft_strnchr.c					\
		ft_strncmp.c					\
		ft_strncpy.c					\
		ft_strnequ.c					\
		ft_strnew.c						\
		ft_strnstr.c					\
		ft_strrchr.c					\
		ft_strsplit.c					\
		ft_strstr.c						\
		ft_strsub.c						\
		ft_strsub_b.c					\
		ft_strtrim.c					\
		ft_tolower.c					\
		ft_toupper.c					\

OBJ = $(SRC:.c=.o)
OBJ1 = objets/*.o
CC = gcc
OPT1 = -c
OPT2 = -o

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(OPT1) $(SRCS)
		@mkdir objets
		@mv *.o objets
		ar rc $(NAME) $(OBJ1)
		ranlib $(NAME)
		@rm -rf objets
		@echo "\033[34m === Creation de la libft.a ===\033[0m"


clean	:
	rm -rf objets
	@echo "\033[31m === Suppression des fichiers objets===\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[31m === Suppression du fichier executable===\033[0m"


re: fclean all
	 @echo "\033[35m === Renouvellement Librairie ====\033[0m"

.PHONY: clean fclean re
