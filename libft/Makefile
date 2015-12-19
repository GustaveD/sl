# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/08/11 21:59:51 by jrosamon          #+#    #+#              #
#    Updated: 2015/12/19 17:04:09 by jrosamon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_memdup.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_stricpy.c \
	  ft_strdup.c \
	  ft_strlen.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strlcat.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strrchr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_putstr_fd.c\
	  ft_strsplit.c\
	  ft_lstnew.c \
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_lstadd.c\
	  ft_lstaddfront.c\
	  ft_lstaddafter.c\
	  ft_nbrlen.c\
	  ft_power.c\
	  ft_putnbr_r.c


INCLUDE = -I ./includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIB = ar rc
RANLIB = ranlib

OBJ_NAME = $(SRC:.c=.o)
	
all : $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRC) $(INCLUDE)
	$(CLIB) $(NAME) $(OBJ_NAME)
	$(RANLIB) $(NAME)

clean:
	/bin/rm -f $(OBJ_NAME)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
