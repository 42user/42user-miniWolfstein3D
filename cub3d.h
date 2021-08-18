#ifndef CUB3D_H
# define CUB3D_H

# include "libft/srcs/libft.h"
# include <mlx.h>
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# define MOV_SPEED 0.05
# define ROT_SPEED 0.04

int				g_error;
int				g_screen_h;
int				g_screen_w;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_dpoint
{
	double		x;
	double		y;
}				t_dpoint;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_plr_pos
{
	double		x;
	double		y;
	double		z;
	t_vector	dir;
	t_vector	plane;
}				t_plr_pos;

typedef struct s_parsed
{
	int						res_width;
	int						res_height;
	double					*zbuffer;
	int						n_sprite;
	t_list					*sprite_list;
	t_dpoint				*sprite;
	int						*sprite_order;
	double					*sprite_dist;
	char					*north_path;
	char					*south_path;
	char					*west_path;
	char					*east_path;
	char					*sprite_path;
	unsigned int			flr_colour;
	unsigned int			ceil_colour;
	char					**map;
	t_point					player_pos;
	char					player_dir;
	size_t					map_hgt;
	size_t					map_wdth;
}				t_parsed;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	t_img		frame;
}				t_win;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}				t_keys;

typedef struct s_dda_sprite
{
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
}				t_dda_sprit;

typedef struct s_dda_wall
{
	double		camera_x;
	t_vector	ray;
	t_point		map;
	t_vector	side_dist;
	t_vector	del_dist;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		*zbuffer;
}				t_dda_wall;

typedef struct s_txtrs
{
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	t_img		sprite;
}				t_txtrs;

typedef struct s_all
{
	int			save;
	t_parsed	parsed;
	t_win		window;
	t_keys		keys;
	t_plr_pos	pos;
	t_txtrs		txtrs;
	t_dda_wall	dda_walls;
	t_dda_sprit	dda_sprite;
}				t_all;

typedef struct s_ver_line
{
	int			height;
	int			draw_start;
	int			draw_end;
}				t_ver_line;

typedef struct s_stripe
{
	t_ver_line	line;
	double		tex_pos;
	int			tex_x;
	int			tex_y;
	double		step;
}				t_stripe;

void			init_struct(t_all *all);
void			init_dda_sprit(t_dda_sprit *dda);
void			init_dda_walls(t_dda_wall *dda);
void			init_txtrs(t_txtrs *txtrs);
int				init_map(t_list **start, t_parsed *parsed);
void			init_plr_pos(t_all *all);
int				parse_file(char *filepath, t_parsed *parsed);
int				valid_list(t_parsed *parsed, t_list *lst);
int				valid_params(t_list **head, t_parsed *parsed);
void			valid_resolution(char **params, t_parsed *parsed);
void			valid_texture(char **params, t_parsed *parsed, int flag);
void			valid_colour(char **params, t_parsed *parsed, int flag);
void			valid_map(t_list **start, t_parsed *parsed);
int				check_space_map(t_parsed *parsed, int x, int y);
int				check_wall_map(t_parsed *parsed, int x, int y);
int				check_number_params(char **params, size_t num_params);
int				check_args(int argc, char **argv, t_all *all);
int				append_sprite(t_parsed *parsed, int x, int y);
void			make_sprite_arrays(t_parsed *parsed);
int				get_textures(t_all *all);
void			draw_map(t_all *all);
void			draw_player(t_all *all, int colour);
void			draw_wall(int x, t_dda_wall *dda, t_all *all);
void			draw_ceil(t_all *all);
void			draw_floor(t_all *all);
void			draw_sprite(t_all *all, t_dda_sprit *dda);
int				cast_rays_wall(t_all *all);
int				cast_sprite(t_all *all);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				calculate_pos(t_all *all);
int				render_next_frame(t_all *all);
int				make_screen(t_all *all);
void			free_parsed(t_parsed *parsed);
void			free_str(void *line);
void			free_strs(char **strs);
int				error_handler(void);
int				close_win(t_all *all, int code);
#endif
