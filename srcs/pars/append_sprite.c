#include "cub3d.h"

void	make_sprite_arrays(t_parsed *parsed)
{
	int		*sprite_order;
	double	*sprite_dist;

	sprite_order = (int *)malloc(sizeof(int) * parsed->n_sprite);
	if (!sprite_order)
	{
		g_error = 2;
		return ;
	}
	sprite_dist = (double *)malloc(sizeof(double) * parsed->n_sprite);
	if (!sprite_dist)
	{
		g_error = 2;
		return ;
	}
	parsed->sprite_order = sprite_order;
	parsed->sprite_dist = sprite_dist;
}

static void	copy_arr(t_dpoint *dest, t_dpoint *src, size_t src_size)
{
	size_t			i;

	i = 0;
	while (i < src_size)
	{
		dest[i] = src[i];
		i++;
	}
}

int	append_sprite(t_parsed *parsed, int x, int y)
{
	t_dpoint		sprite_position;
	t_dpoint		*new_array;
	t_dpoint		*old_array;

	old_array = parsed->sprite;
	parsed->n_sprite++;
	new_array = (t_dpoint *)malloc(sizeof(t_dpoint) * parsed->n_sprite);
	if (!new_array)
	{
		g_error = 2;
		return (-1);
	}
	sprite_position.x = x + 0.5;
	sprite_position.y = y + 0.5;
	new_array[parsed->n_sprite - 1] = sprite_position;
	copy_arr(new_array, old_array, parsed->n_sprite - 1);
	parsed->sprite = new_array;
	free(old_array);
	return (0);
}
