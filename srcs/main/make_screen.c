#include "cub3d.h"

static void	int_to_char(unsigned char *dataset, int value)
{
	dataset[0] = (unsigned char)(value);
	dataset[1] = (unsigned char)(value >> 8);
	dataset[2] = (unsigned char)(value >> 16);
	dataset[3] = (unsigned char)(value >> 24);
}

static int	fill_header(int fd, int bmpsize, t_all *all)
{
	int				i;
	unsigned char	header[54];

	i = 0;
	while (i < 54)
		header[i++] = 0;
	header[0] = 'B';
	header[1] = 'M';
	int_to_char(header + 2, bmpsize);
	header[10] = 54;
	header[14] = 40;
	int_to_char(header + 18, all->parsed.res_width);
	int_to_char(header + 22, all->parsed.res_height);
	header[26] = 1;
	header[28] = 32;
	if (write(fd, header, 54) < 0)
		return (0);
	return (1);
}

static int	get_rgb(t_all *all, int x, int y)
{
	unsigned int	colour;
	t_img			*frame;

	frame = &(all->window.frame);
	colour = *(unsigned int *)(frame->addr + y * frame->line_len
			+ x * (frame->bpp / 8));
	return (colour);
}

static int	fill_bmp(int fd, t_all *all)
{
	int					y;
	int					x;
	unsigned int		colour;

	y = all->parsed.res_height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < all->parsed.res_width)
		{
			colour = get_rgb(all, x, y);
			if (write(fd, &colour, 4) < 0)
				return (0);
			x++;
		}
		y--;
	}
	return (1);
}

int	make_screen(t_all *all)
{
	int		bmpsize;
	int		fd;

	bmpsize = 54 + (4 * all->parsed.res_width * all->parsed.res_height);
	fd = open("screen.bmp", O_WRONLY | O_CREAT, 0666);
	if (!(fd >= 0 && (fill_header(fd, bmpsize, all)) && (fill_bmp(fd, all))))
	{
		error_handler();
		return (-1);
	}
	close(fd);
	return (0);
}
