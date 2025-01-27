/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:44:50 by psevilla          #+#    #+#             */
/*   Updated: 2025/01/27 17:45:52 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strjoin(char *s1, char *s2)
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

char	*ft_strdup(char *s)
{
	size_t	size;
	char	*d;
	char	*aux;

	size = ft_strlen(s) + 1;
	d = malloc(size);
	if (!d)
		exit_error(NULL, NULL);
	aux = d;
	while (*s)
		*d++ = *s++;
	*d = '\0';
	return (aux);
}
