# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 23:14:42 by aaitelka          #+#    #+#              #
#    Updated: 2024/04/11 22:25:26 by aaitelka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	:=	\033[0;32m
NC		:=	\033[0m

LIBFT	:=	./libft
MK_LBFT :=	@$(MAKE) --no-print-directory -C $(LIBFT)

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror

NAME	:=	push_swap
HEAD	:=	include/push_swap.h

SRCS	:=	push_swap.c \
			src/ft_atol.c \
			src/ft_libft.c \
			src/instructions.c \
			src/push_swap_utils.c \
			src/push_swap_sorting.c

OBJS	:=	$(SRCS:%.c=%.o)

all		:	$(NAME)

%o		:	%c $(HEAD)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS) $(LIBFT)/libft.a
			@echo "$(GREEN)==========| Compiling libft... |==========$(NC)"
			$(MK_LBFT)
			@echo "$(GREEN)==========| Compiling libft bonus... |==========$(NC)"
			$(MK_LBFT) bonus
			@echo "$(GREEN)==========| Linking $(NAME) executable... |==========$(NC)"
			$(CC) $(CFLAGS) $^ $(LIBFT)/libft.a -o $@

run		: all
		./push_swap 2 1 3 6 5
clean	:
			@echo "$(GREEN)==========| Cleaning... |==========...$(NC)"
			$(MK_LBFT) clean
			$(RM) $(OBJS)

fclean	:	clean
			@echo "$(GREEN)==========| Full Cleaning... |==========$(NC)"
			$(MK_LBFT) fclean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	clean
