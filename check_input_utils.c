#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	is_zero(char *s)
{
	int	i;

	i = 0;
	if (is_sign(s[i]))
		i++;
	while (s[i] && s[i] == '0')
		i++;
	if (!s[i])
		return (1);
	return (0);
}

int	cmp_nbr(char *n1, char *n2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (n1[i] == '+')
		i++;
	if (n2[j] == '+')
		j++;
	while (n1[i])
	{
		if (n1[i] != n2[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	is_num(char *s)
{
	int	i;

	i = 0;
	if (is_sign(s[i]))
		i++;
	while (s[i])
	{
		if (!is_digit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
