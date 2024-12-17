#include "push_swap.h"

void print_stack(t_stack *stack, int size)
{
    printf("Size: %d\n", size);
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
	//t_stack	*stack_b;
	int		size;

	if (argc > 1)
	{
		//stack_b = NULL;
		if(!check_input(argv + 1))
			exit_error(NULL, NULL);
		stack_a = start_stack(argv);
		size = add_index(stack_a);
		print_stack(stack_a, size);
		free_stack(&stack_a);
	}
	return (0);
}
