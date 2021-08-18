#include "libft.h"

static int	ft_arrsz(const char *s, char c)
{
	int		all;

	all = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			all++;
			s++;
		}
		if (*s == c && *s)
			s++;
	}
	return (all);
}

static int	ft_strsz(const char *s, char c)
{
	int		strsz;

	strsz = 0;
	while (*s != c && *s++)
		strsz++;
	return (strsz);
}

void	*ft_arrfree(char **arrstr, int j)
{
	if (j > 0)
	{
		while (j > 0)
			free(arrstr[j--]);
		free(arrstr[j]);
	}
	free(arrstr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arrstr;
	int		j;
	int		k;

	arrstr = (char **)malloc(sizeof(char *) * (ft_arrsz(s, c) + 1));
	if (!s || !arrstr)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			arrstr[j] = (char *)malloc((ft_strsz(s, c) + 1));
			if (!(arrstr[j]))
				return (ft_arrfree(arrstr, j));
			k = 0;
			while (*s != c && *s)
				arrstr[j][k++] = (char)*s++;
			arrstr[j++][k] = '\0';
		}
	}
	arrstr[j] = NULL;
	return (arrstr);
}
