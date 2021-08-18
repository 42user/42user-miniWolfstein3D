#include "libft.h"

int	c(char **arl)
{
	if (!*arl)
	{
		*arl = gnl_calloc(1, sizeof(*arl));
		if (!*arl)
			return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUF_SIZE + 1];
	char		*arl[4096 + 1];
	char		*tmp;
	int			rb;

	if (BUF_SIZE < 1 || !line || fd < 0 || read(fd, buf, 0) < 0 || c(&arl[fd]))
		return (-1);
	rb = read(fd, buf, BUF_SIZE);
	while (!(subc(arl[fd]) + 1) && rb > 0)
	{
		buf[rb] = '\0';
		arl[fd] = gnl_strjoin(arl[fd], buf);
	}
	*line = gnl_sub(arl[fd], 0, gnl_l(arl[fd], 1));
	if (!(subc(arl[fd]) + 1))
	{
		free(arl[fd]);
		arl[fd] = NULL;
		return (0);
	}
	tmp = arl[fd];
	arl[fd] = gnl_sub(arl[fd], gnl_l(arl[fd], 1) + 1, gnl_l(arl[fd], 0));
	free(tmp);
	return (1);
}
