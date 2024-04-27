/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:00:02 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/25 19:43:06 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool    is_sorted(t_node *list)
{
    if (!list || !list->next)
        return (false);
    while (list->next) {
        if (list->item > list->next->item)
            return (false);
        list = list->next;
    }
    return (true);
}

static int find_target(t_stack *stack, int target)
{
    int     half;
    t_node  *list;

    list = stack->set;
    half = stack->size / 2;
    while (half--) {
        if (target == list->index)
            return (TOP);
        list = list->next;
    }
    return (BOTTOM);
}

static void	sort_three(t_stack *s_a)
{
    int	top;
    int	next;
    int	last;

    if (!s_a || is_sorted(s_a->set))
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

static void centralize(t_stack *s_a, t_stack *s_b, int div)
{
    int chunk;
    int old_chunk;
    int pushed;
    int top_a;

    chunk = (s_a->size / div);
    pushed = 0;
    old_chunk = chunk;
    while (s_a->size > 3) {
        top_a = s_a->set->index;
        if (s_b->size == chunk) {
            pushed = chunk;
            old_chunk = (s_a->size / div);
            chunk += old_chunk;
        }
        if (top_a <= chunk) {
            px(&s_b, &s_a, 'b');
            if (top_a <= pushed + (old_chunk / 2))
                rx(&(s_b)->set, 'b');
        } else
            rx(&(s_a)->set, 'a');
    }
}

static void    sort_all(t_stack *s_a, t_stack *s_b)
{
    t_node  *set;
    int     target;
    int     last_a;
    int     last_b;

    while (s_b->size) {
        set = s_a->set;
        target = set->index - 1;
        last_a = last_node(set)->index;
        last_b = last_node(s_b->set)->index;
        if (target == s_b->set->index)
            px(&s_a, &s_b, 'a');
        else if (target == last_a)
            rrx(&(s_a)->set, 'a');
        else if (target == last_b) {
            rrx(&(s_b)->set, 'b'), px(&s_a, &s_b, 'a');
        } else if (last_a == s_a->max) {
            px(&s_a, &s_b, 'a'), rx(&(s_a)->set, 'a');
        } else if (last_b > last_a) {
            rrx(&(s_b)->set, 'b'), px(&s_a, &s_b, 'a');
            rx(&(s_a)->set, 'a');
        } else if (find_target(s_b, target))
            rx(&(s_b)->set, 'b');
        else
            rrx(&(s_b)->set, 'b');
    }
}

void    sort(t_stack *s_a, t_stack *s_b)
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
