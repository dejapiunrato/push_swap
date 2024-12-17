#include "push_swap.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
    printf(CYAN "Stack A" RESET "          " CYAN "Stack B\n" RESET);
    printf(YELLOW "Value | Index" RESET "    " YELLOW "Value | Index\n" RESET);
    printf("-------------    -------------\n");
    while (stack_a || stack_b)
    {
        if (stack_a)
        {
            printf(GREEN "%5d" RESET " | " RED "%5d" RESET, stack_a->value, stack_a->index);
            stack_a = stack_a->next;
        }
        else
        {
            printf("                ");
        }
        if (stack_b)
        {
            printf("    " GREEN "%5d" RESET " | " RED "%5d\n" RESET, stack_b->value, stack_b->index);
            stack_b = stack_b->next;
        }
        else
        {
            printf("\n");
        }
    }
    printf("-------------    -------------\n");
}

int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    int size;

    if (argc > 1)
    {
        if (!check_input(argv + 1))
            exit_error(NULL, NULL);
        stack_a = start_stack(argv);
        size = add_index(stack_a);
        printf(MAGENTA "Size: %d\n" RESET, size);
        printf(BLUE "Initial state:\n" RESET);
        print_stacks(stack_a, stack_b);

        // pb pb pb pb pb
        for (int i = 0; i < 5; i++)
        {
            push_b(&stack_a, &stack_b);
        }
        printf(BLUE "\nAfter pb pb pb pb pb:\n" RESET);
        print_stacks(stack_a, stack_b);

        // sb
        swap_b(&stack_b);
        printf(BLUE "\nAfter sb:\n" RESET);
        print_stacks(stack_a, stack_b);

        // pa pa pa pa pa
        for (int i = 0; i < 5; i++)
        {
            push_a(&stack_a, &stack_b);
        }
        printf(BLUE "\nAfter pa pa pa pa pa:\n" RESET);
        print_stacks(stack_a, stack_b);

        // sa
        swap_a(&stack_a);
        printf(BLUE "\nAfter sa:\n" RESET);
        print_stacks(stack_a, stack_b);

        free_stack(&stack_a);
        free_stack(&stack_b);
    }
    return 0;
}
