#include "cub3d.h"

static void	get_wall_text(t_img **texture, char **path, t_all *all, int flag)
{
	if (flag == 0)
	{
		*texture = &all->txtrs.north;
		*path = all->parsed.north_path;
	}
	else if (flag == 1)
	{
		*texture = &all->txtrs.south;
		*path = all->parsed.south_path;
	}
	else if (flag == 2)
	{
		*texture = &all->txtrs.west;
		*path = all->parsed.west_path;
	}
	else if (flag == 3)
	{
		*texture = &all->txtrs.east;
		*path = all->parsed.east_path;
	}
	else if (flag == 4)
	{
		*texture = &all->txtrs.sprite;
		*path = all->parsed.sprite_path;
	}
}

static int	get_texture(t_all *all, int flag)
{
	t_img			*texture;
	char			*path;

	get_wall_text(&texture, &path, all, flag);
	if (path)
	{
		texture->img = mlx_xpm_file_to_image(all->window.mlx, path,
				&texture->width, &texture->height);
		if (texture->img == NULL)
			return (-1);
		texture->addr = mlx_get_data_addr(texture->img,
				&(texture->bpp), &(texture->line_len), &(texture->endian));
	}
	return (0);
}

int	get_textures(t_all *all)
{
	int		i;

	i = -1;
	while (++i < 5)
		if (get_texture(all, i) == -1)
			return (-1);
	return (0);
}
