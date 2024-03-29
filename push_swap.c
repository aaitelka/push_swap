/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:26:05 by aaitelka          #+#    #+#             */
/*   Updated: 2024/03/13 21:26:07 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_and_exit()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

long ft_atol(const char *str)
{
	int sign;
	long result;

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

void ft_check_duplicated(t_list *stack, void *content)
{
	t_list *current;

	current = stack;
	while (current)
	{
		if (current->content == content)
			print_and_exit();
		current = current->next;
	}
}

long parse_arg(char *args)
{
	int k;
	long result;

	k = 0;
	while (args[k])
	{
		if (!(ft_isdigit(args[k]) || args[k] == '-' || args[k] == '+')
			|| (ft_isdigit(args[k - 1]) && (args[k] == '-' || args[k] == '+'))
			|| args[k] == '\t')
			print_and_exit();
		else
			result = ft_atol(args);
		k++;
	}
	return (result);
}

void parse_args(t_list **stack, int ac, char **av)
{
	int i;
	int j;
	long result;
	char **args;

	i = 0;
	args = NULL;
	while (ac > 1 && ++i < ac)
	{
		if (*av[i] == '\t' || *av[i] == ' ' || ft_strncmp(av[i], "", 1) == 0)
			print_and_exit();
		args = ft_split(av[i], ' ');
		if (!*args)
			print_and_exit();
		j = 0;
		while (args[j])
		{
			result = parse_arg(args[j]);
			if (result <= INT_MAX && result >= INT_MIN)
			{
				ft_check_duplicated(*stack, (void *) result);
				ft_lstadd_back(stack, ft_lstnew((void *) result));
			} else
				print_and_exit();
			j++;
		}
	}
}

#include <stdio.h>

void print(int value)
{
	printf("%d\n", value);
}

void display(t_list *stack, t_list *stack_b)
{
	printf("-\n");
	printf("a\n");
	printf("-\n");
	ft_lstiter(stack, (void *) print);
	printf("-\n");
	printf("b\n");
	printf("-\n");
	ft_lstiter(stack_b, (void *) print);
}

void example(t_list *stack, t_list *stack_b)
{
	printf("=========STACK A========\n");
	display(stack, stack_b);
	printf("=========SWAP A========\n");
	ft_swap(&stack);
	display(stack, stack_b);
	printf("=========PB PB PB========\n");
	ft_push(&stack_b, &stack);
	ft_push(&stack_b, &stack);
	ft_push(&stack_b, &stack);
	display(stack, stack_b);
	printf("=========RA RB========\n");
	ft_rotate(&stack);
	ft_rotate(&stack_b);
	display(stack, stack_b);
	printf("=========RRA RRB========\n");
	ft_reverse_rotate(&stack);
	ft_reverse_rotate(&stack_b);
	display(stack, stack_b);
	printf("=========SWAP A========\n");
	ft_swap(&stack);
	display(stack, stack_b);
	printf("=========PA PA PA========\n");
	ft_push(&stack, &stack_b);
	ft_push(&stack, &stack_b);
	ft_push(&stack, &stack_b);
	display(stack, stack_b);

	bool sorted = ft_is_sorted(stack);
	if (sorted)
		printf("Sorted\n");
	else
		printf("Not Sorted\n");
}

int main(int ac, char **av)
{
	t_list *stack = NULL;
	t_list *stack_b = NULL;

	parse_args(&stack, ac, av);
	example(stack, stack_b);

	return (0);
}
