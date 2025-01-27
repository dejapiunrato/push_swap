/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:44:45 by psevilla          #+#    #+#             */
/*   Updated: 2025/01/27 18:10:26 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rotate_a(t_stack **s_a, t_size *size, char *sol, unsigned int block)
{
	int	i;
	int	j;
	int	first;
	int	last;

	first = find_first(s_a, size, block);
	last = find_last(s_a, size, block);
	if (size->size_a - last < first)
		i = last;
	else
		i = first;
	j = i;
	while (j--)
		rotate(s_a);
	sol = optim_rotation_a(size, i, sol);
	return (sol);
}

static char	*actions(t_stack **s_a, t_stack **s_b, char *sol)
{
	if (!(*s_b) || !(*s_b)->next)
		return (sol);
	if ((*s_b)->next->index == (*s_b)->index + 1)
	{
		swap(s_b);
		sol = add_moves(sol, "sb\n", 1);
	}
	else if ((*s_b)->index < (*s_b)->next->index)
	{
		rotate(s_b);
		sol = add_moves(sol, "rb\n", 1);
	}
	if (!(*s_a) || !(*s_a)->next)
		return (sol);
	if ((*s_a)->next->index == (*s_a)->index - 1)
	{
		swap(s_a);
		sol = (add_moves(sol, "sa\n", 1));
	}
	return (sol);
}

static char	*push_a(t_stack **s_a, t_stack **s_b, t_size *size, char *sol)
{
	int	index;
	int	i;

	index = (int)size->size - 1;
	while (index >= 0)
	{
		if ((*s_b)->index == (unsigned int)index)
		{
			push(s_b, s_a, size, 'a');
			sol = add_moves(sol, "pa\n", 1);
			index--;
		}
		else
		{
			i = 0;
			while ((*s_b)->index != (unsigned int)index)
			{
				rotate(s_b);
				i++;
			}
			sol = optim_rotation_b(size, i, sol);
			sol = actions(s_a, s_b, sol);
		}
	}
	return (sol);
}

static char	*push_b(t_stack **s_a, t_stack **s_b, t_size *size, char *sol)
{
	unsigned int	block;
	unsigned int	block_size;
	int				count;

	block_size = 18;
	block = block_size ;
	while (size->size_a)
	{
		count = block_size;
		while (size->size_a && count)
		{
			if ((*s_a)->index < block)
			{
				push(s_a, s_b, size, 'b');
				sol = add_moves(sol, "pb\n", 1);
				count--;
			}
			else
				sol = rotate_a(s_a, size, sol, block);
			sol = actions(s_a, s_b, sol);
		}
		block += block_size;
	}
	return (sol);
}

char	*sort(t_stack **s_a, t_stack **s_b, t_size *size, char *sol)
{
	sol = push_b(s_a, s_b, size, sol);
	sol = push_a(s_a, s_b, size, sol);
	return (sol);
}
