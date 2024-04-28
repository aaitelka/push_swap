/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:42:48 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/28 13:07:13 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker_bonus.h"

int	create_stack(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!*stack)
		return (0);
	(*stack)->size = 0;
	(*stack)->set = NULL;
	return (1);
}

bool	should_do(char *instr)
{
	return (!ft_strcmp(instr, PA) || !ft_strcmp(instr, PB)
		|| !ft_strcmp(instr, RA) || !ft_strcmp(instr, RB)
		|| !ft_strcmp(instr, RR)
		|| !ft_strcmp(instr, SA) || !ft_strcmp(instr, SB)
		|| !ft_strcmp(instr, SS)
		|| !ft_strcmp(instr, RRA) || !ft_strcmp(instr, RRB)
		|| !ft_strcmp(instr, RRR));
}

t_list	*get_instructions(void)
{
	char	*line;
	t_list	*instr;

	line = NULL;
	instr = NULL;
	while (true)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (should_do(line))
			ft_lstadd_back(&instr, ft_lstnew(line));
		else
		{
			ft_putstr_fd("Error\n", 1);
			exit(EXIT_FAILURE);
		}
	}
	return (instr);
}

void	apply_instruction(t_stack *s_a, t_stack *s_b, t_list *instr)
{
	t_list	*current;

	current = instr;
	while (current)
	{
		if (!ft_strcmp(current->content, PA))
			px(&s_a, &s_b);
		else if (!ft_strcmp(current->content, PB))
			px(&s_b, &s_a);
		else if (!ft_strcmp(current->content, RA))
			rx(&(s_a)->set);
		else if (!ft_strcmp(current->content, RB))
			rx(&(s_b)->set);
		else if (!ft_strcmp(current->content, RR))
			(rx(&(s_a)->set), rx(&(s_b)->set));
		else if (!ft_strcmp(current->content, RRA))
			rrx(&(s_a)->set);
		else if (!ft_strcmp(current->content, RRB))
			rrx(&(s_b)->set);
		else if (!ft_strcmp(current->content, RRR))
			(rrx(&(s_a)->set), rrx(&(s_b)->set));
		else if (!ft_strcmp(current->content, SA))
			sx(&(s_a)->set);
		else if (!ft_strcmp(current->content, SB))
			sx(&(s_b)->set);
		else if (!ft_strcmp(current->content, SS))
			(sx(&(s_a)->set), sx(&(s_b)->set));
		current = current->next;
	}
	ft_lstclear(&instr, free);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*stack_b;

	stack = NULL;
	stack_b = NULL;
	if (ac < 2)
		exit(EXIT_SUCCESS);
	if (!create_stack(&stack) || !create_stack(&stack_b))
		destroy(stack, stack_b, EXIT_FAILURE);
	if (!init_stack(&stack, ac, av))
		destroy(stack, stack_b, EXIT_FAILURE);
	apply_instruction(stack, stack_b, get_instructions());
	if (is_sorted(stack->set))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	destroy(stack, stack_b, EXIT_SUCCESS);
	return (0);
}
