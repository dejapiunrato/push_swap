#include "push_swap.h"

void	push(t_stack **src, t_stack **dest, t_size *size, char stack)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	if (stack == 'a')
	{
		size->size_a++;
		size->size_b--;
	}
	else
	{
		size->size_a--;
		size->size_b++;
	}
}

void	reverse_rotate(t_stack **stack)
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

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}
