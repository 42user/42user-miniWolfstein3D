#include <cub3d.h>

static int	invalid_chars(char *colour_str)
{
	size_t		i;

	i = 0;
	while (colour_str[i])
	{
		if ((colour_str[i] != ',')
			&& (!(colour_str[i] >= '0' && colour_str[i] <= '9')))
		{
			g_error = 15;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	valid_colour_value(char *str)
{
	int		res;

	res = ft_atoi(str);
	if ((res < 0) || (res > 255))
		return (-1);
	return (res);
}

static void	valid_rgb(char **rgb_str, t_parsed *parsed, int flag)
{
	int		r;
	int		g;
	int		b;
	int		rgb;

	r = valid_colour_value(rgb_str[0]);
	g = valid_colour_value(rgb_str[1]);
	b = valid_colour_value(rgb_str[2]);
	if ((r == -1) || (g == -1) || (b == -1))
	{
		g_error = 15;
		return ;
	}
	rgb = 0;
	rgb = (r << 16 | g << 8 | b);
	if ((flag == 1) && (parsed->flr_colour))
		g_error = 18;
	else if (flag == 1)
		parsed->flr_colour = rgb;
	else if (flag == 2)
		parsed->ceil_colour = rgb;
}

static int	commas_num(char *str)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i++] == ',')
			res++;
	}
	return (res);
}

void	valid_colour(char **params, t_parsed *parsed, int flag)
{
	char	**rgb_str;
	size_t	i;

	if ((!(check_number_params(params, 2))))
	{
		g_error = 15;
		return ;
	}
	if (invalid_chars(params[1]))
		return ;
	rgb_str = ft_split(params[1], ',');
	if (!rgb_str)
	{
		g_error = 2;
		return ;
	}
	if (commas_num(params[1]) != 2 || !rgb_str[2] || !rgb_str[1] || !rgb_str[0])
	{
		g_error = 20;
		return ;
	}
	i = 0;
	valid_rgb(rgb_str, parsed, flag);
	free_strs(rgb_str);
}
