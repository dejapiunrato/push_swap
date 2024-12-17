#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	swap_a(t_stack **stack)
{
	swap(*stack);
	ft_putstr("sa\n");
}

void	swap_b(t_stack **stack)
{
	swap(*stack);
	ft_putstr("sb\n");
}

void swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
