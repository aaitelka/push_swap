/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:26:05 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/01 01:19:50 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"
#include <stdio.h>

void	print_and_exit(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_check_duplicated(t_list *stack, void *content)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		if (*((int *)current->content) == *((int *)content))
            print_and_exit();
		current = current->next;
	}
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
			|| args[k] == '\t')
			print_and_exit();
		else
			result = ft_atol(args);
		k++;
	}
	return (result);
}

void	ft_push(t_list **stack, char *arg)
{
	long	result;
    int    *item;

	result = parse_arg(arg);
	if (result <= INT_MAX && result >= INT_MIN)
	{
        item = (int *)malloc(sizeof(int));
        if (!item)
            return ;
        *item = (int)result;
		ft_check_duplicated(*stack, item);
		ft_lstadd_back(stack, ft_lstnew(item));
        item = NULL;
	}
	else
		print_and_exit();
}

void	parse_args(t_list **stack, int ac, char **av)
{
	int		i;
	int		j;
	char	**args;

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
			ft_push(stack, args[j]);
            free(args[j]);
			j++;
		}
        free(args);
        args = NULL;
	}
}


void print(void *content)
{
	printf("%d\n", *((int *)content));
}

void display(t_list *stack, t_list *stack_b)
{
	printf("-\n");
	printf("a\n");
	printf("-\n");
	ft_lstiter(stack, print);
	printf("-\n");
	printf("b\n");
	printf("-\n");
	ft_lstiter(stack_b, print);
}

void example(t_list *stack, t_list *stack_b)
{
	printf("=========STACK A========\n");
	display(stack, stack_b);
	printf("=========SWAP A========\n");
	ft_swap(&stack);
	display(stack, stack_b);
//	printf("=========PB PB PB========\n");
//	ft_push_stack(&stack_b, &stack);
//	ft_push_stack(&stack_b, &stack);
//	ft_push_stack(&stack_b, &stack);
//	display(stack, stack_b);
//	printf("=========RA RB========\n");
//	ft_rotate(&stack);
//	ft_rotate(&stack_b);
//	display(stack, stack_b);
//	printf("=========RRA RRB========\n");
//	ft_reverse_rotate(&stack);
//	ft_reverse_rotate(&stack_b);
//	display(stack, stack_b);
//	printf("=========SWAP A========\n");
//	ft_swap(&stack);
//	display(stack, stack_b);
//	printf("=========PA PA PA========\n");
//	ft_push_stack(&stack, &stack_b);
//	ft_push_stack(&stack, &stack_b);
//	ft_push_stack(&stack, &stack_b);
//	display(stack, stack_b);

	bool sorted = ft_is_sorted(stack);
	if (sorted)
		printf("Sorted\n");
	else
		printf("Not Sorted\n");
}

void f(void *content)
{
    free(content);
}

int main(int ac, char **av)
{
	t_list *stack = NULL;
	t_list *stack_b = NULL;

	parse_args(&stack, ac, av);
	example(stack, stack_b);

    ft_lstclear(&stack, free);
    ft_lstclear(&stack_b, free);
	return (0);
}
