#include "cub3d.h"

static int	check_arround(char c)
{
	if ((c == '0') || (c == '1') || (c == '2') || (c == 'N')
		|| (c == 'S') || (c == 'E') || (c == 'W'))
		return (1);
	return (0);
}

int	check_wall_map(t_parsed *parsed, int x, int y)
{
	int		line_len;
	int		i;
	int		j;

	line_len = ft_strlen((parsed->map)[y]);
	if ((y == 0) || (y == (int)parsed->map_hgt - 1)
		|| (x == 0) || (x == line_len - 1))
		g_error = 6;
	i = -1;
	while ((i < 2) && !(g_error))
	{
		j = -1;
		while ((j < 2) && !(g_error))
		{
			if ((!((i == 0) && (j == 0)))
				&& (!(check_arround((parsed->map)[y + i][x + j]))))
				g_error = 6;
			j++;
		}
		i++;
	}
	if (g_error)
		return (0);
	return (1);
}
