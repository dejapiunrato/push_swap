#include "push_swap.h"

t_stack	*start_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int 	num;

	stack_a = NULL;
	i = 1;
	num = 0;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = new_stack(num);
		else
			stack_add_last(&stack_a, new_stack(num));
	}
}
