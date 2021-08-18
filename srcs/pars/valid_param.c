#include "cub3d.h"

static int	parameter_valid(char **params, t_parsed *parsed)
{
	if (ft_strcmp(params[0], "R") == 0)
		valid_resolution(params, parsed);
	else if (ft_strcmp(params[0], "NO") == 0)
		valid_texture(params, parsed, 1);
	else if (ft_strcmp(params[0], "SO") == 0)
		valid_texture(params, parsed, 2);
	else if (ft_strcmp(params[0], "WE") == 0)
		valid_texture(params, parsed, 3);
	else if (ft_strcmp(params[0], "EA") == 0)
		valid_texture(params, parsed, 4);
	else if (ft_strcmp(params[0], "S") == 0)
		valid_texture(params, parsed, 5);
	else if (ft_strcmp(params[0], "F") == 0)
		valid_colour(params, parsed, 1);
	else if (ft_strcmp(params[0], "C") == 0)
		valid_colour(params, parsed, 2);
	else if (params[0][0] == '1' || params[0][0] == '0')
		g_error = 3;
	else
		g_error = 9;
	if (g_error)
		return (0);
	return (1);
}

int	valid_params(t_list **start, t_parsed *parsed)
{
	char	*line;
	char	**params;
	int		res;
	int		n_params;
	t_list	*head;

	res = 0;
	n_params = 0;
	head = *start;
	while (head && n_params < 8)
	{
		line = (char *)head->content;
		if (!(line[0] == '\0'))
		{
			params = ft_split(line, ' ');
			if ((n_params++ != -1) && !params)
				g_error = 2;
			if (g_error || !(parameter_valid(params, parsed)))
				res = -1;
			free_strs(params);
		}
		head = head->next;
	}
	*start = head;
	return (res);
}
