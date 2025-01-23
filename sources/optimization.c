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

char	*replace(char *str, char *old_sub, char *new_sub)
{
	int	count;

	if (!str || !old_sub || !new_sub || ft_strlen(old_sub) == 0)
		return (NULL);
	count = count_occurrences(str, old_sub);
	if (count == 0)
		return (ft_strdup(str));
	return (perform_replacement(str, old_sub, new_sub, count));
}

char *optimization(char *sol)
{
    int len;
    char *tmp;
    t_replacement rules[] = {
        {"ra\nrb\n", "rr\n"},
        {"rb\nra\n", "rr\n"},
        {"sa\nsb\n", "ss\n"},
        {"sb\nsa\n", "ss\n"},
        {"pa\npb\n", "\n"},
        {"pb\npa\n", "\n"},
        {NULL, NULL}
    };

    len = ft_strlen(sol);
    int i = 0;
    while (rules[i].old_sub != NULL) {
        tmp = replace(sol, rules[i].old_sub, rules[i].new_sub);
        free(sol);
        sol = tmp;
        i++;
    }

    if (ft_strlen(sol) != len)
        sol = optimization(sol);
    return (sol);
}
