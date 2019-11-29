# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcariou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 17:39:52 by pcariou           #+#    #+#              #
#    Updated: 2019/11/29 14:30:54 by pcariou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

HEADER		= ./

SRCS		=  ft_printf.c ft_printf2.c ft_printf3.c ft_printf4.c small_fts.c small_fts2.c

OBJS		= $(SRCS:.c=.o)

RM			= rm -f

AR			=  ar rcs

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc

ATTRIBUT	= -c

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) $(ATTRIBUT) $< -o $(<:.c=.o) -I$(HEADER)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS) && cd libft && make

clean:
			$(RM) $(OBJS) && cd libft && make clean

fclean:		clean
			$(RM) $(NAME) && cd libft && make fclean

re:			fclean all

.PHONY:		all clean fclean re
