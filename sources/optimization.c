/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:44:33 by psevilla          #+#    #+#             */
/*   Updated: 2025/02/04 18:39:26 by psevilla         ###   ########.fr       */
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
	rules[0] = (t_replacement){"\nra\npb\nrra\npa\n", "\nsa\n"};
	rules[1] = (t_replacement){"\npb\npb\nra\npa\nrra\npa\n", "\nsa\n"};
	rules[2] = (t_replacement){"\npb\npb\nsb\npa\npa\n", "\nsa\n"};
	rules[3] = (t_replacement){"\nrb\npa\nrrb\npb\n", "\nsb\n"};
	rules[4] = (t_replacement){"\npa\npa\nrb\npb\nrrb\npb\n", "\nsb\n"};
	rules[5] = (t_replacement){"\npa\npa\nsa\npb\npb\n", "\nsb\n"};
	rules[6] = (t_replacement){"ra\nrb\n", "rr\n"};
	rules[7] = (t_replacement){"rb\nra\n", "rr\n"};
	rules[8] = (t_replacement){"rra\nrrb\n", "rrr\n"};
	rules[9] = (t_replacement){"rrb\nrra\n", "rrr\n"};
	rules[10] = (t_replacement){"sa\nsb\n", "ss\n"};
	rules[11] = (t_replacement){"sb\nsa\n", "ss\n"};
	rules[12] = (t_replacement){"\npa\npb\n", "\n"};
	rules[13] = (t_replacement){"\npb\npa\n", "\n"};
	rules[14] = (t_replacement){NULL, NULL};
}

char	*optimization(char *sol)
{
	int				i;
	int				len;
	char			*tmp;
	t_replacement	rules[15];

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
