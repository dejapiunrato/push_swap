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
	unsigned int	j;
	t_stack			*last;

	i = 0;
	last = get_last_node(stack_a);
	if (size->size == 3)
		j = 2;
	else if (size->size == 4)
		j = 3;
	else
		j = 4;
	while (last->index != j)
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
	unsigned int	j;

	if (size->size == 5)
		j = 1;
	else
		j = 0;
	i = 0;
	while ((*stack_a)->index != j)
	{
		rotate(stack_a);
		i++;
	}
	sol = optim_rotation_a(size, i, sol);
	push(stack_a, s_b);
	sol = add_moves(sol, "pb\n", 1);
	sol = s_3(stack_a, size, sol);
	push(s_b, stack_a);
	sol = add_moves(sol, "pa\n", 1);
	return (sol);
}

char	*s_5(t_stack **stack_a, t_stack **s_b, t_size *size, char *sol)
{
	int	i;

	i = 0;
	while ((*stack_a)->index != 0)
	{
		rotate(stack_a);
		i++;
	}
	sol = optim_rotation_a(size, i, sol);
	push(stack_a, s_b);
	sol = add_moves(sol, "pb\n", 1);
	sol = s_4(stack_a, s_b, size, sol);
	sol = add_moves(sol, "pa\n", 1);
	return (sol);
}
