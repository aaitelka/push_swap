/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:45:42 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/25 13:45:42 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# define TOP 1
# define BOTTOM 0

# include "../../lib/libft/libft.h"
# include <stdbool.h>

typedef struct s_node
{
    int				item;
    int				index;
    struct s_node	*next;
}					t_node;

typedef struct s_stack
{
    int		size;
    int		max;
    t_node	*set;
}			t_stack;

void	init_stack(t_stack **stack, int ac, char **av);

unsigned long long	ft_atoll(const char *str);

/**		 --------------------
 *		|	INSTRUCTIONS	|
 *		--------------------
 */

void	sx(t_node **node, char c);

void 	px(t_stack **dest, t_stack **src, char c);

void	rx(t_node **node, char c);

void	rrx(t_node **node, char c);

void 	sort(t_stack **s_a, t_stack **s_b);

/**		 --------------------
 *		|	LINKED	LIST	|
 *		--------------------
 */

t_node	*create_node(int item);

void	add_back(t_node **nodes, t_node *new);

void	ft_del_one(t_node *node);

void	clear_stack(t_stack **stack);

t_node	*last_node(t_node *node);

#endif