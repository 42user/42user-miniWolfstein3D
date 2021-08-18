#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_ceil(t_all *all)
{
	int		y;
	int		x;

	y = 0;
	while (y < all->parsed.res_height / 2)
	{
		x = 0;
		while (x < all->parsed.res_width)
			my_mlx_pixel_put(&(all->window.frame), x++, y,
				all->parsed.ceil_colour);
		y++;
	}
}

void	draw_floor(t_all *all)
{
	int		y;
	int		x;

	y = all->parsed.res_height / 2;
	while (y < all->parsed.res_height)
	{
		x = 0;
		while (x < all->parsed.res_width)
			my_mlx_pixel_put(&(all->window.frame), x++, y,
				all->parsed.flr_colour);
		y++;
	}
}

int	render_next_frame(t_all *all)
{
	draw_ceil(all);
	draw_floor(all);
	cast_rays_wall(all);
	cast_sprite(all);
	return (0);
}
