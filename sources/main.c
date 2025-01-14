#include "push_swap.h"

char	*parse(t_stack **stack_a, t_stack **stack_b, t_size *size, char *solution)
{
	int	i;

	i = size->size;
	if (i == 2)
		solution = sort_2(stack_a, solution);
	else if (i == 3)
		solution = sort_3(stack_a, size, solution);
	else if (i == 4)
		solution = sort_4(stack_a, stack_b, size, solution);
	else if (i == 5)
		solution = sort_5(stack_a, stack_b, size, solution);
	else
		solution = radix_sort(stack_a, stack_b, size, solution);	
	return (solution);
}

int	main(int argc, char **argv)
{
	char	*solution;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_size	*size;

	if (argc > 1)
	{
		if (!check_input(argv + 1))
			exit_error(&stack_a, NULL);
		else 
		{
			stack_a = start_stack(argv);
			stack_b = NULL;
			size = start_size(argc);
			add_index(stack_a, size->bin_pos);
			if (!check_order(&stack_a))
			{	
				solution = parse(&stack_a, &stack_b, size, ft_strdup(""));
				ft_putstr(solution);
				free(solution);
			}
			free_stack(&stack_a);
			free_stack(&stack_b);
			free(size);
		}
	}
	return (0);
}
