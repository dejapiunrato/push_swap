#include "push_swap.h"

char	*optim_rotation_a(t_size *size, int i, char *solution)
{
	char	*rot;

	if (i == size->size_a)
		return (solution);
	if (i <= size->size_a / 2)
		rot = ft_strdup("ra\n");
	else
	{
		rot = ft_strdup("rra\n");
		i = size->size_a - i;
	}
	solution = add_moves(solution, rot, i);
	free(rot);
	return (solution);
}

char	*optim_rotation_b(t_size *size, int i, char *solution)
{
	char	*rot;

	if (i == size->size_b)
		return (solution);
	if (i <= size->size_b / 2)
		rot = ft_strdup("rb\n");
	else
	{
		rot = ft_strdup("rrb\n");
		i = size->size_b - i;
	}
	solution = add_moves(solution, rot, i);
	free(rot);
	return (solution);
}

char	*add_moves(char *solution, char *moves, int i)
{
	char	*tmp;

	while (i > 0)
	{
		tmp = solution;
		solution = ft_strjoin(tmp, moves);
		free(tmp);
		i--;
	}
	return (solution);
}

int	find_min_a(t_stack **s_a, t_size *size)
{
	unsigned int	min;
	t_stack			*tmp;

	min = size->size_a;
	tmp = *s_a;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int	find_max_a(t_stack **s_a)
{
	unsigned int	max;
	t_stack			*tmp;

	max = 0;
	tmp = *s_a;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}
