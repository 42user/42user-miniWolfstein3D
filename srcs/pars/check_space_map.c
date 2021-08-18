#include "cub3d.h"

static int	check_arround(char c)
{
	if ((c == '1') || (c == ' '))
		return (1);
	return (0);
}

int	check_space_map(t_parsed *parsed, int x, int y)
{
	int		line_len;
	int		i;
	int		j;

	line_len = ft_strlen((parsed->map)[y]);
	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if ((x + j >= 0 && x + j < line_len)
				&& (y + i >= 0 && y + i < (int)parsed->map_hgt))
			{
				if ((!((i == 0) && (j == 0)))
					&& (!(check_arround((parsed->map)[y + i][x + j]))))
					g_error = 6;
				if (g_error)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
