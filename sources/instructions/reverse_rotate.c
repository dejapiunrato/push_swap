#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

char	*reverse_rotate_a(t_stack **stack)
{
	reverse_rotate(stack);
	return ("rra\n");
}

char	*reverse_rotate_b(t_stack **stack)
{
	reverse_rotate(stack);
	return ("rrb\n");
}

char	*reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return ("rrr\n");
}
