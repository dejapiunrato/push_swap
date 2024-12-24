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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		exit_error(NULL, NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
