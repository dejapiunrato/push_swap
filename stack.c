#include "push_swap.h"

t_stack *new_stack(int value)
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

	while (stack)
	{
		tmp = (* stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	get_last_stack()
{

}

void	add_stack_last(t_stack **stack, t_stack *new)
{
	t_stack *tmp;

	if (!stack || !new)
		return ;
	
}
