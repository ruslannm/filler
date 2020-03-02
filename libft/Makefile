# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgero <rgero@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 15:46:56 by rgero             #+#    #+#              #
#    Updated: 2020/03/02 17:30:23 by rgero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = src
SRC_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
	ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
	ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
	ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
	ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
	ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
	ft_toupper.c ft_strsplit_tolst.c get_next_line.c ft_strcjoin.c \
	ft_lstaddback.c

SRC_PRINTF_PATH = ft_printf/src
SRC_PRINTF_NAME = 	ft_check_format.c ft_get_args.c ft_get_arg_cspf.c \
	ft_get_arg_duox.c ft_get_str_dif.c ft_get_str_uoxp.c \
	ft_get_str_f_special_case.c ft_parse_format.c ft_parse_conversion.c \
	ft_parse_fields.c ft_printf.c ft_put_str_di.c ft_put_str_f.c \
	ft_big_number.c ft_conv_bin_fracpart.c ft_conv_bin_intpart.c \
	ft_conv_bin_dec.c ft_roundup.c

SRC =  $(addprefix $(SRC_PATH)/, $(SRC_NAME))
SRC += $(addprefix $(SRC_PRINTF_PATH)/, $(SRC_PRINTF_NAME))

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME += $(SRC_PRINTF_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

HEADER = -I includes -I ft_printf/includes

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c includes/libft.h includes/get_next_line.h
	/bin/mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

$(OBJ_PATH)/%.o : $(SRC_PRINTF_PATH)/%.c ft_printf/includes/ft_printf.h
	/bin/mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

clean:
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
