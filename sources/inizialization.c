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

t_size	*start_size(int	argc)
{
	t_size	*size;

	size = malloc(sizeof(t_size));
	if (!size)
		exit_error(NULL, NULL);
	size->size = argc - 1;
	size->size_a = size->size;
	size->size_b = 0;
	size->bin_pos = bin_len(size->size);
	return (size);
}

int	bin_len(int size)
{
	int		len;

	len = 0;
	while (size)
	{
		size /= 2;
		len++;
	}
	return (len);
}

static char	*add_bin(int index, int bin_len)
{
	char	*bin;
	int		i;

	bin = malloc(sizeof(char) * bin_len);
	if (!bin)
		exit_error(NULL, NULL);
	bin[bin_len] = '\0';
	i = bin_len - 1;
	while (i >= 0)
	{
		bin[i] = (index % 2) + '0';
		index /= 2;
		i--;
	}
	return (bin);
}

void	add_index(t_stack *stack, int bin_len)
{
	t_stack 		*tmp1;
	t_stack 		*tmp2;
	int				i;

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
		tmp1->bin = add_bin(i, bin_len);
		tmp1 = tmp1->next;
	}
}
