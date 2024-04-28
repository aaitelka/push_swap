/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:45:42 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/28 15:45:18 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define TOP 1
# define BOTTOM 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define SA "sa\n"
# define SB "sb\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RR "rr\n"
# define RRR "rrr\n"
# define SS "ss\n"

# include "../../lib/libft/libft.h"
# include <stdbool.h>
# include <string.h>

typedef struct s_node
{
	int				item;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	int		max;
	t_node	*set;
}	t_stack;

bool	is_sorted(t_node *list);

bool	is_duplicate(t_node *stack, t_node *new);

int		find_target(t_stack *stack, int target);

int		ft_strcmp(const char *s1, const char *s2);

void	destroy(t_stack *sa, t_stack *sb, int status);

bool	init_stack(t_stack **stack, int ac, char **av);

long	ft_atol(const char *str);

bool	is_blank(char *str);

/**		 --------------------
 *		|	INSTRUCTIONS	|
 *		--------------------
 */

void	sx(t_node **node);

void	rx(t_node **node);

void	rrx(t_node **node);

void	px(t_stack **dest, t_stack **src);

void	sort(t_stack *s_a, t_stack *s_b);

/**		 --------------------
 *		|	LINKED	LIST	|
 *		--------------------
 */

t_node	*create_node(int item);

void	add_back(t_node **nodes, t_node *new);

void	clear_stack(t_stack *stack);

t_node	*last_node(t_node *node);

char	*get_next_line(int fd);

#endif
