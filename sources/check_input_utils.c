/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:44:20 by psevilla          #+#    #+#             */
/*   Updated: 2025/01/27 17:45:43 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	is_zero(char *s)
{
	int	i;

	i = 0;
	if (is_sign(s[i]))
		i++;
	while (s[i] && s[i] == '0')
		i++;
	if (!s[i])
		return (1);
	return (0);
}

int	cmp_nbr(char *n1, char *n2)
{
	int	num1;
	int	num2;

	num1 = ft_atoi(n1);
	num2 = ft_atoi(n2);
	return (num1 == num2);
}

int	is_num(char *s)
{
	int	i;

	i = 0;
	if (is_sign(s[i]) && is_digit(s[i + 1]))
		i++;
	while (s[i])
	{
		if (!is_digit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
