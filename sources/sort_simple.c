#include "push_swap.h"

char	*s_2(t_stack **stack_a, char *sol)
{
	int	first;
	int	second;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	if (first > second)
	{
		swap(stack_a);
		sol = add_moves(sol, "sa\n", 1);
	}
	return (sol);
}

char	*s_3(t_stack **stack_a, t_size *size, char *sol)
{
	int				i;
	unsigned int	max;
	t_stack			*last;

	i = 0;
	max = find_max_a(stack_a);
	last = get_last_node(stack_a);
	while (last->index != max)
	{
		rotate(stack_a);
		last = get_last_node(stack_a);
		i++;
	}
	sol = optim_rotation_a(size, i, sol);
	sol = s_2(stack_a, sol);
	return (sol);
}

char	*s_4(t_stack **stack_a, t_stack **s_b, t_size *size, char *sol)
{
	int				i;
	unsigned int	min;

	min = find_min_a(stack_a, size);
	while ((*stack_a)->index != min)
	{
		rotate(stack_a);
		i++;
	}
	sol = optim_rotation_a(size, i, sol);
	push(stack_a, s_b, size, 'b');
	sol = add_moves(sol, "pb\n", 1);
	sol = s_3(stack_a, size, sol);
	push(s_b, stack_a, size, 'a');
	sol = add_moves(sol, "pa\n", 1);
	return (sol);
}

char	*s_5(t_stack **stack_a, t_stack **s_b, t_size *size, char *sol)
{
	int				i;
	unsigned int	min;

	i = 0;
	min = find_min_a(stack_a, size);
	while ((*stack_a)->index != min)
	{
		rotate(stack_a);
		i++;
	}
	sol = optim_rotation_a(size, i, sol);
	push(stack_a, s_b, size, 'b');
	sol = add_moves(sol, "pb\n", 1);
	sol = s_4(stack_a, s_b, size, sol);
	sol = add_moves(sol, "pa\n", 1);
	return (sol);
}
