/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:44:33 by psevilla          #+#    #+#             */
/*   Updated: 2025/01/30 16:46:10 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_occurrences(char *str, char *old_sub)
{
	int		count;
	char	*tmp;
	char	*insert_point;

	count = 0;
	insert_point = str;
	tmp = ft_strstr(insert_point, old_sub);
	while (tmp)
	{
		count++;
		insert_point = tmp + ft_strlen(old_sub);
		tmp = ft_strstr(insert_point, old_sub);
	}
	return (count);
}

static char	*perform_replacement(char *str, char *old_s, char *new_s, int count)
{
	char	*result;
	char	*tmp;
	int		len_front;
	size_t	len;

	len = ft_strlen(str) + count * (ft_strlen(new_s) - ft_strlen(old_s) + 1);
	result = (char *)malloc(len);
	if (!result)
		return (NULL);
	tmp = result;
	while (count--)
	{
		len_front = ft_strstr(str, old_s) - str;
		tmp = ft_strncpy(tmp, str, len_front) + len_front;
		tmp = ft_strcpy(tmp, new_s) + ft_strlen(new_s);
		str = ft_strstr(str, old_s) + ft_strlen(old_s);
	}
	ft_strcpy(tmp, str);
	return (result);
}

static char	*replace(char *str, char *old_sub, char *new_sub)
{
	int	count;

	if (!str || !old_sub || !new_sub || ft_strlen(old_sub) == 0)
		return (NULL);
	count = count_occurrences(str, old_sub);
	if (count == 0)
		return (ft_strdup(str));
	return (perform_replacement(str, old_sub, new_sub, count));
}

static void	start_rules(t_replacement *rules)
{
	rules[0].old_sub = "\nra\npb\nrra\npa\n"; //ra pb rra pa
	rules[0].new_sub = "\nsa\n"; // sa

	rules[1].old_sub = "\nrb\npa\nrrb\npb\n"; // rb pa rrb pb
	rules[1].new_sub = "\nsb\n";

	rules[2].old_sub = "ra\nrb\n"; // ra rb
	rules[2].new_sub = "rr\n"; // rr

	rules[3].old_sub = "rb\nra\n"; // rb ra
	rules[3].new_sub = "rr\n"; // rr

	rules[4].old_sub = "rra\nrrb\n"; // rra rrb
	rules[4].new_sub = "rrr\n"; // rrr

	rules[5].old_sub = "rrb\nrra\n"; // rrb rra
	rules[5].new_sub = "rrr\n"; // rrr

	rules[6].old_sub = "sa\nsb\n"; // sa sb
	rules[6].new_sub = "ss\n"; // ss

	rules[7].old_sub = "sb\nsa\n"; //sb sa
	rules[7].new_sub = "ss\n"; // ss

	rules[8].old_sub = "\npa\npb\n"; // pa pb
	rules[8].new_sub = "\n"; // X

	rules[9].old_sub = "\npb\npa\n"; // pb pa
	rules[9].new_sub = "\n"; // X
	
	rules[10].old_sub = NULL;
	rules[10].new_sub = NULL;
}

char	*optimization(char *sol)
{
	int				i;
	int				len;
	char			*tmp;
	t_replacement	rules[11];

	i = 0;
	len = ft_strlen(sol);
	start_rules(rules);
	while (rules[i].old_sub != NULL)
	{
		tmp = replace(sol, rules[i].old_sub, rules[i].new_sub);
		free(sol);
		sol = tmp;
		i++;
	}
	if (ft_strlen(sol) < len)
		sol = optimization(sol);
	return (sol);
}
