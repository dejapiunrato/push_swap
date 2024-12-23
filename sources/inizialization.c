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
	return (stack_a);
}

static char	*ft_bin(unsigned int index)
{
	char	*bin;
	int		i;

	bin = malloc(sizeof(char) * 33);
	if (!bin)
		exit_error(NULL, NULL);
	bin[32] = '\0';
	i = 31;
	while (i >= 0)
	{
		bin[i] = (index % 2) + '0';
		index /= 2;
		i--;
	}
	return (bin);
}

unsigned int	add_index(t_stack *stack)
{
	t_stack 		*tmp1;
	t_stack 		*tmp2;
	unsigned int	size;
	unsigned int	i;

	tmp1 = stack;
	size = 0;
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
		tmp1->bin = ft_bin(i);
		tmp1 = tmp1->next;
		size++;
	}
	return (size);
}
