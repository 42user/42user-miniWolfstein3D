#include "cub3d.h"

int	close_win(t_all *all, int code)
{
	free_parsed(&all->parsed);
	if (all->window.frame.img)
		mlx_destroy_image(all->window.mlx, all->window.frame.img);
	if (all->window.win)
		mlx_destroy_window(all->window.mlx, all->window.win);
	exit(code);
	return (0);
}

static char	*get_error_message(int error_code)
{
	char	*message[21];

	message[1] = "File in first arg should be .cub";
	message[2] = "Failed malloc";
	message[3] = "Either map not be last or no smth params";
	message[4] = "Map params not last, but should have";
	message[5] = "Excess params precedes map";
	message[6] = "Invalid map";
	message[7] = "No map";
	message[8] = "Only '--save' may be 2d args";
	message[9] = "Invalid parameter occur";
	message[10] = "Invalid num of args or resolution";
	message[11] = "Invalid texture file";
	message[14] = "Invalid num args in NO / SO / WE / EA params";
	message[15] = "Invalid num in F / C params. Should be three nums 0 - 255";
	message[16] = "Invalid texture (not .xpm) or filename have too many dots";
	message[17] = "Player position should be only one";
	message[18] = "Invalid num NO / SO / WE / EA / R / S / F / C params";
	message[19] = "Invalid num of args";
	message[20] = "Invalid colour (Note, it's should be R,G,B)";
	return (message[error_code]);
}

int	error_handler(void)
{
	ft_putendl_fd("Error", 2);
	if (g_error)
	{
		ft_putstr_fd("cub3D: ", 2);
		ft_putendl_fd(get_error_message(g_error), 2);
	}
	else
	{
		if (errno)
			perror("cub3D");
	}
	return (-1);
}
