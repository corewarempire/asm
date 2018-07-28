# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meyami <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:02:18 by meyami            #+#    #+#              #
#    Updated: 2017/12/18 16:19:00 by meyami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SOURCES = 	ft_lstdelone.c ft_strnequ.c ft_strclr.c ft_strdel.c ft_strncmp.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_strsplit.c ft_itoa.c ft_putchar.c \
			ft_strjoin.c ft_strtrim.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_strnew.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
			ft_strsub.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_lstnew.c\
			ft_memalloc.c ft_memdel.c ft_strncat.c ft_strlcat.c ft_memset.c \
			ft_bzero.c ft_memcpy.c ft_memccpy.c	ft_strcpy.c ft_strncpy.c ft_strrchr.c \
			ft_strstr.c ft_strnstr.c ft_strcat.c ft_strchr.c ft_isdigit.c ft_isalpha.c \
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
			ft_putstr.c ft_putnbr.c ft_strlen.c ft_strdup.c ft_strcmp.c ft_strequ.c \
			ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
			get_next_line.c	ft_printf.c ft_printf_helper.c ft_printf_itoa.c \
			ft_printf_initializer.c ft_printf_buffer.c ft_printf_converter.c \
			ft_printf_format.c ft_printf_width.c ft_printf_precision.c \
			ft_printf_length.c ft_printf_type.c ft_printf_type_dec.c \
			ft_printf_type_chars.c ft_printf_type_base.c ft_printf_type_others.c \
			ft_atoi_long.c ft_isnumber.c ft_strtablen.c ft_putnchar_fd.c
BINARIES =	$(SOURCES:.c=.o)
CC		 = 	gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) -c $(SOURCES) -I includes/
	ar rcs libft.a $(BINARIES)

clean:
	rm -f $(BINARIES)

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re
