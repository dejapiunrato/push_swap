#include "push_swap.h"

long int	ft_atoi(char *s)
{
	int			i;
	long int	num;
	int			neg;

	i = 0;
	num = 0;
	neg = 1;
	if (s[i] == '+')
		i++;
	if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (s[i])
	{
		num = num * 10 + s[i] - '0';
		i++;
	}
	return (num * neg);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
