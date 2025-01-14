#include "push_swap.h"

void	pushes(t_stack **s_a, t_stack **s_b, t_size *size, char stack)
{
	if (stack == 'b')
	{
		push(s_a, s_b);
		size->size_a--;
		size->size_b++;
	}
	else if (stack == 'a')
	{
		push(s_b, s_a);
		size->size_b--;
		size->size_a++;
	}
}

char	*push_b(t_stack **s_a, t_stack **s_b, t_size *size, char *sol)
{
	int	i;
	int	j;

	j = 0;
	size->size = size->size_a;
	while (j < size->size)
	{
		if ((*s_a)->bin[size->bin_pos - 1] == '0' && j++ < size->size)
		{
			pushes(s_a, s_b, size, 'b');
			sol = add_moves(sol, "pb\n", 1);
		}
		else
		{
			i = 0;
			while ((*s_a)->bin[size->bin_pos - 1] == '1' && j++ < size->size)
			{
				rotate(s_a);
				i++;
			}
			sol = optim_rotation_a(size, i, sol);
		}
	}
	return (sol);
}

char	*push_a(t_stack **s_a, t_stack **s_b, t_size *size, char *sol)
{
	int	i;
	int	j;

	j = 0;
	size->size = size->size_b;
	while (j < size->size)
	{
		if ((*s_b)->bin[size->bin_pos - 1] == '1' && j++ < size->size)
		{
			pushes(s_a, s_b, size, 'a');
			sol = add_moves(sol, "pa\n", 1);
		}
		else
		{
			i = 0;
			while ((*s_b)->bin[size->bin_pos - 1] == '0' && j++ < size->size)
			{
				rotate(s_b);
				i++;
			}
			sol = optim_rotation_b(size, i, sol);
		}
	}
	return (sol);
}

char	*radix_sort(t_stack **s_a, t_stack **s_b, t_size *size, char *sol)
{
	while (size->bin_pos > 0)
	{
		sol = push_b(s_a, s_b, size, sol);
		sol = push_a(s_a, s_b, size, sol);
		size->bin_pos--;
	}
	while (size->size_b > 0)
	{
		push(s_b, s_a);
		sol = add_moves(sol, "pa\n", 1);
		size->size_b--;
	}
	return (sol);
}
