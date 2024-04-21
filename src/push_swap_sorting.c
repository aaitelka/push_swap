/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:00:02 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/18 15:02:41 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

bool ft_is_sorted(t_node *list) {
    if (!list || !list->next)
        return (false);
    while (list->next) {
        if (list->item > list->next->item)
            return (false);
        list = list->next;
    }
    return (true);
}

void p(int item, int index) {
    printf("item = %d\t| index = %d\n", item, index);
}
int find_min(t_stack **stack) {
    t_node *tmp;
    int min;

    tmp = (*stack)->collection;
    min = tmp->index;
    while (tmp) {
        if (min > tmp->index)
            min = tmp->index;
        tmp = tmp->next;
    }
    printf("min = %d\n", min);
    return (min);
}

int ft_find_target(t_stack **stack, int target) {
    int half;
    t_node *list;

    list = (*stack)->collection;
    half = (*stack)->size / 2;
    while (half--) {
        if (target == list->index)
            return (1);
        list = list->next;
    }
    return (0);
}

void	ft_sort_three(t_stack **stack_a)
{
    int	top;
    int	next;
    int	last;

    if (!*stack_a || ft_is_sorted((*stack_a)->collection))
        return ;
    while (!ft_is_sorted((*stack_a)->collection))
    {
        top = (*stack_a)->collection->index;
        next = (*stack_a)->collection->next->index;
        last = ft_last((*stack_a)->collection)->index;
        if (top > next && next < last)
            ft_swap(&(*stack_a)->collection, 'a');
        else if (top > next && next < last)
            ft_rotate(&(*stack_a)->collection, 'a');
        else
            ft_reverse_rotate(&(*stack_a)->collection, 'a');
    }
}

void ft_sort_five(t_stack **stack_a, t_stack **stack_b) {
    int target;

    target = 0;
    while ((*stack_a)->size > 2) {
        target += 1;
        if (ft_find_target(stack_a, target)) {
            ft_rotate(&(*stack_a)->collection, 'a');
        } else
            ft_reverse_rotate(&(*stack_a)->collection, 'a');
        if (target == (*stack_a)->collection->index)
            ft_push_stack(stack_b, stack_a, 'b');
    }
    ft_sort_three(stack_a);
    while ((*stack_b)->size)
        ft_push_stack(stack_a, stack_b, 'a');
}

void centeralize(t_stack **stack_a, t_stack **stack_b) {
    static int chunk;
    static int old_chunk;
    static int pushed;
    int top_a;

    chunk = ((*stack_a)->size / 5);
    pushed = 0;
    old_chunk = chunk;
    while ((*stack_a)->size > 3) {
        top_a = (*stack_a)->collection->index;
        if ((*stack_b)->size == chunk) {
            pushed = chunk;
            old_chunk = ((*stack_a)->size / 3);
            chunk += old_chunk;
        }
        if (top_a <= chunk) {
            ft_push_stack(stack_b, stack_a, 'b');
            if (top_a <= pushed + (old_chunk / 2))
                ft_rotate(&(*stack_b)->collection, 'b');
        } else
            ft_rotate(&(*stack_a)->collection, 'a');
    }
}

void ft_sort_all(t_stack **stack_a, t_stack **stack_b) {

    int top_a;
    int last_a;
    int top_b;
    int last_b;

    while ((*stack_b)->size) {
        top_a = (*stack_a)->collection->index;
        last_a = ft_last((*stack_a)->collection)->index;
        top_b = (*stack_b)->collection->index;
        last_b = ft_last((*stack_b)->collection)->index;
        if ((top_a - 1) == top_b)
            ft_push_stack(stack_a, stack_b, 'a');
        else if ((top_a - 1) == last_a)
            ft_reverse_rotate(&(*stack_a)->collection, 'a');
        else if ((top_a - 1) == last_b) {
            ft_reverse_rotate(&(*stack_b)->collection, 'b');
            ft_push_stack(stack_a, stack_b, 'a');
        } else if (last_a == (*stack_a)->max) {
            ft_push_stack(stack_a, stack_b, 'a');
            ft_rotate(&(*stack_a)->collection, 'a');
        } else if (last_b > last_a) {
            ft_reverse_rotate(&(*stack_b)->collection, 'b');
            ft_push_stack(stack_a, stack_b, 'a');
            ft_rotate(&(*stack_a)->collection, 'a');
        } else if (ft_find_target(stack_b, (top_a - 1)))
            ft_rotate(&(*stack_b)->collection, 'b');
        else
            ft_reverse_rotate(&(*stack_b)->collection, 'b');
    }
}

void ft_sort(t_stack **stack_a, t_stack **stack_b) {

    if (!*stack_a || ft_is_sorted((*stack_a)->collection) || (*stack_a)->size < 2 || !*stack_b)
        return;
    centeralize(stack_a, stack_b);
    ft_sort_five(stack_a, stack_b);
    ft_sort_all(stack_a, stack_b);
}
