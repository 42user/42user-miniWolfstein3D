#include "cub3d.h"

int	check_args(int argc, char **argv, t_all *all)
{
	if (argc == 2)
	{
		all->save = 0;
		return (1);
	}
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") != 0)
		{
			g_error = 8;
			error_handler();
			return (0);
		}
		all->save = 1;
		return (1);
	}
	g_error = 19;
	error_handler();
	return (0);
}

int	check_number_params(char **params, size_t num_params)
{
	size_t	count;

	count = 0;
	while (params[count])
		count++;
	if (count != num_params)
		return (0);
	return (1);
}

static void	set_path(char *path, int flag, t_parsed *parsed)
{
	if ((flag == 1) && (parsed->north_path))
		g_error = 18;
	else if (flag == 1)
		parsed->north_path = path;
	else if ((flag == 2) && (parsed->south_path))
		g_error = 18;
	else if (flag == 2)
		parsed->south_path = path;
	else if ((flag == 3) && (parsed->west_path))
		g_error = 18;
	else if (flag == 3)
		parsed->west_path = path;
	else if ((flag == 4) && (parsed->east_path))
		g_error = 18;
	else if (flag == 4)
		parsed->east_path = path;
	else if ((flag == 5) && (parsed->sprite_path))
		g_error = 18;
	else if (flag == 5)
		parsed->sprite_path = path;
}

static int	is_xpm(char *path)
{
	int		last_char;

	last_char = ft_strlen(path) - 1;
	if ((path[last_char] == 'm')
		&& (path[last_char - 1] == 'p')
		&& (path[last_char - 2] == 'x')
		&& (path[last_char - 3] == '.'))
		return (1);
	return (0);
}

void	valid_texture(char **params, t_parsed *parsed, int flag)
{
	char	*path;
	int		fd_check;

	if (!(check_number_params(params, 2)))
	{
		g_error = 14;
		return ;
	}
	path = ft_strdup(params[1]);
	if (!path)
		g_error = 2;
	if (!(is_xpm(path)))
		g_error = 16;
	if (g_error)
		return ;
	fd_check = open(path, O_RDONLY);
	if (fd_check == -1)
	{
		g_error = 11;
		return ;
	}
	close(fd_check);
	set_path(path, flag, parsed);
}
