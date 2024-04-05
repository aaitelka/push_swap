/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:00:02 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/03 01:43:34 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

bool	ft_is_sorted(t_node *list)
{
	if (!list || !list->next)
		return (false);
	while (list->next)
	{
		if (list->item > list->next->item)
			return (false);
		list = list->next;
	}
	return (true);
}

void	p(int item, int index)
{
	printf("item = %d\t| index = %d\n", item, index);
}

/**
 * in next push from a to b should check if top < chunk
 */
void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int index;
	int	chunk;
	int	schunk;

	if (!*stack_a || ft_is_sorted((*stack_a)->collection) || !*stack_b)
		return ;
	chunk = 0;
	schunk = 0;
	ft_iterate((*stack_a)->collection, p);
	printf("-----------------------------\n");
	while ((*stack_a)->size)
	{
		if ((*stack_b)->size == chunk)
		{
			schunk = chunk / 2;
			chunk += ((*stack_a)->size / 3) + schunk;
		}
		index = (*stack_a)->collection->index;
		ft_push_stack(stack_b, stack_a);
		if (index <= chunk)
			ft_rotate(&(*stack_b)->collection);
	}
	ft_iterate((*stack_b)->collection, p);
}
