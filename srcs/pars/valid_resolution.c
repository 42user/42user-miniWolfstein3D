#include "cub3d.h"

static int	valid_value(char *str)
{
	size_t	i;
	int		res;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	if (i > 9)
		res = 20000;
	else
		res = ft_atoi(str);
	if (res <= 0)
		return (-1);
	return (res);
}

static void	set_height(int parameter_height, t_parsed *parsed)
{
	if (parameter_height > g_screen_h)
		parsed->res_height = g_screen_h;
	else
		parsed->res_height = parameter_height;
}

static void	set_width(int parameter_width, t_parsed *parsed)
{
	if (parameter_width > g_screen_w)
		parsed->res_width = g_screen_w;
	else
		parsed->res_width = parameter_width;
}

static void	set_zbuffer(t_parsed *parsed)
{
	parsed->zbuffer = (double *)malloc(parsed->res_width * sizeof(double));
	if (parsed->zbuffer == NULL)
		g_error = 2;
}

void	valid_resolution(char **params, t_parsed *parsed)
{
	int		height_param;
	int		width_param;

	if (parsed->res_height || parsed->res_width)
	{
		g_error = 18;
		return ;
	}
	if (!(check_number_params(params, 3)))
	{
		g_error = 10;
		return ;
	}
	width_param = valid_value(params[1]);
	height_param = valid_value(params[2]);
	if ((width_param == -1) || (height_param == -1))
	{
		g_error = 10;
		return ;
	}
	set_width(width_param, parsed);
	set_height(height_param, parsed);
	set_zbuffer(parsed);
}
