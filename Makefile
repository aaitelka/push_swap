# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 23:14:42 by aaitelka          #+#    #+#              #
#    Updated: 2024/04/27 12:13:42 by aaitelka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	:=	\033[0;32m
NC		:=	\033[0m

LIBFT	:=	lib/libft/libft.a
MK_LBFT	:=	@$(MAKE) --no-print-directory -C ./lib/libft

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror

NAME	:=	push_swap
HEAD	:=	pushswap/include/push_swap.h

CHECKER	:= checker
B_HEAD	:= bonus/include/checker_bonus.h

SRCS	:=	pushswap/push_swap.c \
			pushswap/src/libft.c \
			pushswap/src/parsing.c \
			pushswap/src/sorting.c \
			pushswap/src/helpers.c \
			pushswap/src/instructions.c \

OBJS	:=	$(SRCS:%.c=%.o)

B_SRCS	:=	bonus/checker_bonus.c \
			bonus/src/libft_bonus.c \
			bonus/src/parsing_bonus.c \
			bonus/src/helpers_bonus.c \
			bonus/src/instructions_bonus.c \
			bonus/src/read_instructions_bonus.c \

B_OBJS	:=	$(B_SRCS:%_bonus.c=%_bonus.o)

all : 			$(NAME)

%.o			:	%.c $(HEAD)
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 		$(OBJS) $(LIBFT)
				@echo "$(GREEN)==========| Linking $(NAME) executable... |==========$(NC)"
				$(CC) $(OBJS) $(LIBFT) -o $@


%_bonus.o : 	%_bonus.c $(B_HEAD)
				$(CC) $(CFLAGS) -c $< -o $@

bonus		: 	$(CHECKER)

$(CHECKER)	: 	$(B_OBJS) $(LIBFT)
				@echo "$(GREEN)==========| Linking $(CHECKER) executable... |==========$(NC)"
				$(CC) $(B_OBJS) $(LIBFT) -o $@

$(LIBFT) :
				@echo "$(GREEN)==========| Compiling libft... |==========$(NC)"
				$(MK_LBFT)
				@echo "$(GREEN)==========| Compiling libft bonus... |==========$(NC)"
				$(MK_LBFT) bonus

clean		:
				@echo "$(GREEN)==========| Cleaning... |==========...$(NC)"
				$(MK_LBFT) clean
				$(RM) $(OBJS) $(B_OBJS)

fclean :		clean
				@echo "$(GREEN)==========| Full Cleaning... |==========$(NC)"
				$(MK_LBFT) fclean
				$(RM) $(NAME) $(CHECKER)

re		:		fclean all
