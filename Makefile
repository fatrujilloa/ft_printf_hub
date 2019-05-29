# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 13:27:24 by ftrujill          #+#    #+#              #
#    Updated: 2019/05/29 14:43:33 by ftrujill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

CC = gcc
#CC_FLAGS = -Wall -Werror -Wextra
CC_FLAGS = 

SRC_PATH = ./srcs/
OBJ_PATH = ./srcs/
INC_PATH = ./inc/
LFT_PATH = ../LibftHub/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(SRC_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = printf.h conversions.h

SRC_NAME = ft_printf.c main.c get_arg.c aux_print.c aux.c conversions_1.c conversions_2.c conversions_3.c

all: $(NAME) $(SRC) $(OBJ)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all
