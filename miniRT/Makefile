NAME = miniRT
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iminilibx-linux -g
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
		initialisation/init_scene.c \
		windows/init_windows.c \
		showing/intersect_show.c \
		utils/my_put_pixel.c \
		utils/get_real_screen.c \
		utils/compute_cam_angle.c \
		utils/transform_cam.c \
		intersection/plan_intersection.c \
		intersection/intersection.c \
		vector/vect_product.c \
		intersection/cylinder_intersection.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf


LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a


LIBS = -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LIBFT) -lm -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean $(NAME)

.PHONY: clean fclean re all
