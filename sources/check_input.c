#include "push_swap.h"

int	is_dup(char **input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		j = i + 1;
		while (input[j])
		{
			if (cmp_nbr(input[i], input[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//añadir liberar stacks.
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a || *stack_a)
		free_stack(stack_a);
	if (stack_b || *stack_b)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

int	check_input(char **input)
{
	int	i;
	int	zeros;

	i = 0;
	zeros = 0;
	while (input[i])
	{
		if (!is_num(input[i]))
			return (0);
		zeros += is_zero(input[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	if (is_dup(input))
		return (0);
	return (1);
}
