#include "cub3d.h"

static void	calculate_del_dist(t_dda_wall *dda, t_all *all)
{
	dda->map.x = (int)all->pos.x;
	dda->map.y = (int)all->pos.y;
	if (dda->ray.y == 0)
		dda->del_dist.x = 0;
	else
	{
		if (dda->ray.x == 0)
			dda->del_dist.x = 1;
		else
			dda->del_dist.x = fabs(1 / dda->ray.x);
	}
	if (dda->ray.x == 0)
		dda->del_dist.y = 0;
	else
	{
		if (dda->ray.y == 0)
			dda->del_dist.y = 1;
		else
			dda->del_dist.y = fabs(1 / dda->ray.y);
	}
}

static void	calculate_side_dist_and_steps(t_dda_wall *dda, t_all *all)
{
	if (dda->ray.x < 0)
	{
		dda->step_x = -1;
		dda->side_dist.x = (all->pos.x - dda->map.x) * dda->del_dist.x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist.x = (dda->map.x + 1.0 - all->pos.x) * dda->del_dist.x;
	}
	if (dda->ray.y < 0)
	{
		dda->step_y = -1;
		dda->side_dist.y = (all->pos.y - dda->map.y) * dda->del_dist.y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist.y = (dda->map.y + 1.0 - all->pos.y) * dda->del_dist.y;
	}
}

static void	perform_dda(t_dda_wall *dda, t_all *all)
{
	dda->hit = 0;
	while (dda->hit == 0)
	{
		if (dda->side_dist.x < dda->side_dist.y)
		{
			dda->side_dist.x += dda->del_dist.x;
			dda->map.x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist.y += dda->del_dist.y;
			dda->map.y += dda->step_y;
			dda->side = 1;
		}
		if (all->parsed.map[dda->map.y][dda->map.x] == '1')
			dda->hit = 1;
	}
	if (dda->side == 0)
		dda->perp_wall_dist = (dda->map.x - all->pos.x
				+ (1 - dda->step_x) / 2) / dda->ray.x;
	else
		dda->perp_wall_dist = (dda->map.y - all->pos.y
				+ (1 - dda->step_y) / 2) / dda->ray.y;
}

int	cast_rays_wall(t_all *all)
{
	t_dda_wall	*dda;
	int			x;

	dda = &(all->dda_walls);
	x = 0;
	while (x < all->parsed.res_width)
	{
		dda->camera_x = 2 * x / (double)all->parsed.res_width - 1;
		dda->ray.x = all->pos.dir.x + all->pos.plane.x * dda->camera_x;
		dda->ray.y = all->pos.dir.y + all->pos.plane.y * dda->camera_x;
		calculate_del_dist(dda, all);
		calculate_side_dist_and_steps(dda, all);
		perform_dda(dda, all);
		all->parsed.zbuffer[x] = dda->perp_wall_dist;
		draw_wall(x, dda, all);
		x++;
	}
	return (0);
}
