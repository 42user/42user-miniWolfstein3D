#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*endptr;

	endptr = s + ft_strlen(s);
	if (*endptr == (char)c)
		return ((char *)endptr);
	if (ft_strlen(s) != 0)
	{
		while (endptr > s)
		{
			if (*endptr == (char)c)
				return ((char *)endptr);
			if (*--endptr == (char)c)
				return ((char *)endptr);
		}
	}
	return (NULL);
}
