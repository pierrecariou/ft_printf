# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcariou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 18:00:16 by pcariou           #+#    #+#              #
#    Updated: 2019/11/28 16:49:50 by pcariou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ../libftprintf.a


HEADER		= ./

SRCS		=  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strtrim.c ft_itoa.c ft_strjoin.c ft_substr.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_memmove.c ft_strrev.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_putchar_count.c write_str_rev.c hexaconverter.c ft_putnbr_count.c ft_putunbr_count.c count_length_unbr.c count_length_ulnbr.c count_length_nbr.c pointerconverter.c ft_putnstr.c ft_putstr.c ft_putnstr.c 

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
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) 

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

