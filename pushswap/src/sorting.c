/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:00:02 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/28 12:26:32 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

static void	sort_three(t_stack *s_a)
{
	int	top;
	int	next;
	int	last;

	if (is_sorted(s_a->set))
		return ;
	while (!is_sorted(s_a->set))
	{
		top = s_a->set->index;
		next = s_a->set->next->index;
		last = last_node(s_a->set)->index;
		if (top > next && next < last)
			sx(&(s_a)->set, 'a');
		else if (top > next && next < last)
			rx(&(s_a)->set, 'a');
		else
			rrx(&(s_a)->set, 'a');
	}
}

static void	centralize(t_stack *s_a, t_stack *s_b, int div)
{
	int	chunk;
	int	top_a;

	chunk = s_a->size / div;
	while (s_a->size > 3)
	{
		top_a = s_a->set->index;
		if (s_b->size == chunk)
			chunk += s_a->size / div;
		if (top_a <= chunk)
		{
			px(&s_b, &s_a, 'b');
			if (top_a <= chunk - (s_a->size / div) / 2)
				rx(&(s_b)->set, 'b');
		}
		else
			rx(&(s_a)->set, 'a');
	}
}

static void	sort_all(t_stack *s_a, t_stack *s_b)
{
	int		target;
	int		last_a;
	int		last_b;

	while (s_b->size)
	{
		target = s_a->set->index - 1;
		last_a = last_node(s_a->set)->index;
		last_b = last_node(s_b->set)->index;
		if (target == s_b->set->index)
			px(&s_a, &s_b, 'a');
		else if (target == last_a)
			rrx(&(s_a)->set, 'a');
		else if (target == last_b)
			(rrx(&(s_b)->set, 'b'), px(&s_a, &s_b, 'a'));
		else if (last_a == s_a->max)
			(px(&s_a, &s_b, 'a'), rx(&(s_a)->set, 'a'));
		else if (last_b > last_a)
			(rrx(&(s_b)->set, 'b'), px(&s_a, &s_b, 'a'), rx(&(s_a)->set, 'a'));
		else if (find_target(s_b, target))
			rx(&(s_b)->set, 'b');
		else
			rrx(&(s_b)->set, 'b');
	}
}

void	sort(t_stack *s_a, t_stack *s_b)
{
	if (!s_a || is_sorted((s_a)->set) || (s_a)->size < 2 || !s_b)
		return ;
	if ((s_a)->size == 5)
		centralize(s_a, s_b, 2);
	else
		centralize(s_a, s_b, 3);
	sort_three(s_a);
	sort_all(s_a, s_b);
	while ((s_a)->set->index != 1)
		rrx(&(s_a)->set, 'a');
}
