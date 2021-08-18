#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	i = -1;
	if (s != NULL && f != NULL)
	{
		dst = malloc((ft_strlen(s) + 1) * sizeof(char));
		if (!dst)
			return (NULL);
		while (s[++i])
			dst[i] = f(i, s[i]);
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
