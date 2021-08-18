#include "libft.h"

void	*gnl_calloc(size_t count, size_t size)
{
	char	*d;
	char	*p;
	size_t	nb;

	nb = count * size;
	p = malloc(nb);
	if (!p)
		return (NULL);
	d = p;
	while (nb--)
		*p++ = '\0';
	return (d);
}

int	subc(char *arl)
{
	int	i;

	i = 0;
	while (arl[i])
		if (arl[i++] == '\n')
			return (--i);
	return (-1);
}

size_t	gnl_l(char *s, int flag_n)
{
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n' && flag_n)
			return (--i);
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*s;
	char	*new;
	char	*old;

	s = malloc(gnl_l(s1, 0) + gnl_l(s2, 0) + 1);
	if (!s1 || !s2 || !s)
		return (NULL);
	new = s;
	old = s1;
	while (*s1)
		*s++ = *s1++;
	while (*s2)
		*s++ = *s2++;
	*s = '\0';
	free(old);
	return (new);
}

char	*gnl_sub(char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*new;

	str = malloc(len + 1);
	if (!s || start > gnl_l(s, 0) || !str)
		return (NULL);
	new = str;
	while (s[start] && len--)
		*str++ = s[start++];
	*str = '\0';
	return (new);
}
