/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:42:41 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/11 15:42:44 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	sx(t_node **node)
{
	t_node	*tmp;

	if (!(*node) || !((*node)->next))
		return ;
	tmp = (*node)->next;
	(*node)->next = tmp->next;
	tmp->next = *node;
	(*node) = tmp;
}

void	px(t_stack **dest, t_stack **src)
{
	t_node	*tmp;

	if (!*src || !*dest || !(*src)->size)
		return ;
	tmp = (*src)->set;
	(*src)->set = (*src)->set->next;
	tmp->next = (*dest)->set;
	(*dest)->set = tmp;
	(*dest)->size++;
	(*src)->size--;
}

void	rx(t_node **node)
{
	t_node	*tmp;

	if (!(*node) || !((*node)->next))
		return ;
	tmp = (*node);
	(*node) = (*node)->next;
	last_node(tmp)->next = tmp;
	tmp->next = NULL;
}

void	rrx(t_node **node)
{
	t_node	*tmp;

	if (!(*node) || !((*node)->next))
		return ;
	tmp = (*node);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = (*node);
	(*node) = tmp->next;
	tmp->next = NULL;
}
