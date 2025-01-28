/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:44:43 by psevilla          #+#    #+#             */
/*   Updated: 2025/01/28 18:54:02 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_first(t_stack **s_a, t_size *size, unsigned int block)
{
	int	i;
	int	j;

	i = 0;
	while ((*s_a)->index >= block && i++ <= size->size_a)
		rotate(s_a);
	j = i;
	while (j--)
		reverse_rotate(s_a);
	return (i);
}

int	find_last(t_stack **s_a, t_size *size, unsigned int block)
{
	int	i;
	int	j;

	i = 0;
	while ((*s_a)->index >= block && i++ <= size->size_a)
		reverse_rotate(s_a);
	j = i;
	while (j--)
		rotate(s_a);
	i = size->size_a - i;
	return (i);
}

int	ft_sqrt(unsigned int nbr)
{
	unsigned int	i;

	i = 1;
	while (i * i <= nbr)
	{
		if (i * i == nbr)
			return (i);
		i++;
	}
	return (i - 1);
}
