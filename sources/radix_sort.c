#include "push_swap.h"

char	*optim_rotation_a(t_size *size, int i, char *solution)
{
	char	*rot;

	if (i == size->size_a)
		return (solution);
	if (i <= size->size_a / 2)
		rot = ft_strdup("ra\n");
	else
	{
		rot = ft_strdup("rra\n");
		i = size->size_a - i;
	}
	solution = add_moves(solution, rot, i);
	return (solution);
}

char	*optim_rotation_b(t_size *size, int i, char *solution)
{
	char	*rot;

	if (i == size->size_b)
		return (solution);
	if (i <= size->size_b / 2)
		rot = ft_strdup("rb\n");
	else
	{
		rot = ft_strdup("rrb\n");
		i = size->size_b - i;
	}
	solution = add_moves(solution, rot, i);
	return (solution);
}

char	*add_moves(char *solution, char *moves, int i)
{
	char	*tmp;

	while (i > 0)
	{
		tmp = solution;
		solution = ft_strjoin(tmp, moves);
		free(tmp);
		i--;
	}
	return (solution);
}

char	*move_to_b(t_stack **stack_a, t_stack **stack_b, t_size *size, char *solution)
{
	int	i;
	int	j;

	j = 0;
	size->size = size->size_a;
	while (j < size->size)
	{
		if ((*stack_a)->bin[size->bin_pos - 1] == '0' && j++ < size->size)
		{
			push(stack_a, stack_b);
			solution = add_moves(solution, "pb\n", 1);
			size->size_a--;
			size->size_b++;
		}
		else 
		{
			i = 0;
			while ((*stack_a)->bin[size->bin_pos - 1] == '1' && j++ < size->size)
			{
				rotate(stack_a);
				i++;
			}
			solution = optim_rotation_a(size, i, solution);
		}
	}
	return (solution);
}

char	*move_to_a(t_stack **stack_a, t_stack **stack_b, t_size *size, char *solution)
{
	int	i;
	int	j;

	j = 0;
	size->size = size->size_b;
	while (j < size->size)
	{
		if ((*stack_b)->bin[size->bin_pos - 1] == '1' && j++ < size->size)
		{
			push(stack_b, stack_a);
			solution = add_moves(solution, "pa\n", 1);
			size->size_b--;
			size->size_a++;
		}
		else
		{
			i = 0;
			while ((*stack_b)->bin[size->bin_pos - 1] == '0' && j++ < size->size)
			{
				rotate(stack_b);
				i++;
			}
			solution = optim_rotation_b(size, i, solution);
		}
	}
	return (solution);
}

char *radix_sort(t_stack **stack_a, t_stack **stack_b, t_size *size)
{
	char *solution = ft_strdup("");

	while (size->bin_pos > 0)
	{
		solution = move_to_b(stack_a, stack_b, size, solution);
		solution = move_to_a(stack_a, stack_b, size, solution);
		size->bin_pos--;
	}
	while (size->size_b > 0)
	{
		push(stack_b, stack_a);
		solution = add_moves(solution, "pa\n", 1);
		size->size_b--;
	}
	printf("%s", solution);
	return(solution);
}
