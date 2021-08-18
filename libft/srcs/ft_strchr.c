#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		if (*s++ == (char)c)
			return ((char *)s);
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
