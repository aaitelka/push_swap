/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:00:02 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/01 01:20:26 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

//void	ft_sort(t_stack **stack_a, t_stack **stack_b)
//{
//	if (!*stack_a || ft_is_sorted((*stack_a)->collection) || !*stack_b)
//		return ;
//
//	int	top;
//
//	top = (*stack_a)->collection->item;
//
//}