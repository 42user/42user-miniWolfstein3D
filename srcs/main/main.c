#include "cub3d.h"

int	infinite_hook(t_all *all)
{
	calculate_pos(all);
	render_next_frame(all);
	if (all->save == 0)
		mlx_put_image_to_window(all->window.mlx,
			all->window.win, all->window.frame.img, 0, 0);
	else
	{
		make_screen(all);
		close_win(all, 0);
	}
	return (0);
}

int	key_pressed(int keycode, t_all *all)
{
	if (keycode == 13)
		all->keys.w = 1;
	else if (keycode == 0)
		all->keys.a = 1;
	else if (keycode == 1)
		all->keys.s = 1;
	else if (keycode == 2)
		all->keys.d = 1;
	else if (keycode == 123)
		all->keys.left = 1;
	else if (keycode == 124)
		all->keys.right = 1;
	else if (keycode == 53)
		close_win(all, 0);
	return (0);
}

int	key_released(int keycode, t_all *all)
{
	if (keycode == 13)
		all->keys.w = 0;
	else if (keycode == 0)
		all->keys.a = 0;
	else if (keycode == 1)
		all->keys.s = 0;
	else if (keycode == 2)
		all->keys.d = 0;
	else if (keycode == 123)
		all->keys.left = 0;
	else if (keycode == 124)
		all->keys.right = 0;
	return (0);
}

static void	launch_mlx(t_all *all)
{
	get_textures(all);
	all->window.frame.img = mlx_new_image(all->window.mlx,
			all->parsed.res_width, all->parsed.res_height);
	if (all->window.frame.img == NULL)
		return ;
	all->window.frame.addr = mlx_get_data_addr(all->window.frame.img,
			&(all->window.frame.bpp), &(all->window.frame.line_len),
			&(all->window.frame.endian));
	if (all->save == 1)
		infinite_hook(all);
	else
	{
		all->window.win = mlx_new_window(all->window.mlx, all->parsed.res_width,
				all->parsed.res_height, "cub3D");
		if (all->window.win == NULL)
			return ;
		mlx_loop_hook(all->window.mlx, infinite_hook, all);
		mlx_hook(all->window.win, 2, 1L << 0, key_pressed, all);
		mlx_hook(all->window.win, 3, 1L << 1, key_released, all);
		mlx_hook(all->window.win, 17, 1L << 17, close_win, all);
		mlx_loop(all->window.mlx);
	}
}

int	main(int argc, char **argv)
{
	t_all		all;

	init_struct(&all);
	if (!(check_args(argc, argv, &all)))
		return (-1);
	mlx_get_screen_size(&g_screen_w, &g_screen_h);
	errno = 0;
	if (parse_file(argv[1], &(all.parsed)))
		return (-1);
	all.window.mlx = mlx_init();
	init_plr_pos(&all);
	launch_mlx(&all);
	return (0);
}
