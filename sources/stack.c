#include "push_swap.h"

t_stack *new_node(int value)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	free_stack(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !*stack)
		return ;

	while (*stack)
	{
		tmp = (* stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_stack	*get_last_node(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !*stack)
		return (NULL);
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	add_node_end(t_stack **stack, t_stack *new)
{
	t_stack *last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = get_last_node(stack);
	last->next = new;
}
