/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:07:44 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/29 20:48:47 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

bool	is_sorted(t_node *list)
{
	if (!list)
		return (false);
	while (list->next)
	{
		if (list->item > list->next->item)
			return (false);
		list = list->next;
	}
	return (true);
}

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

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	destroy(t_stack *sa, t_stack *sb, int status)
{
	clear_stack(sa);
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
