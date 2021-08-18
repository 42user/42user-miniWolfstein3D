#include "cub3d.h"

static void	sort_sprite(int *sprite_order, double *sprite_dist, int n_sprite)
{
	int		i;
	int		j;
	double	temp_d;
	double	temp_o;

	i = n_sprite - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (sprite_dist[j] < sprite_dist[j + 1])
			{
				temp_d = sprite_dist[j + 1];
				sprite_dist[j + 1] = sprite_dist[j];
				sprite_dist[j] = temp_d;
				temp_o = sprite_order[j + 1];
				sprite_order[j + 1] = sprite_order[j];
				sprite_order[j] = temp_o;
			}
			j++;
		}
		i--;
	}
}

static void	fill_sprite_arrs(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->parsed.n_sprite)
	{
		all->parsed.sprite_order[i] = i;
		all->parsed.sprite_dist[i] = ((all->pos.x - all->parsed.sprite[i].x)
				* (all->pos.x - all->parsed.sprite[i].x)
				+ (all->pos.y - all->parsed.sprite[i].y)
				* (all->pos.y - all->parsed.sprite[i].y));
		i++;
	}
}

static void	calc_sprite_values(t_all *all, t_dda_sprit *dda, int i)
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;

	sprite_x = all->parsed.sprite[all->parsed.sprite_order[i]].x
		- all->pos.x;
	sprite_y = all->parsed.sprite[all->parsed.sprite_order[i]].y
		- all->pos.y;
	inv_det = 1.0 / (all->pos.plane.x * all->pos.dir.y
			- all->pos.dir.x * all->pos.plane.y);
	dda->transform_x = inv_det * (all->pos.dir.y * sprite_x
			- all->pos.dir.x * sprite_y);
	dda->transform_y = inv_det * (-all->pos.plane.y * sprite_x
			+ all->pos.plane.x * sprite_y);
	dda->sprite_screen_x = (int)((all->parsed.res_width / 2)
			* (1 + dda->transform_x / dda->transform_y));
	dda->sprite_height = abs((int)(all->parsed.res_height / dda->transform_y));
	dda->sprite_width = abs((int)(all->parsed.res_height / dda->transform_y));
}

static void	calc_draw_coords(t_all *all, t_dda_sprit *dda)
{
	dda->draw_start_y = -dda->sprite_height / 2
		+ all->parsed.res_height / 2;
	if (dda->draw_start_y < 0)
		dda->draw_start_y = 0;
	dda->draw_end_y = dda->sprite_height / 2 + all->parsed.res_height / 2;
	if (dda->draw_end_y >= all->parsed.res_height)
		dda->draw_end_y = all->parsed.res_height - 1;
	dda->draw_start_x = -dda->sprite_width / 2 + dda->sprite_screen_x;
	if (dda->draw_start_x < 0)
		dda->draw_start_x = 0;
	dda->draw_end_x = dda->sprite_width / 2 + dda->sprite_screen_x;
	if (dda->draw_end_x >= all->parsed.res_width)
		dda->draw_end_x = all->parsed.res_width - 1;
}

int	cast_sprite(t_all *all)
{
	t_dda_sprit		*dda;
	int				i;

	dda = &all->dda_sprite;
	fill_sprite_arrs(all);
	sort_sprite(all->parsed.sprite_order, all->parsed.sprite_dist,
		all->parsed.n_sprite);
	i = 0;
	while (i < all->parsed.n_sprite)
	{
		calc_sprite_values(all, dda, i);
		calc_draw_coords(all, dda);
		draw_sprite(all, dda);
		i++;
	}
	return (0);
}
