#include "cub3d.h"

static size_t	get_max_strlen(t_list **start)
{
	t_list		*head;
	size_t		max_len;
	size_t		len;

	head = *start;
	max_len = 0;
	while (head)
	{
		len = ft_strlen((char *)head->content);
		if (len > max_len)
			max_len = len;
		head = head->next;
	}
	return (max_len);
}

static int	map_malloc(char **map, int lst_size,
					   t_list **start, t_parsed *parsed)
{
	int			i;

	parsed->map_wdth = get_max_strlen(start);
	i = 0;
	while (i < lst_size)
	{
		map[i] = (char *)malloc(parsed->map_wdth * sizeof(char) + 1);
		if (!(map[i++]))
			return (-1);
	}
	return (0);
}

static void	fill_str(char *dest, char *src, t_parsed *parsed)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < (int)parsed->map_wdth)
		dest[i++] = ' ';
	dest[i] = '\0';
}

int	init_map(t_list **start, t_parsed *parsed)
{
	char		**map;
	size_t		i;
	t_list		*head;

	head = *start;
	map = ft_calloc(parsed->map_hgt + 1, sizeof(char *));
	if ((!map) || (map_malloc(map, parsed->map_hgt, start, parsed) == -1))
		return (-1);
	i = 0;
	while (i < parsed->map_hgt)
	{
		if (*(char *)head->content == '\0')
			break ;
		fill_str(map[i++], (char *)head->content, parsed);
		head = head->next;
	}
	map[i] = NULL;
	parsed->map = map;
	*start = head;
	return (0);
}
