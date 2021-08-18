NAME	=	cub3D

PARAL	=	-j 4

LIBFT	=	libft/srcs/libft.a

MLX		=	minilibx/libmlx.a

PARS	=	./srcs/pars/parse_file.c ./srcs/pars/valid_list.c\
			./srcs/pars/free_memory.c ./srcs/pars/valid_param.c\
			./srcs/pars/valid_resolution.c ./srcs/pars/valid_texture.c\
			./srcs/pars/valid_colour.c ./srcs/pars/valid_map.c\
			./srcs/pars/check_wall_map.c ./srcs/pars/check_space_map.c\
			./srcs/pars/append_sprite.c ./srcs/pars/init_map.c

RAYCAST	=	./srcs/raycast/drawing_utils.c ./srcs/raycast/init_plr_pos.c\
			./srcs/raycast/calculate_pos.c ./srcs/raycast/raycasting_wall.c\
			./srcs/raycast/get_textures.c\
			./srcs/raycast/raycasting_wall_drawing.c\
			./srcs/raycast/raycasting_sprite.c\
			./srcs/raycast/raycasting_sprite_drawing.c

MAIN	=	./srcs/main/main.c ./srcs/main/init_struct.c\
			./srcs/main/init_txt_dda.c ./srcs/main/make_screen.c\
			./srcs/main/error_handler.c

SRCS	=	$(PARS) $(MAIN) $(RAYCAST)

SRCS	:=	$(addprefix $(SRCSDIR), $(SRCS))

OBJS	=	$(patsubst %.c,%.o,$(SRCS))

FLAGS	=	-Wall -Wextra -Werror

%.o: %.c	Makefile cub3d.h
			gcc $(FLAGS) -c $< -I . -I libft/srcs/ -I minilibx/ -o $(<:.c=.o) -O2

all:		$(NAME)

$(LIBFT):	libft/srcs/*.[^a] libft/srcs/Makefile
			$(MAKE) -C libft/srcs/ $(PARAL)
			$(MAKE) clean -C libft/srcs/ $(PARAL)
					
$(MLX):
			$(MAKE) -C minilibx/ $(PARAL)

$(NAME):	$(LIBFT) $(MLX) $(OBJS)
			gcc $(FLAGS) $(OBJS) -o $(NAME) -L libft/srcs/ -lft \
			-L minilibx/ -lmlx -framework OpenGL -framework AppKit

clean:				
			rm -f $(OBJS) $(LIBFT) $(MLX) ./screenshot.bmp
			$(MAKE) clean -C minilibx/ $(PARAL)

fclean:		clean
			rm -f $(NAME)
			$(MAKE) fclean -C libft/srcs/ $(PARAL)

re:			fclean all

.PHONY:		all clean fclean re
