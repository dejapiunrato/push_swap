#include "push_swap.h"

void	sort_2(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = (*stack)->next;
	if (first->index < second->index)
		return ;
	else
		swap_a(stack);
}
/* 
max[0] = Indice máximo
max[1] = posición del índice máximo
max[2] = ordenado(1) o desordenado(0)
max[3] = tamaño del stack
*/
void	sort_3(t_stack **stack)
{
	unsigned int	*max;

	max = check_order_return_max(stack, 3);
	if (max[2]) // Está ordenado
	{
		free(max);
		return ;
	}
	if (max[1] == 0) // El mayor está arriba
		rotate_a(stack);
	else if (max[1] == 1) // El mayor está en el medio
		reverse_rotate_a(stack);
	sort_2(stack);
	free (max);
}

/* 
min[0] = Indice mínimo
min[1] = posición del índice mínimo
min[2] = ordenado(1) o desordenado(0)
min[3] = tamaño del stack
*/
void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int	*min;

	min = check_order_return_min(stack_a, 4);
	int i = 0;
	while (i < 4)
	{
		printf("%d | ", min[i]);
		i++;
	}
	printf("\n");
	if (min[2])
	{
		free(min);
		return ;
	}
	if (min[1] == 1 || min[1] == 2) // El menor está en el medio
		rotate_a(stack_a);
	else if (min[1] == 2) // El menor está en tercera posición
		rotate_a(stack_a);
	else if (min[1] == 3)
		reverse_rotate_a(stack_a);
	push_b(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
	free(min);
}
