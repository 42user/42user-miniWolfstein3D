#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;

	d = b;
	while (len--)
		*d++ = (unsigned char)c;
	return (b);
}
