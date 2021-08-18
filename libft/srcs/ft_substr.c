#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if ((s == NULL) || len <= 0 || ft_strlen(s) <= start)
		return (ft_strdup("\0"));
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	while (len--)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
