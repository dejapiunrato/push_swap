#include "push_swap.h"

char	*parse(t_stack **stack_a, t_stack **stack_b, t_size *size, char *sol)
{
	int	i;

	i = size->size;
	if (i == 2)
		sol = s_2(stack_a, sol);
	else if (i == 3)
		sol = s_3(stack_a, size, sol);
	else if (i == 4)
		sol = s_4(stack_a, stack_b, size, sol);
	else if (i == 5)
		sol = s_5(stack_a, stack_b, size, sol);
	else
		sol = sort(stack_a, stack_b, size, sol);
	return (sol);
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b, t_size **size)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(*size);
	*size = NULL;
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
			free_stacks(&stack_a, &stack_b, &size);
		}
	}
	return (0);
}

/* int	main(int argc, char **argv)
{
    char	*solution;
    t_stack	*stack_a;
    t_stack	*stack_b;
    t_size	*size;
    FILE	*file;

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
                file = fopen("solution.txt", "w");
                if (file)
                {
                    fprintf(file, "%s", solution);
                    fclose(file);
                }
                free(solution);
            }
            free_stacks(&stack_a, &stack_b, &size);
        }
    }
	return (0);
}
 */
