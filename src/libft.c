/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 01:37:11 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/25 01:37:11 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*create_node(int item)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->item = item;
	node->next = NULL;
	return (node);
}

t_node	*last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	add_back(t_node **nodes, t_node *new)
{
	t_node	*last;

	if (!nodes || !new)
		return ;
	last = last_node(*nodes);
	if (last)
		last->next = new;
	else
		*nodes = new;
}

void	del_one(t_stack **stack, void (*del)(void*))
{
    if (!stack || !del)
        return ;
    del((*stack)->set);
    free(*stack);
}

void	clear(t_stack **stack, void (*del)(void*))
{
    t_node 	*temp;

    if (!stack || !del)
        return ;
    while ((*stack)->set)
    {
        temp = (*stack)->set->next;
        del_one(stack, del);
        (*stack)->set = temp;
    }
    *stack = NULL;
}

void	clear_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	current = (*stack)->set;
	while (current)
	{
		next = current->next;
		free(current);
        current = NULL;
		current = next;
	}
	free(*stack);
	*stack = NULL;
}
