#include "cub3d.h"

static void	north(t_all *all)
{
	all->pos.dir.x = 0;
	all->pos.dir.y = -1;
	all->pos.plane.x = -0.66;
	all->pos.plane.y = 0;
}

static void	south(t_all *all)
{
	all->pos.dir.x = 0;
	all->pos.dir.y = 1;
	all->pos.plane.x = 0.66;
	all->pos.plane.y = 0;
}

static void	west(t_all *all)
{
	all->pos.dir.x = -1;
	all->pos.dir.y = 0;
	all->pos.plane.x = 0;
	all->pos.plane.y = 0.66;
}

static void	east(t_all *all)
{
	all->pos.dir.x = 1;
	all->pos.dir.y = 0;
	all->pos.plane.x = 0;
	all->pos.plane.y = -0.66;
}

void	init_plr_pos(t_all *all)
{
	all->pos.x = all->parsed.player_pos.x + 0.5;
	all->pos.y = all->parsed.player_pos.y + 0.5;
	if (all->parsed.player_dir == 'N')
		north(all);
	else if (all->parsed.player_dir == 'S')
		south(all);
	else if (all->parsed.player_dir == 'W')
		west(all);
	else if (all->parsed.player_dir == 'E')
		east(all);
}
