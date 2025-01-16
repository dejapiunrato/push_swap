#include "push_swap.h"

static char	*first_last(t_size *size, char *sol, int first, int last)
{
	int	i;
	printf("Size_a: %d | First: %d | Last: %d\n", size->size_a, first, last);
	if (size->size_a - last < first)
		i = last;
	else
		i = first;
	sol = optim_rotation_a(size, i, sol);
	return (sol);
}

static char	*rotate_a(t_stack **s_a, t_size *size, char *sol, unsigned int block)
{
	int	i;
	int	first;
	int	last;

	i = 0;
	while (i <= size->size_a)
	{
		if ((*s_a)->index < block)
		{
			first = i;
			break ;
		}
		rotate(s_a);
		i++;
	}
	last = i + 1;
	while (i <= size->size_a)
	{
		if ((*s_a)->index < block)
			last = i;
		rotate(s_a);
		i++;
	}
	sol = first_last(size, sol, first, last);
	return (sol);
}

static char	*push_b(t_stack **s_a, t_stack **s_b, t_size *size, char *sol)
{
	unsigned int	block;
	int	count;

	block = 5 ;
	while (size->size_a > 0)
	{
		count = 5;
		while (count > 0 && size->size_a > 0)
		{
			if ((*s_a)->index < block)
			{
				push(s_a, s_b);
				sol = add_moves(sol, "pb\n", 1);
				size->size_a--;
				size->size_b++;
				count--;
			}
			else
				sol = rotate_a(s_a, size, sol, block);
		}
		block += 5;
	}
	return (sol);
}

char	*sort(t_stack **s_a, t_stack **s_b, t_size *size, char *sol)
{
	sol = push_b(s_a, s_b, size, sol);
	return (sol);
}
