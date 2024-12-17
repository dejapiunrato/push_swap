#include "push_swap.h"

t_stack	*start_stack(char **argv)
{
	t_stack		*stack_a;
	int			i;
	long int	num;

	stack_a = NULL;
	i = 1;
	num = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = new_node((int)num);
		else
			add_node_end(&stack_a, new_node((int)num));
		i++;
	}
	add_index(stack_a);
	return (stack_a);
}

void	add_index(t_stack *stack)
{
	t_stack *tmp1;
	t_stack *tmp2;
	int		i;

	tmp1 = stack;
	while (tmp1)
	{
		tmp2 = stack;
		i = 0;
		while (tmp2)
		{
			if (tmp1->value > tmp2->value)
				i++;
			tmp2 = tmp2->next;
		}
		tmp1->index = i;
		tmp1 = tmp1->next;
	}
}
