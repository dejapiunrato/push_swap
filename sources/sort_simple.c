#include "push_swap.h"

char	*sort_2(t_stack **stack_a, char *solution)
{
	int	first;
	int	second;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	if (first > second)
	{
		swap(stack_a);
		solution = add_moves(solution, "sa\n", 1);
	}
	return (solution);
}

char	*sort_3(t_stack **stack_a, t_size *size, char *solution)
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
	solution = optim_rotation_a(size, i, solution);
	solution = sort_2(stack_a, solution);
	return (solution);
}

char *sort_4(t_stack **stack_a, t_stack **stack_b, t_size *size, char *solution)
{
	int				i;
	unsigned int 	j;

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
	solution = optim_rotation_a(size, i, solution);
	push(stack_a, stack_b);
	solution = add_moves(solution, "pb\n", 1);
	solution = sort_3(stack_a, size, solution);
	push(stack_b, stack_a);
	solution = add_moves(solution, "pa\n", 1);
	return (solution);
}

char *sort_5(t_stack **stack_a, t_stack **stack_b, t_size *size, char *solution)
{
	int	i;

	i = 0;
	while ((*stack_a)->index != 0)
	{
		rotate(stack_a);
		i++;
	}
	solution = optim_rotation_a(size, i, solution);
	push(stack_a, stack_b);
	solution = add_moves(solution, "pb\n", 1);
	solution = sort_4(stack_a, stack_b, size, solution);
	solution = add_moves(solution, "pa\n", 1);
	return (solution);
}
