/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:00:02 by aaitelka          #+#    #+#             */
/*   Updated: 2024/03/28 23:00:04 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_list *list)
{
	if (!list || !list->next)
		return (false);
	while (list->next)
	{
		if ((long) list->content > (long) list->next->content)
			return (false);
		list = list->next;
	}
	return (true);
}

//truevoid	ft_sort(t_list **stack_a, t_list **stack_b)
//{
//
//}