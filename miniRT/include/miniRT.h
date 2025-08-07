/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:43:08 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/07 21:56:38 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define PI 3.14159265358979

# include "../get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_mode
{
	MODE_CAMERA,
	MODE_OBJECT,
	MODE_LIGHT
}							t_mode;

typedef struct s_color
{
	double					part1;
	double					part2;
	double					part3;
}							t_color;

typedef struct s_point
{
	double					x_p;
	double					y_p;
	double					z_p;
}							t_point;

typedef struct s_scr_p
{
	int						x;
	int						y;
}							t_scr_p;

typedef struct s_vector
{
	double					x_d;
	double					y_d;
	double					z_d;
	t_point					origin_d;
}							t_vector;

typedef struct s_sphere
{
	t_point					origin;
	double					radius;
	t_color					color;
}							t_sphere;

typedef struct s_cylinder
{
	t_point					origin;
	double					diameter;
	double					height;
	t_vector				orientation;
	t_color					color;
	double					a;
	double					b;
}							t_cylinder;

typedef struct s_plan
{
	t_point					origin;
	t_vector				normal_vect;
	t_color					color;
	double					a;
	double					b;
}							t_plan;

/*
 *	Theta represente the angle after rotation by x
 *	Phi represente the angle after rotation by y'
 */
typedef struct s_camera
{
	t_vector				orientation;
	t_point					origin;
	double					field_of_view;
	double					theta;
	double					phi;
	double					rho;
}							t_camera;

typedef struct s_data
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*addrs;
	int						bpp;
	int						ll;
	int						e;
	int						width;
	int						heigth;
}							t_data;

typedef struct s_aLight
{
	double					intensity;
	t_color					color;
}							t_aLight;

typedef struct s_light
{
	t_point					origin;
	double					intensity;
	t_color					color;
}							t_light;

typedef struct s_sphere_list
{
	t_sphere				*sphere;
	struct s_sphere_list	*next;
}							t_sphere_list;

typedef struct s_cylinder_list
{
	t_cylinder				*cylinder;
	struct s_cylinder_list	*next;
}							t_cylinder_list;

typedef struct s_plane_list
{
	t_plan					*plane;
	struct s_plane_list		*next;
}							t_plane_list;

typedef struct s_colision
{
	void					*obj;
	double					dist;
	char					type[10];
	int						cap;
}							t_colision;

typedef struct s_scene
{
	t_sphere_list			*sphere;
	t_cylinder_list			*cylinder;
	t_plane_list			*plan;
	t_camera				camera;
	t_aLight				ambiant;
	t_light					light;
	t_data					*win;
	t_colision				*selected_obj;
	t_mode					mode;
	int						nb_sphere;
	int						nb_cylinder;
	int						nb_plan;
	double					screen_cam_dist;
	double					dist_px_real;
}							t_scene;

typedef struct s_map_elements
{
	int						ambient_count;
	int						camera_count;
	int						ligth_count;
	int						sphere_count;
	int						plane_count;
	int						cylinder_count;
}							t_map_elements;

typedef struct s_param
{
	t_vector				vec;
	t_vector				s;
	t_point					rr1;
	t_point					rr2;
}							t_param;

typedef struct s_slove_c
{
	double					t;
	t_vector				s;
	t_vector				r1;
	t_vector				r2;
	t_vector				rao;
	t_vector				va;
}							t_slove_c;

int							check_format(char *av);
void						msg_error(char *msg);
int							main(int ac, char **av);
int							ambient_ligth(char *line);
int							check_camera(char *line);
int							check_light(char *line);
int							check_sphere(char *line);
int							check_plane(char *line);
int							check_cylinder(char *line);
char						*clean_line(char *str);
int							ft_isspace(char c);
void						ft_free_split(char **split);
int							ft_strcmp(char *s1, char *s2);
double						ft_atof(char *str);
int							check_color(char *line);
int							check_color_nbr(char **color_splited);
int							check_normalized_vector(char *str);
int							check_coordinates(char *str);
int							num_digitt2(char *str);
int							num_digitt(char *str);
int							count_arguments(char *str);
char						*trim_end(char *str);
int							count_comma_separated(char *str);
int							count_comma(char *str);
int							points_seen(char *str, int i);
int							update_map_elements(char *line,
								t_map_elements *elements);
int							check_map_elements(t_map_elements *elements);
void						init_map_elements(t_map_elements *elements);
int							is_really_normalized(double x, double y, double z);
int							parse_vector_values(char *s, double *x, double *y,
								double *z);
char						*check_identifier(char *av, char c);

int							init_window(t_data *data, t_scene *scene);
int							handle_keypress(int keysym, t_scene *scene);
int							close_window(t_scene *data);

/*-------Geometric tools for vector manipulation-----------*/

/*
 *	Normalise the vector given in argument. It means that its module
 *	should be equal to 1
 *	If the module of the argument is equal to 0, then return a vector
 *		with 0 all component.
 */
t_vector					normalisation(t_vector vector);
double						ft_module(t_vector vector);
void						my_put_pixel(int x, int y, int color,
								t_scene *scene);
void						intersect_show(t_scene *scene);
void						get_real_screen(t_scene *scene);
void						compute_cam_angle(t_scene *scene);
t_vector					transform_cam(t_scene *scene, t_vector vec,
								double rho);
double						double_min(double a, double b);
void						intersection(t_scene *s, t_colision *c, t_vector v,
								t_scr_p p);

/*
 *	Return the distance between two point a and b
 */
double						distance(t_point a, t_point b);

/*
 *	Return a vector director started at "a" and pass throug b
 *	the module of returned vector is equal to 1
 */
t_vector					director_vect(t_point a, t_point b);
double						dot_product(t_vector a, t_vector b);
t_vector					cross_product(t_vector a, t_vector b);
t_vector					add_vector(t_vector a, t_vector b, t_point origin);
t_vector					substract_vect(t_point a, t_point b,
								t_point origin);
t_point						to_point(t_vector vec);
t_vector					to_vector(t_point p, t_point origin);
t_vector					k_vector(double k, t_vector vec);
t_vector					get_norm_surf(void *obj, char *type, t_point pos);

double						quadratique_equation(double a, double b, double c);
void						sphere_int(t_vector d, t_sphere_list **s,
								t_colision *c);
void						plan_int(t_vector dir, t_plane_list **plan,
								t_colision *col);
void						cyl_int(t_vector d, t_cylinder_list **c_l,
								t_colision *c);
void						intersect_light(t_scene *s, t_colision *c,
								t_point i, t_scr_p p);
t_scene						*init_scene(void);
int							add_plane(t_scene *scene, char *line);
int							parse_plane(char *line, t_plan *plane);
int							add_sphere(t_scene *scene, char *line);
int							add_cylinder(t_scene *scene, char *line);
int							parse_light(char *line, t_light *light);
int							parse_ambient(char *line, t_aLight *alight);
int							parse_sphere(char *line, t_sphere *sphere);
int							parse_cylinder(char *line, t_cylinder *cylinder);
int							parse_color(char *str, t_color *color);
int							parse_point(char *str, t_point *point);
int							parse_vector(char *str, t_vector *vector);
int							parse_camera(char *line, t_camera *camera);

int							convert_color(t_color col);
t_color						add_color(t_color c1, t_color c2);
t_color						k_color(double k, t_color c);

void						plan_int_l(t_vector dir, t_plane_list **plan,
								t_colision *col);
void						sphere_int_l(t_vector dir, t_sphere_list **sp_l,
								t_colision *col);
void						transform_normal_vect_a(t_vector *n, double a);
void						transform_normal_vect_b(t_vector *n, double b);
double						plan_equation(t_vector dir, t_plan pl);
double						put_lateral(t_vector Va, t_vector Rao,
								t_cylinder *cyl);
void						update_colision_cylinder(t_colision *col,
								double t, t_cylinder *cyl, int cap);
void						put_disc(t_param data, t_colision *col,
								t_cylinder *cyl);
t_color						get_all_col(t_scene *s, t_colision *col, t_vector v,
								t_point inter);
int							handle_mouse(int button, int x, int y,
								t_scene *scene);
void						move_selected_sphere(t_scene *scene, int keysym);
void						move_selected_plan(t_scene *scene, int keysym);
void						move_selected_cylinder(t_scene *scene, int keysym);
void						free_scene(t_scene *scene);

#endif
