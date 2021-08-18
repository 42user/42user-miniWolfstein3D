#include "cub3d.h"

void	free_strs(char **strs)
{
	size_t	i;

	if (strs)
	{
		i = 0;
		while (strs[i])
			free_str(strs[i++]);
		free_str(strs);
		strs = NULL;
	}
}

void	free_str(void *line)
{
	if (line)
		free(line);
	line = NULL;
}

void	free_parsed(t_parsed *parsed)
{
	char	**map;

	free_str(parsed->zbuffer);
	free_str(parsed->north_path);
	free_str(parsed->south_path);
	free_str(parsed->west_path);
	free_str(parsed->east_path);
	free_str(parsed->sprite_path);
	free_str(parsed->sprite);
	free_str(parsed->sprite_order);
	free_str(parsed->sprite_dist);
	map = parsed->map;
	free_strs(map);
}
