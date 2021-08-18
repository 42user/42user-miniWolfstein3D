#include "cub3d.h"

t_img	get_texture(t_dda_wall *dda, t_all *all)
{
	t_img		texture;

	if (dda->side == 0)
	{
		if (dda->ray.x > 0)
			texture = all->txtrs.west;
		else
			texture = all->txtrs.east;
	}
	if (dda->side == 1)
	{
		if (dda->ray.y > 0)
			texture = all->txtrs.north;
		else
			texture = all->txtrs.south;
	}
	return (texture);
}

static void	calculate_line_params(t_dda_wall *dda, t_all *all,
		t_ver_line *line)
{
	line->height = (int)(all->parsed.res_height / dda->perp_wall_dist);
	line->draw_start = -line->height / 2 + all->parsed.res_height / 2;
	if (line->draw_start < 0)
		line->draw_start = 0;
	line->draw_end = line->height / 2 + all->parsed.res_height / 2;
	if (line->draw_end >= all->parsed.res_height)
		line->draw_end = all->parsed.res_height - 1;
}

static int	calculate_tex_x(t_dda_wall *dda, t_all *all, t_img texture)
{
	double	wall_x;
	int		tex_x;

	if (dda->side == 0)
		wall_x = all->pos.y + dda->perp_wall_dist * dda->ray.y;
	else
		wall_x = all->pos.x + dda->perp_wall_dist * dda->ray.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)(texture.width));
	if (dda->side == 0 && dda->ray.x > 0)
		tex_x = texture.width - tex_x - 1;
	if (dda->side == 1 && dda->ray.y < 0)
		tex_x = texture.width - tex_x - 1;
	return (tex_x);
}

static void	draw_texture_stripe(t_stripe *stripe, int x,
									t_img texture, t_all *all)
{
	int				y;
	unsigned int	colour;

	stripe->step = (double)texture.height / (double)stripe->line.height;
	stripe->tex_pos = (stripe->line.draw_start - all->parsed.res_height / 2
			+ stripe->line.height / 2) * stripe->step;
	y = stripe->line.draw_start;
	while (y < stripe->line.draw_end)
	{
		stripe->tex_y = (int)stripe->tex_pos & (texture.height - 1);
		colour = *(unsigned int *)(texture.addr
				+ (stripe->tex_y * texture.line_len
					+ stripe->tex_x * (texture.bpp / 8)));
		my_mlx_pixel_put(&(all->window.frame),
			all->parsed.res_width - x - 1, y, colour);
		stripe->tex_pos += stripe->step;
		y++;
	}
}

void	draw_wall(int x, t_dda_wall *dda, t_all *all)
{
	t_img		texture;
	t_stripe	stripe;

	calculate_line_params(dda, all, &stripe.line);
	texture = get_texture(dda, all);
	stripe.tex_x = calculate_tex_x(dda, all, texture);
	draw_texture_stripe(&stripe, x, texture, all);
}
