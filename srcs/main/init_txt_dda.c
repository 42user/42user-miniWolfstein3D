#include "cub3d.h"

static void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->height = 0;
	img->width = 0;
}

void	init_txtrs(t_txtrs *txtrs)
{
	init_img(&(txtrs->north));
	init_img(&(txtrs->south));
	init_img(&(txtrs->west));
	init_img(&(txtrs->east));
	init_img(&(txtrs->sprite));
}

void	init_dda_walls(t_dda_wall *dda)
{
	dda->camera_x = 0;
	dda->ray.x = 0;
	dda->ray.y = 0;
	dda->map.x = 0;
	dda->map.y = 0;
	dda->side_dist.x = 0;
	dda->side_dist.y = 0;
	dda->del_dist.x = 0;
	dda->del_dist.y = 0;
	dda->perp_wall_dist = 0;
	dda->step_x = 0;
	dda->step_y = 0;
	dda->hit = 0;
	dda->side = 0;
}

void	init_dda_sprit(t_dda_sprit *dda)
{
	dda->transform_x = 0;
	dda->transform_y = 0;
	dda->sprite_screen_x = 0;
	dda->sprite_height = 0;
	dda->sprite_width = 0;
	dda->draw_start_x = 0;
	dda->draw_start_y = 0;
	dda->draw_end_x = 0;
	dda->draw_end_y = 0;
}
