/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:26:14 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/01 01:25:01 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
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
	t_node	*collection;
}			t_stack;

long	ft_atol(const char *str);

void	ft_swap(t_node **stack);

void	ft_push_stack(t_node **dest, t_node **src);

void	ft_rotate(t_node **stack);

void	ft_reverse_rotate(t_node **stack);

void	ft_sort(t_node **stack_a, t_node **stack_b);

bool	ft_is_sorted(t_node *list);

/**		 --------------------
 *		|	LINKED	LIST	|
 *		--------------------
 */

t_node	*ft_new_node(int item);

void	ft_add_front(t_node **nodes, t_node *new);

void	ft_add_back(t_node **nodes, t_node *new);

void	ft_del_one(t_node *node);

void	ft_clear(t_node **nodes, void (*del)(void*));

void	ft_iterate(t_node *node, void (*f)(int));

t_node	*ft_last(t_node *node);

#endif
