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
