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
	i = size->size_a - i;
	j = i;
	while (j--)
		rotate(s_a);
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
	printf("%d, %d, \n", first, last);
	sol = optim_rotation_a(size, i, sol);
	return (sol);
}

static char	*push_b(t_stack **s_a, t_stack **s_b, t_size *size, char *sol)
{
	unsigned int	block;
	unsigned int	block_size;
	int				count;

	block_size = 3;
	block = block_size ;
	while (size->size_a > 0)
	{
		count = block_size;
		while (count > 0 || size->size_a > 0)
		{
			/* printf("%d | ", (*s_a)->value); */
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
	return (sol);
}
