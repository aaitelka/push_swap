/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:26:14 by aaitelka          #+#    #+#             */
/*   Updated: 2024/03/13 21:26:16 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

void	ft_swap(t_list **stack);

void	ft_push(t_list **dest, t_list **src);

void	ft_rotate(t_list **stack);

void	ft_pop_last(t_list **stack);

void	ft_reverse_rotate(t_list **stack);

#endif
