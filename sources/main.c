#include "push_swap.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define WHITE "\033[37m"

void print_stack_values(t_stack *stack)
{
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->index > stack->next->index)
            return 0;
        stack = stack->next;
    }
    return 1;
}

void test_sort_4(char **argv, int test_num)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    stack_a = start_stack(argv);
    add_index(stack_a);

    // Test sort_4
    sort_4(&stack_a, &stack_b);

    if (is_sorted(stack_a))
    {
        printf(WHITE "Test %d: " RESET "["GREEN "OK" RESET"]\n", test_num);
    }
    else
    {
        printf(WHITE "Test %d: " RESET "["RED "KO" RESET"]\n", test_num);
        printf("Stack to sort: ");
        print_stack_values(stack_a);
        printf("Resulting stack: ");
        print_stack_values(stack_a);
    }

    free_stack(&stack_a);
    free_stack(&stack_b);
}

int main(void)
{
    char *test_cases[][6] = {
        {"./push_swap", "1", "2", "3", "4", NULL},
        {"./push_swap", "1", "2", "4", "3", NULL},
        {"./push_swap", "1", "3", "2", "4", NULL},
        {"./push_swap", "1", "3", "4", "2", NULL},
        {"./push_swap", "1", "4", "2", "3", NULL},
        {"./push_swap", "1", "4", "3", "2", NULL},
        {"./push_swap", "2", "1", "3", "4", NULL},
        {"./push_swap", "2", "1", "4", "3", NULL},
        {"./push_swap", "2", "3", "1", "4", NULL},
        {"./push_swap", "2", "3", "4", "1", NULL},
        {"./push_swap", "2", "4", "1", "3", NULL},
        {"./push_swap", "2", "4", "3", "1", NULL},
        {"./push_swap", "3", "1", "2", "4", NULL},
        {"./push_swap", "3", "1", "4", "2", NULL},
        {"./push_swap", "3", "2", "1", "4", NULL},
        {"./push_swap", "3", "2", "4", "1", NULL},
        {"./push_swap", "3", "4", "1", "2", NULL},
        {"./push_swap", "3", "4", "2", "1", NULL},
        {"./push_swap", "4", "1", "2", "3", NULL},
        {"./push_swap", "4", "1", "3", "2", NULL},
        {"./push_swap", "4", "2", "1", "3", NULL},
        {"./push_swap", "4", "2", "3", "1", NULL},
        {"./push_swap", "4", "3", "1", "2", NULL},
        {"./push_swap", "4", "3", "2", "1", NULL}
    };

    for (int i = 0; i < 24; i++)
    {
        test_sort_4(test_cases[i], i + 1);
    }

    return 0;
}
