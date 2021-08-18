#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	size_t			l;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	l = ft_strlen(needle);
	while (*haystack != '\0')
	{
		if (i + l > len)
			return (NULL);
		if (ft_strncmp(haystack, needle, l) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
