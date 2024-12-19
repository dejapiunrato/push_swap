#include "push_swap.h"

static int	*init_array(t_stack **stack)
{
	int	*arr;

	arr = (int *)malloc(4 * sizeof(int));
	if (!arr)
		exit_error(stack, NULL);
	arr[0] = (*stack)->index;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;

	return (arr);
}

/* devuelve el índice máximo, su posición y si está ordenado el stack.
max[0] = Indice máximo
max[1] = posición del índice máximo
max[2] = ordenado(1) o desordenado(0)
max[3] = tamaño */
int	*check_order_return_max(t_stack **stack, int size)
{
	int		*max;
	t_stack	*tmp;
	int		i;

	max = init_array(stack);
	tmp = *stack;
	i = 1;
	while(tmp->next)
	{
		if (tmp->index < tmp->next->index)
			i++;
		if (tmp->index > max[0])
		{
			max[0] = tmp->index;
			max[1] = max[3];
		}
		max[3]++;
		tmp = tmp->next;
	}
	if (tmp->index > max[0])
	{
		max[0] = tmp->index;
		max[1] = max[3];
	}
	if (i == size)
		max[2] = 1;
	return(max);
}

int	*check_order_return_min(t_stack **stack, int size)
{
	int		*min;
	t_stack	*tmp;
	int		i;

	min = init_array(stack);
	tmp = *stack;
	i = 1;
	while(tmp->next)
	{
		if (tmp->index < tmp->next->index)
			i++;
		if (tmp->index < min[0])
		{
			min[0] = tmp->index;
			min[1] = min[3];
		}
		min[3]++;
		tmp = tmp->next;
	}
	if (tmp->index < min[0])
	{
		min[0] = tmp->index;
		min[1] = min[3];
	}
	if (i == size)
		min[2] = 1;
	return (min);
}
