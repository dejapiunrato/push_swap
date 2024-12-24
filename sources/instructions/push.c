#include "push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

char	*push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	return ("pa\n");
}

char	*push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	return ("pb\n");
}
