# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 17:12:19 by sgalasso          #+#    #+#              #
#    Updated: 2018/07/26 19:05:53 by sgalasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = group-asm

SRC = 	srcs/main.c \
		srcs/reader.c \
		srcs/data.c \
		srcs/reader_check_header.c \
		srcs/parser_check_syntax.c \
		srcs/error.c \
		srcs/lines.c \
		srcs/labels.c \
		srcs/file.c \
		srcs/parameters.c \

OBJ = $(SRC:.c=.o)

INCLUDES = includes/

all: lib $(NAME)

$(NAME):	$(OBJ)
	gcc -Wall -Wextra -Werror -o $(NAME) libft/libft.a $(OBJ) -I $(INCLUDES) -g #enlever le -g

lib:
	make -C libft/

%.o: %.c $(INCLUDES)asm.h
	gcc -Wall -Wextra -Werror -o $@ -c $< -I $(INCLUDES)  -g #enlever le -g

clean:
	rm -f $(OBJ) && make -C libft/ clean

fclean:		clean
	rm -f $(NAME) && make -C libft/ fclean

re:			fclean all
