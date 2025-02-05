/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:44:23 by psevilla          #+#    #+#             */
/*   Updated: 2025/01/28 18:51:13 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_dup(char **input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		j = i + 1;
		while (input[j])
		{
			if (cmp_nbr(input[i], input[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a)
		free_stack(stack_a);
	if (!stack_b || !*stack_b)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(0);
}

int	check_input(char **input)
{
	int	i;
	int	zeros;

	i = 0;
	zeros = 0;
	while (input[i])
	{
		if (!is_num(input[i]))
			return (0);
		zeros += is_zero(input[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	if (is_dup(input))
		return (0);
	return (1);
}

int	check_order(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
