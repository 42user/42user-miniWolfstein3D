#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc((ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	ft_memcpy((void *)s2, (const void *)s1, (ft_strlen(s1) + 1));
	return (s2);
}
