/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:07:44 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/28 15:44:42 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	is_duplicate(t_node *stack, t_node *new)
{
	t_node	*current;

	current = stack;
	while (current)
	{
		if (current->item == new->item)
			return (true);
		else if (current->item < new->item)
			new->index++;
		else
			current->index++;
		current = current->next;
	}
	return (false);
}

int	find_target(t_stack *stack, int target)
{
	int		half;
	t_node	*list;

	list = stack->set;
	half = stack->size / 2;
	while (half--)
	{
		if (target == list->index)
			return (TOP);
		list = list->next;
	}
	return (BOTTOM);
}

void	destroy(t_stack *sa, t_stack *sb, int status)
{
	if (sa)
		clear_stack(sa);
	if (sb)
		clear_stack(sb);
	exit(status);
}

bool	is_blank(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
		{
			return (false);
		}
		str++;
	}
	return (true);
}
