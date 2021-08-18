#include "cub3d.h"

static void	move(t_all *all)
{
	double		speed;

	speed = MOV_SPEED + 0.01;
	if (all->keys.s == 1)
	{
		if (all->parsed.map[(int)(all->pos.y)] \
			[(int)(all->pos.x - all->pos.dir.x * speed)] != '1')
			all->pos.x -= all->pos.dir.x * MOV_SPEED;
		if (all->parsed.map[(int)(all->pos.y - all->pos.dir.y
				* speed)][(int)(all->pos.x)] != '1')
			all->pos.y -= all->pos.dir.y * MOV_SPEED;
	}
	if (all->keys.w == 1)
	{
		if (all->parsed.map[(int)(all->pos.y)] \
			[(int)(all->pos.x + all->pos.dir.x * speed)] != '1')
			all->pos.x += all->pos.dir.x * MOV_SPEED;
		if (all->parsed.map[(int)(all->pos.y + all->pos.dir.y
				* speed)][(int)(all->pos.x)] != '1')
			all->pos.y += all->pos.dir.y * MOV_SPEED;
	}
}

static void	strafe(t_all *all)
{
	double		speed;

	speed = MOV_SPEED + 0.01;
	if (all->keys.a == 1)
	{
		if (all->parsed.map[(int)(all->pos.y)][(int)(all->pos.x
							+ all->pos.plane.x * speed)] != '1')
			all->pos.x += all->pos.plane.x * MOV_SPEED;
		if (all->parsed.map[(int)(all->pos.y + all->pos.plane.y
				* speed)][(int)(all->pos.x)] != '1')
			all->pos.y += all->pos.plane.y * MOV_SPEED;
	}
	if (all->keys.d == 1)
	{
		if (all->parsed.map[(int)(all->pos.y)][(int)(all->pos.x
					- all->pos.plane.x * speed)] != '1')
			all->pos.x -= all->pos.plane.x * MOV_SPEED;
		if (all->parsed.map[(int)(all->pos.y - all->pos.plane.y
				* speed)][(int)(all->pos.x)] != '1')
			all->pos.y -= all->pos.plane.y * MOV_SPEED;
	}
}

static void	turn_left(t_all *all)
{
	double		olddir_x;
	double		oldplane_x;

	if (all->keys.left == 1)
	{
		olddir_x = all->pos.dir.x;
		all->pos.dir.x = all->pos.dir.x * cos(-ROT_SPEED) - \
							all->pos.dir.y * sin(-ROT_SPEED);
		all->pos.dir.y = olddir_x * sin(-ROT_SPEED) + \
							all->pos.dir.y * cos(-ROT_SPEED);
		oldplane_x = all->pos.plane.x;
		all->pos.plane.x = all->pos.plane.x * cos(-ROT_SPEED) - \
							all->pos.plane.y * sin(-ROT_SPEED);
		all->pos.plane.y = oldplane_x * sin(-ROT_SPEED) + \
							all->pos.plane.y * cos(-ROT_SPEED);
	}
}

static void	turn_right(t_all *all)
{
	double		olddir_x;
	double		oldplane_x;

	if (all->keys.right == 1)
	{
		olddir_x = all->pos.dir.x;
		all->pos.dir.x = all->pos.dir.x * cos(ROT_SPEED) - \
							all->pos.dir.y * sin(ROT_SPEED);
		all->pos.dir.y = olddir_x * sin(ROT_SPEED) + \
							all->pos.dir.y * cos(ROT_SPEED);
		oldplane_x = all->pos.plane.x;
		all->pos.plane.x = all->pos.plane.x * cos(ROT_SPEED) - \
							all->pos.plane.y * sin(ROT_SPEED);
		all->pos.plane.y = oldplane_x * sin(ROT_SPEED) + \
							all->pos.plane.y * cos(ROT_SPEED);
	}
}

int	calculate_pos(t_all *all)
{
	move(all);
	strafe(all);
	turn_left(all);
	turn_right(all);
	return (0);
}
