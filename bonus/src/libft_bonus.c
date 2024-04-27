/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 01:37:11 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/27 09:26:58 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

long	ft_atol(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == 32)
		str++;
	if (*str == '-' && *str++)
		sign = -1;
	else if (*str == '+')
		str++;
	if (!ft_isdigit(*str) || !*str)
		return (LONG_MAX);
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += (*str++ - '0');
	}
	return (result * sign);
}

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

void	clear_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->set;
	while (current)
	{
		next = current->next;
		free(current);
		current = NULL;
		current = next;
	}
	free(stack);
	stack = NULL;
}
