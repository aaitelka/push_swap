/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:26:05 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/25 19:32:40 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"
#include <stdio.h>

int	create_stack(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!*stack)
		return (0);
	(*stack)->size = 0;
	(*stack)->set = NULL;
	return (1);
}

void destroy(t_stack *sa, t_stack *sb, int status)
{
	if (sa)
		clear_stack(sa);
	if (sb)
		clear_stack(sb);
	exit(status);
}

// void leak()
// {
// 	system("leaks push_swap");
// }

int main(int ac, char **av)
{
	// atexit(leak);
	t_stack *stack;
	t_stack *stack_b;

    stack = NULL;
    stack_b = NULL;
	if (!create_stack(&stack) || !create_stack(&stack_b))
		destroy(stack, stack_b, EXIT_FAILURE);
	if (!init_stack(&stack, ac, av))
		destroy(stack, stack_b, EXIT_FAILURE); 
	sort(stack, stack_b);
	destroy(stack, stack_b, EXIT_SUCCESS);
	return (0);
}

