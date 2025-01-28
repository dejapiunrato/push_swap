/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:44:33 by psevilla          #+#    #+#             */
/*   Updated: 2025/01/28 17:22:41 by psevilla         ###   ########.fr       */
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
	rules[0].old_sub = "ra\npb\nrra\npa\n";
	rules[0].new_sub = "sa\n";
	rules[1].old_sub = "rb\npa\nrrb\npb\n";
	rules[1].new_sub = "sb\n";
	rules[2].old_sub = "ra\nrb\n";
	rules[2].new_sub = "rr\n";
	rules[3].old_sub = "rb\nra\n";
	rules[3].new_sub = "rr\n";
	rules[4].old_sub = "rra\nrrb\n";
	rules[4].new_sub = "rrr\n";
	rules[5].old_sub = "rrb\nrra\n";
	rules[5].new_sub = "rrr\n";
	rules[6].old_sub = "sa\nsb\n";
	rules[6].new_sub = "ss\n";
	rules[7].old_sub = "sb\nsa\n";
	rules[7].new_sub = "ss\n";
	rules[8].old_sub = "\npa\npb\n";
	rules[8].new_sub = "\n";
	rules[9].old_sub = "\npb\npa\n";
	rules[9].new_sub = "\n";
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
