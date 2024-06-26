/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:21:12 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/28 15:43:55 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	print_and_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

bool	has_double_sign(char c, char nc)
{
	return ((c == '-' && nc == '-') || (c == '-' && nc == '+')
		|| (c == '+' && nc == '+') || (c == '+' && nc == '-'));
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
			|| (ft_strlen(args) == 1 && (args[k] == '+' || args[k] == '-'))
			|| has_double_sign(args[k], args[k + 1]))
			print_and_exit();
		else
			result = ft_atol(args);
		k++;
	}
	return (result);
}

bool	put_to_stack(t_stack **stack, char *arg)
{
	t_node	*new_node;
	long	result;

	new_node = NULL;
	result = parse_arg(arg);
	if (result <= INT_MAX && result >= INT_MIN)
	{
		new_node = create_node((int)(result));
		if (!new_node)
			return (false);
		new_node->index = 1;
		(*stack)->size++;
		(*stack)->max++;
		if (is_duplicate((*stack)->set, new_node))
			print_and_exit();
		add_back(&(*stack)->set, new_node);
	}
	else
		print_and_exit();
	return (true);
}

bool	init_stack(t_stack **stack, int ac, char **av)
{
	int		j;
	int		i;
	char	**args;

	i = 0;
	args = NULL;
	while (ac > 1 && ++i < ac)
	{
		if (ft_strncmp(av[i], "", 1) == 0 || is_blank(av[i]))
			print_and_exit();
		args = ft_split(av[i], ' ');
		if (!args)
			return (false);
		j = 0;
		while (args[j])
		{
			if (!put_to_stack(stack, args[j]))
				return (false);
			free(args[j]);
			j++;
		}
		free(args);
	}
	return (true);
}
