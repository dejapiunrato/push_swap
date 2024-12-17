#include "push_swap.h"

void print_stack(t_stack *stack)
{
    printf("Stack:\n");
    printf("Value | Index\n");
    printf("-------------\n");
    while (stack)
    {
        printf("%5d | %5d\n", stack->value, stack->index);
        stack = stack->next;
    }
    printf("-------------\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc > 1)
	{		
		if(!check_input(argv + 1))
			exit_error(NULL, NULL);
		stack_a = start_stack(argv);
		print_stack(stack_a);
		free_stack(&stack_a);
	}
	return (0);
}
