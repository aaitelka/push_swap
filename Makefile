# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 23:14:42 by aaitelka          #+#    #+#              #
#    Updated: 2024/03/27 23:15:43 by aaitelka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	push_swap
HEAD	:=	push_swap.h
LIBFT	:=	./libft
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
RM		:=	rm -rf

SRCS	:=	push_swap.c \
			push_swap_utils.c

OBJS	:=	$(SRCS:%.c=%.o)

all		:	$(NAME)

%.o		:	%.c $(HEAD)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
		$(MAKE) -C $(LIBFT)
		$(MAKE) bonus -C $(LIBFT)
		$(CC) $(CFLAGS) $^ $(LIBFT)/libft.a -o $@

clean	:
		$(MAKE) -C $(LIBFT) clean
		$(RM) $(OBJS)

fclean	:	clean
		$(MAKE) -C $(LIBFT) fclean
		$(RM) $(NAME)

re		:	fclean all

.PHONY	:	clean
