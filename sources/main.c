#include "push_swap.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

void print_stack(t_stack *stack)
{
    printf(CYAN "Stack:\n" RESET);
    printf(YELLOW "Value | Index | Binary\n" RESET);
    printf("-----------------------\n");
    while (stack)
    {
        printf(GREEN "%5d" RESET " | " RED "%5d" RESET " | " BLUE "%s\n" RESET, stack->value, stack->index, stack->bin);
        stack = stack->next;
    }
    printf("-----------------------\n");
}

int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    t_size  *size;
    if (argc > 1)
    {
        if (!check_input(argv + 1))
            exit_error(&stack_a, NULL);
        stack_a = start_stack(argv);
        size = start_size(argc);
        add_index(stack_a, size->bin_pos);
        printf("Initial stack:\n");
        print_stack(stack_a);
        radix_sort(&stack_a, &stack_b, size);
        printf("Sorted stack:\n");
        print_stack(stack_a);
        print_stack(stack_b);
        free_stack(&stack_a);
        free_stack(&stack_b);
        free(size);
    }
    else
    {
        printf("Usage: %s <list of numbers>\n", argv[0]);
    }

    return 0;
}
