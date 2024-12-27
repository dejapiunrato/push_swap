#include "push_swap.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

void print_stack(t_stack *stack, char name)
{
    printf(CYAN "Stack %c\n" RESET, name);
    printf(YELLOW "Value | Index | Binary\n" RESET);
    printf("-----------------------\n");
    while (stack)
    {
        printf(GREEN "%5d" RESET " | " RED "%5d" RESET " | " BLUE "%s\n" RESET, stack->value, stack->index, stack->bin);
        stack = stack->next;
    }
    printf("-----------------------\n");
}

int count_lines(const char *str) {
    int line_count = 0;
    for (const char *p = str; *p != '\0'; p++) {
        if (*p == '\n') {
            line_count++;
        }
    }
    return line_count;
}

int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    t_size  *size;
    char *solution;
    FILE *file;
    int line_count_before, line_count_after;

    if (argc > 1)
    {
        if (!check_input(argv + 1))
            exit_error(&stack_a, NULL);
        stack_a = start_stack(argv);
        size = start_size(argc);
        add_index(stack_a, size->bin_pos);
        printf("Initial stack:\n");
        print_stack(stack_a, 'a');
        solution = radix_sort(&stack_a, &stack_b, size);
        printf("%s\n---\n", solution);

        // Contar el número de saltos de línea antes de la optimización
        line_count_before = count_lines(solution);

        solution = optimization(solution);


        // Contar el número de saltos de línea después de la optimización
        line_count_after = count_lines(solution);

        // Guardar solution en un archivo
        file = fopen("test.txt", "w");
        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }
        fprintf(file, "%s", solution);
        fclose(file);

        free_stack(&stack_a);
        free_stack(&stack_b);
        free(size);

        // Imprimir el número de saltos de línea antes y después de la optimización y la diferencia
        printf("Number of lines before optimization: %d\n", line_count_before);
        printf("Number of lines after optimization: %d\n", line_count_after);
        printf("Difference: %d\n", line_count_before - line_count_after);
    }
    else
    {
        printf("Usage: %s <list of numbers>\n", argv[0]);
    }

    return 0;
}
