/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:21:12 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/01 01:20:33 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_node **stack)
{
	t_node	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	(*stack) = tmp;
}

void	ft_push_stack(t_stack **dest, t_stack **src)
{
	t_node	*tmp;

	if (!src || !(*src) || !*dest)
		return ;
	tmp = (*src)->collection;
	(*src)->collection = (*src)->collection->next;
	tmp->next = (*dest)->collection;
	(*dest)->collection = tmp;
	(*dest)->size++;
	(*src)->size--;
}

void	ft_rotate(t_node **stack)
{
	t_node	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	ft_last(tmp)->next = tmp;
	tmp->next = NULL;
}

void	ft_reverse_rotate(t_node **stack)
{
	t_node	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = (*stack);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = (*stack);
	(*stack) = tmp->next;
	tmp->next = NULL;
}
