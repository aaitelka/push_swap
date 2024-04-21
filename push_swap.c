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


void	print_and_exit(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_check_duplicated(t_node *stack, t_node *new)
{
	t_node	*current;

	current = stack;
	while (current)
	{
		if (current->item == new->item)
			print_and_exit();
		else if (current->item < new->item)
			new->index++;
		else
			current->index++;
		current = current->next;
	}
}

bool	has_double_sign(char c, char nc)
{
	return ((c == '-' && nc == '-') || (c == '-' && nc == '+') || (c == '+' && nc == '+') || (c == '+' && nc == '-'));
}

bool    only_sign(char *str)
{
    return (ft_strlen(str) == 1 && (*str == '+' || *str == '-'));
}

long	parse_arg(char *args)
{
	int		k;
	long	result;

	k = 0;
	while (args[k])
	{
		if (!(ft_isdigit(args[k]) || args[k] == '-' || args[k] == '+')
			|| (ft_isdigit(args[k - 1]) && (args[k] == '-' || args[k] == '+'))
			|| args[k] == '\t'
            || only_sign(args)
			|| has_double_sign(args[k], args[k + 1]))
			print_and_exit();
		else
			result = ft_atol(args);
		k++;
	}
	return (result);
}

void	ft_push(t_stack **stack, char *arg)
{
	t_node	*new_item;
	long	result;

	result = parse_arg(arg);
	if (result <= INT_MAX && result >= INT_MIN)
	{
		new_item = ft_new_node((int)(result));
		new_item->index = 1;
		(*stack)->size++;
		(*stack)->max++;
		ft_check_duplicated((*stack)->collection, new_item);
		ft_add_back(&(*stack)->collection, new_item);
	}
	else
		print_and_exit();
}

void	parse_args(t_stack **stack, int ac, char **av)
{
	int		j;
	int		i;
	char	**args;

	i = 0;
	args = NULL;
	while (ac > 1 && ++i < ac)
	{
		if (*av[i] == '\t' || ft_strncmp(av[i], "", 1) == 0)
			print_and_exit();
		args = ft_split(av[i], ' ');
		if (!*args)
			print_and_exit();
		j = 0;
		while (args[j])
		{
			ft_push(stack, args[j]);
			free(args[j]);
			j++;
		}
		free(args);
		args = NULL;
	}
}

void print(int item, int index)
{
	printf("item = %d   |   index = %d\n", item, index);
}

void display(t_node *stack, t_node *stack_b)
{
	ft_iterate(stack, print);
	ft_iterate(stack_b, print);
}

void f()
{
	system("leaks push_swap");
}


void	ft_init(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!*stack)
		return ;
	(*stack)->size = 0;
	(*stack)->collection = NULL;
}

int main(int ac, char **av)
{
//	atexit(f);
	t_stack *stack = NULL;
	t_stack *stack_b = NULL;

	ft_init(&stack);
	ft_init(&stack_b);

	parse_args(&stack, ac, av);
	ft_sort(&stack, &stack_b);

	// printf("size = %d\n", stack->size);

	ft_clear(&stack);
	ft_clear(&stack_b);
	return (0);
}
