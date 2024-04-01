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

void	ft_swap(t_list **stack)
{
	t_list	*tmp;

    if (!(*stack) || !((*stack)->next))
        return;
    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = *stack;
    *stack = tmp;
}

void	ft_push_stack(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (!(*src) || !ft_lstsize(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	ft_lstadd_front(dest, ft_lstnew((tmp)->content));
}

void	ft_rotate(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || ft_lstsize(*stack) == 1)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, ft_lstnew(tmp->content));
}

void	ft_pop_last(t_list **stack)
{
	t_list	*last;
	t_list	*current;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	current = *stack;
	last = ft_lstlast(*stack);
	while (current->next != last)
		current = current->next;
	current->next = NULL;
}

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || ft_lstsize(*stack) == 1)
		return ;
	tmp = ft_lstlast(*stack);
	ft_lstadd_front(stack, ft_lstnew(tmp->content));
	ft_pop_last(stack);
}
