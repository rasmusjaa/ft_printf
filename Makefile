# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 15:06:49 by rjaakonm          #+#    #+#              #
#    Updated: 2019/11/25 14:41:45 by rjaakonm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	./srcs/ft_printf.c \
		./srcs/arg_funcs.c \
		./srcs/arg_funcs2.c \
		./srcs/arg_funcs3.c \
		./srcs/help_funcs.c \
		./srcs/help_funcs2.c \
		./srcs/help_funcs3.c \
		./srcs/check_funcs.c \
		./srcs/width.c \
		./srcs/flags.c \
		./srcs/exits.c

LFTSRC = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

OBJS = $(subst .c,.o,$(subst srcs/,,$(SRCS)))

INCL = -I ./incl -I ./libft/incl

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): libftmake
	@cp libft/libft.a ./$(NAME)
	@gcc $(FLAGS) $(INCL) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

libftmake:
	@make -C libft

clean:
	@rm -f $(OBJS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

run: re
	gcc $(FLAGS) main.c libftprintf.a
	./a.out
