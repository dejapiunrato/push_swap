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
