NAME = miniRT
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iminilibx-linux
all   :	$(NAME)

SRCS = 	main.c \
		check_file.c \
		intersection/sphere_intersection.c \
		vector/equation_resolution.c \
		vector/vector_normalisation.c \
		get_next_line.c \
		get_next_line_utils.c \
		map_error/ambient_error.c \
		map_error/camera_error.c \
		map_error/cylinder_error.c \
		map_error/light_error.c \
		map_error/plane_error.c \
		map_error/sphere_error.c \
		map_error/utils_error1.c \
		map_error/utils_error2.c \
		map_error/check_maps_elements.c \
		parsing/add_plane.c \
		parsing/add_sphere_cylinder.c \
		parsing/parse_element.c \
		parsing/parse_element_suite.c \
		parsing/free_elements.c \
		initialisation/init_scene.c \
		windows/init_windows.c \
		windows/init_windows_suite.c \
		windows/init_windows_suite2.c \
		showing/intersect_show.c \
		utils/my_put_pixel.c \
		utils/get_real_screen.c \
		utils/compute_cam_angle.c \
		utils/transform_cam.c \
		intersection/plan_intersection.c \
		intersection/plan_intersection_suite.c \
		intersection/intersection.c \
		vector/vect_product.c \
		intersection/cylinder_intersection.c \
		intersection/cylinder_intersection_suite.c \
		color/accesseur_color.c \
		utils/get_norm_surface.c \
		lightning/intersect_light.c \
		lightning/intersect_light_suite.c

SRCS_BONUS = $(addprefix Bonus/, $(SRCS:%.c=%_bonus.c))

OBJS_BONUS = $(addprefix Bonus/, $(SRCS:%.c=%_bonus.o))

OBJS = $(SRCS:.c=.o)

RM = rm -rf


LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a


LIBS = -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

BONUS = miniRT_bonus 

bonus : $(OBJS_BONUS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) $(LIBFT) -lm -o $(BONUS)


$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LIBFT) -lm -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS)
	@make fclean -C $(LIBFT_PATH)

re: fclean $(NAME)

.PHONY: clean fclean re all
