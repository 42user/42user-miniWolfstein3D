#include "cub3d.h"

static void	init_parsed(t_parsed *parsed)
{
	parsed->res_width = 0;
	parsed->res_height = 0;
	parsed->zbuffer = NULL;
	parsed->n_sprite = 0;
	parsed->sprite_list = NULL;
	parsed->sprite = NULL;
	parsed->sprite_order = NULL;
	parsed->sprite_dist = NULL;
	parsed->north_path = NULL;
	parsed->south_path = NULL;
	parsed->west_path = NULL;
	parsed->east_path = NULL;
	parsed->sprite_path = NULL;
	parsed->flr_colour = 0;
	parsed->ceil_colour = 0;
	parsed->map = NULL;
	parsed->player_pos.x = 0;
	parsed->player_pos.y = 0;
	parsed->player_dir = 0;
	parsed->map_hgt = 0;
	parsed->map_wdth = 0;
}

static void	init_window(t_win *window)
{
	window->mlx = NULL;
	window->win = NULL;
	window->frame.img = NULL;
	window->frame.addr = NULL;
	window->frame.line_len = 0;
	window->frame.bpp = 0;
	window->frame.endian = 0;
}

static void	init_keys(t_keys *keys)
{
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->left = 0;
	keys->right = 0;
}

static void	init_pos(t_plr_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
	pos->z = 0;
	pos->dir.x = 0;
	pos->dir.y = 0;
	pos->plane.x = 0;
	pos->plane.y = 0;
}

void	init_struct(t_all *all)
{
	all->save = 0;
	init_parsed(&(all->parsed));
	init_window(&(all->window));
	init_keys(&(all->keys));
	init_pos(&(all->pos));
	init_dda_walls(&(all->dda_walls));
	init_dda_sprit(&(all->dda_sprite));
	init_txtrs(&(all->txtrs));
}
