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
    int bin_len;

    if (argc > 1)
    {
        if (!check_input(argv + 1))
            exit_error(&stack_a, NULL);
        stack_a = start_stack(argv);
        bin_len = add_index(stack_a, argc - 1);
        printf("%d \n", bin_len);
        print_stack(stack_a);
        free_stack(&stack_a);
    }
    else
    {
        printf("Usage: %s <list of numbers>\n", argv[0]);
    }

    return 0;
}
