/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:58:54 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/01 01:23:54 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

long	ft_atol(const char *str)
{
	int		sign;
	long	result;

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
