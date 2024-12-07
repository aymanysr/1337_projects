# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayousr <ayousr@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/24 10:48:31 by ayousr            #+#    #+#              #
#    Updated: 2024/11/27 16:39:26 by ayousr           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRCS = 	ft_printf_int.c ft_putchar.c ft_printf_char.c ft_printf_pointer.c \
		ft_print_percent.c ft_printf_hex.c ft_printf_str.c ft_strlen.c \
		ft_printf.c ft_printf_hex_upper.c ft_printf_uint.c

CFLAGS = -Wall -Werror -Wextra
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re