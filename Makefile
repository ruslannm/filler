# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgero <rgero@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 15:46:56 by rgero             #+#    #+#              #
#    Updated: 2020/02/24 13:14:18 by rgero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rgero.filler

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -g

SRC_PATH = src
SRC_NAME = main.c ft_init.c ft_find_line.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME)) 

INCLUDES_PATH = includes libft/includes libft/ft_printf/includes
INCLUDES = $(addprefix -I, $(INCLUDES_PATH))

LIB_PATH = libft
LIB_NAME = libft.a

.PHONY: all clean fclean re libft

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)
	$(CC) $(OBJ) -L $(LIB_PATH)/ -lft -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@/bin/mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	/bin/rm -rf $(OBJ_PATH)
	make -C $(LIB_PATH) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB_PATH) fclean
	
re: fclean all
