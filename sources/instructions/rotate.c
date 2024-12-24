#include "push_swap.h"

void	rotate(t_stack	**stack)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = get_last_node(stack);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	last->next = tmp;
}

char	*rotate_a(t_stack **stack)
{
	rotate(stack);
	return ("ra\n");
}

char	*rotate_b(t_stack **stack)
{
	rotate(stack);
	return ("rb\n");
}

char	*rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	return ("rr\n");
}
