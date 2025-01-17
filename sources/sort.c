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

static char	*rotate_a(t_stack **s_a, t_size *size, char *sol, unsigned int block)
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

static char *push_a(t_stack **s_a, t_stack **s_b, t_size *size, char *sol)
{
	int	index;
	int	i;

	index = (int)size->size - 1;

	while (index)
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
		}
	}
	sol = add_moves(sol, "pa\n", 1);
	return (sol);
}

static char	*push_b(t_stack **s_a, t_stack **s_b, t_size *size, char *sol)
{
	unsigned int	block;
	unsigned int	block_size;
	int				count;

	block_size = 18; // 18 para 100 números
	block = block_size ;
	while (size->size_a > 5)
	{
		count = block_size;
		while (count && size->size_a)
		{
			if ((*s_a)->index < block)
			{
				push(s_a, s_b, size, 'b');
				sol = add_moves(sol, "pb\n", 1);
				count--;
			}
			else
				sol = rotate_a(s_a, size, sol, block);
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
