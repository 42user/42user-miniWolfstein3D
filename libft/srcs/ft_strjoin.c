#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s;
	char		*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	join = s;
	if (s != NULL)
	{
		while (*s1)
			*s++ = *s1++;
		while (*s2)
			*s++ = *s2++;
		*s = '\0';
	}
	return (join);
}
