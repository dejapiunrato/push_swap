#include "push_swap.h"

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
		stack_a = start_stack(argv);
		stack_b = NULL;
		size = start_size(argc);
		if (!check_order(&stack_a))
		{	
			size = start_size(argc);
			add_index(stack_a, size->bin_pos);
			solution = radix_sort(&stack_a, &stack_b, size);
			ft_putstr(solution);
		}
		free_stack(&stack_a);
		free_stack(&stack_b);
		free(size);
	}
	return (0);
}
