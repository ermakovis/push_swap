# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcase <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 11:31:10 by tcase             #+#    #+#              #
#    Updated: 2019/05/25 21:46:59 by tcase            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap.a

CC=gcc
FLAGS= -Wall -Werror -Wextra

SRC_DIR=./src
LIB_DIR=./libft
INC_DIR=./includes
OBJ_DIR =./obj

SRC_NAME=move_stk.c checks.c stk_functions.c mark_stk.c \
		 push_rot.c push_rrot.c push_push.c push_sx.c \
		 move_unsorted.c
LIB_NAME=ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
		 ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
		 ft_lstnew.c ft_memalloc.c ft_memccpy.c \
		 ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
		 ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
		 ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
		 ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
		 ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
		 ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
		 ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
		 ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
		 ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
		 ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
		 ft_toupper.c ft_lstdelone.c ft_lstdel.c \
		 ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstsize.c \
		 ft_strclen.c ft_nbrlen.c ft_strtoupper.c ft_swap.c \
		 ft_power.c get_next_line.c 

INC_NAME=push_swap.h
OBJ_NAME=$(SRC_NAME:.c=.o)
LBO_NAME=$(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_DIR)/, $(LIB_NAME))
INC = $(addprefix $(INC_DIR)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
LBO = $(addprefix $(OBJ_DIR)/, $(LBO_NAME))

all: $(NAME)

$(NAME) : $(LBO) $(OBJ)
	ar rc $(NAME) $(LBO) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	$(CC) -o $@ -c $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -o $@ -c $<

clean:
		rm -f $(OBJ) $(LBO) 

fclean: clean
		rm -f $(NAME)

check: all ./src/checker.c
	gcc -o checker ./src/checker.c $(NAME) 

push: all
	gcc -o push_swap ./src/push_swap.c $(NAME) && ./push_swap 3 2 1 0

norme:
	norminette $(SRC) $(LIB) $(INC)

re:	fclean all
