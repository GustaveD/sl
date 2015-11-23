# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/05 16:38:09 by jrosamon          #+#    #+#              #
#    Updated: 2015/11/23 14:36:02 by jrosamon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_ls

SRC_NAME = main.c\
		   opt.c\
		   dir.c\
		   tools.c\
		   print.c

SRC_PATH = ./src/
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

SRCO_NAME = $(SRC_NAME:.c=.o)
SRCO_PATH = ./obj/
SRCO = $(addprefix $(SRCO_PATH), $(SRCO_NAME))

INCL_NAME = ft_ls.h
INCL_PATH = ./includes/
INCL = $(addprefix $(INCL_PATH), $(INCL_NAME))

LIBFT_NAME = libft.a
LIBFT_PATH = ./libft/
LIBFT = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))
LIBFT_INCL_PATH = ./libft/includes/
LIBFT_CC = -lft
LIB = -L $(LIBFT_PATH) $(LIBFT_CC)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(SRCO)
	$(CC) $(CFLAGS) $(LIB) -o $(NAME) $(SRCO)
	@echo "\033[0;36"$(NAME)" created\033[m"

clean:
	@make -C $(LIBFT_PATH) $@
	rm -rf $(SRCO_PATH)
	@echo "\033[0;32m"$(NAME)" objects cleaned\033[m"

clean_fclean:
	rm -rf $(SRCO_PATH)
	@echo "\033[0;32m"$(NAME)"objects cleaned\033[m"

fclean: clean_fclean
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) $@
	@echo "\033[0;31m"$(NAME)" cleaned\033[m"

re: fclean all

norme:
	@norminette $(SRC)
	@norminette $(INCL)
	@make -C $(LIBFT_PATH) $@

$(SRCO_PATH)%.o: $(SRC_PATH)%.c $(INCL)
	@if [ ! -d $(SRCO_PATH) ]; then \
		mkdir $(SRCO_PATH);\
		fi
	$(CC) $(CFLAGS) -I $(INCL_PATH) -I $(LIBFT_INCL_PATH) -o $@ -c $<

.PHONY: all clean fclean re $(LIBFT) norme



