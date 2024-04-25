/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:26:05 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/18 14:51:57 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"
#include <stdio.h>

void	create_stack(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!*stack)
		return ;
	(*stack)->size = 0;
	(*stack)->set = NULL;
}

int main(int ac, char **av)
{
	t_stack *stack;
	t_stack *stack_b;

    stack = NULL;
    stack_b = NULL;
    create_stack(&stack);
    create_stack(&stack_b);
    init_stack(&stack, ac, av);
	sort(&stack, &stack_b);
	clear_stack(&stack);
    clear_stack(&stack_b);
    free(stack);
    free(stack_b);
	return (0);
}
