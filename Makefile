# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcase <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 11:31:10 by tcase             #+#    #+#              #
#    Updated: 2019/06/01 21:10:48 by tcase            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap.a

CC=gcc
FLAGS= -Wall -Werror -Wextra

SRC_DIR=./src
LIB_DIR=./libft
OBJ_DIR=./obj

SRC_NAME=move_stk.c checks.c stk_functions.c mark_stk.c \
		 push_rot.c push_rrot.c push_push.c push_sx.c \
		 move_unsorted.c move_back.c comp_steps.c cleanup.c \
		 list_index_functions.c fill_stk.c
PSH=$(OBJ_DIR)/push_swap.o
CHK=$(OBJ_DIR)/checker.o

OBJ_NAME=$(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))

INC = -I ./includes -I $(LIB_DIR)/includes

all: $(NAME)

$(NAME) : $(OBJ) $(PSH) $(CHK)
	@make -C $(LIB_DIR)
	@$(CC) -o push_swap $(PSH) $(OBJ) -L $(LIB_DIR) -lft $(INC)
	@$(CC) -o checker $(CHK) $(OBJ) -L $(LIB_DIR) -lft $(INC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -o $@ -c $< 
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

clean:
		@rm -f $(OBJ) $(PSH) $(CHK) 

fclean: clean
		@make fclean -C $(LIB_DIR)
		@rm -f checker push_swap

re:	fclean all
