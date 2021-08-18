#include "cub3d.h"

static int	list_append(t_list **head, char *line)
{
	char		*line_copy;

	line_copy = ft_strdup(line);
	if (!line_copy)
		return (-1);
	ft_lstadd_back(head, ft_lstnew(line_copy));
	return (0);
}

static int	init_list(int fd, t_list **head)
{
	int			gnl;
	char		*line;

	gnl = 1;
	while (gnl == 1)
	{
		gnl = get_next_line(fd, &line);
		if (gnl == -1)
		{
			ft_lstclear(head, free_str);
			return (-1);
		}
		list_append(head, line);
		free_str(line);
	}
	close(fd);
	return (0);
}

static int	is_cub(char *filepath)
{
	size_t	last;

	last = ft_strlen(filepath) - 1;
	if (filepath[last] == 'b' && filepath[last - 1] == 'u'
		&& filepath[last - 2] == 'c' && filepath[last - 3] == '.')
		return (1);
	g_error = 1;
	return (0);
}

int	parse_file(char *filepath, t_parsed *parsed)
{
	int			fd;
	int			res;
	t_list		*head;

	res = 0;
	fd = 0;
	head = NULL;
	fd = open(filepath, O_RDONLY);
	if ((!(is_cub(filepath))) || (fd == -1) || (init_list(fd, &head) == -1)
		|| (valid_list(parsed, head)) == -1)
		res = 1;
	ft_lstclear(&head, free_str);
	if (fd > 0)
		close(fd);
	if (res)
		return (error_handler());
	return (res);
}
