#include "cub3d.h"

static int	check_char(char c)
{
	if ((c != '1') && (c != '0') && (c != '2') && (c != ' ')
		&& (c != 'N') && (c != 'S') && (c != 'E') && (c != 'W'))
	{
		g_error = 6;
		return (0);
	}
	return (1);
}

static int	check_set_plr(int x, int y, t_parsed *parsed)
{
	if (((parsed->map)[y][x] == 'N') || ((parsed->map)[y][x] == 'S')
		|| ((parsed->map)[y][x] == 'E') || ((parsed->map)[y][x] == 'W'))
	{
		if (parsed->player_dir)
		{
			g_error = 17;
			return (-1);
		}
		parsed->player_pos.x = x;
		parsed->player_pos.y = y;
		parsed->player_dir = (parsed->map)[y][x];
	}
	return (0);
}

static int	check_map(t_parsed *parsed)
{
	int			x;
	int			y;
	char		**map;

	map = parsed->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == '2') && (append_sprite(parsed, x, y) == -1))
				return (0);
			if ((!(check_char(map[y][x]))) || (check_set_plr(x, y, parsed))
				|| ((map[y][x] == ' ') && (!(check_space_map(parsed, x, y))))
				|| ((map[y][x] != ' ') && (map[y][x] != '1')
				&& (!(check_wall_map(parsed, x, y)))))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	map_height(t_list *head)
{
	int		res;

	res = 0;
	while (*(char *)head->content != '\0')
	{
		res++;
		head = head->next;
	}
	return (res);
}

void	valid_map(t_list **start, t_parsed *parsed)
{
	t_list		*head;

	head = *start;
	parsed->map_hgt = map_height(head);
	if ((init_map(&head, parsed)) == -1)
	{
		g_error = 2;
		return ;
	}
	if (!(check_map(parsed)))
		return ;
	*start = head;
	make_sprite_arrays(parsed);
}
