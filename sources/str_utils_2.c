#include "push_swap.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	if (*s2 == 0)
		return ((char *)s1);
	j = 0;
	while (s1[j])
	{
		if (s1[j] == s2[0])
		{
			i = 0;
			while (s1[j + i] == s2[i] && s2[i])
				i++;
			if (s2[i] == 0)
				return ((char *) &s1[j]);
		}
		j++;
	}
	return (NULL);
}

char	*ft_strcpy(char *s1, char *s2)
{
	char	*ptr;

	ptr = s1;
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (ptr);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
