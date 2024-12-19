#include "push_swap.h"

static void	rotate(t_stack	**stack)
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

void	rotate_a(t_stack **stack)
{
	rotate(stack);
	ft_putstr("ra\n");
}

void	rotate_b(t_stack **stack)
{
	rotate(stack);
	ft_putstr("rb\n");
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
