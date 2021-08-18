#include "cub3d.h"

static void	draw_line(t_all *all, t_dda_sprit *dda, int x, int tex_x)
{
	int				y;
	int				d;
	int				tex_y;
	unsigned int	colour;

	y = dda->draw_start_y;
	while (y < dda->draw_end_y)
	{
		d = y * 256 - all->parsed.res_height * 128 + dda->sprite_height * 128;
		tex_y = ((d * all->txtrs.sprite.height) / dda->sprite_height) / 256;
		colour = *(unsigned int *)(all->txtrs.sprite.addr
				+ (tex_y * all->txtrs.sprite.line_len
					+ tex_x * (all->txtrs.sprite.bpp / 8)));
		if (colour != 0)
		{
			my_mlx_pixel_put(&(all->window.frame),
				all->parsed.res_width - x - 1, y, colour);
		}
		y++;
	}
}

static void	draw_stripe(t_all *all, t_dda_sprit *dda, int x)
{
	int				tex_x;

	tex_x = (int)((x - (-dda->sprite_width / 2 + dda->sprite_screen_x))
			* all->txtrs.sprite.width / dda->sprite_width);
	if (dda->transform_y > 0 && x > 0 && x < all->parsed.res_width
		&& dda->transform_y < all->parsed.zbuffer[x])
		draw_line(all, dda, x, tex_x);
}

void	draw_sprite(t_all *all, t_dda_sprit *dda)
{
	int	x;

	x = dda->draw_start_x;
	while (x < dda->draw_end_x)
	{
		draw_stripe(all, dda, x);
		x++;
	}
}
