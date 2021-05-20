/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:22:16 by yataji            #+#    #+#             */
/*   Updated: 2021/04/26 16:39:04 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>
# include "SDL2/SDL.h"
# include "SDL2/SDL_image.h"
# define MAXWIDTH 1000
# define MAXHEIGHT 1000
# define SPHERE 0
# define CYLINDER 1
# define CONE 2
# define PLANE 3
# define PARAPLOID 4
# define WATER 1.3
# define DIAMOND 1.8
# define GLASS 1.5
# define MAXRF 3

typedef struct s_2d_i
{
	int	i;
	int	j;
}				t_2d_i;

typedef struct s_2d_d
{
	double	x;
	double	y;
}				t_2d_d;

typedef struct s_angle
{
	double	theta1;
	double	theta2;
	double	costheta2;
	double	sintheta1;
}				t_angle;

typedef struct s_var
{
	int				x;
	int				y;
	double			t;
	double			dist;
	double			near;
}					t_var;

typedef struct s_varpars
{
	int		l;
	int		i;
	int		c;
	int		j;
	char	**value;
}			t_varpars;

typedef struct s_vect
{
	double	x;
	double	y;
	double	z;
}					t_vect;

typedef struct s_xyz
{
	t_vect	x;
	t_vect	y;
	t_vect	z;
}				t_xyz;

typedef t_2d_i		t_event;
typedef t_vect		t_point;
typedef t_vect		t_color;
typedef t_vect		t_rot;

typedef struct s_sol
{
	double	tmin;
	double	tmax;
}				t_sol;

typedef struct s_obj
{
	int				type;
	double			angle;
	double			radius;
	t_vect			v;
	t_vect			normal;
	t_vect			hit;
	t_color			color;
	t_rot			rot;
	t_point			trs;
	t_sol			sol;
	t_point			center;
	t_point			pos_texture;
	t_point			pos_slice;
	int				refl;
	int				refr;
	double			per_refr;
	int				matter;
	int				neg_obj;
	double			n2;
	double			t;
	double			size;
	t_vect			slice;
	char			*texture;
	SDL_Surface		*surface;
	struct s_obj	*next;
}					t_obj;

typedef struct s_ray
{
	t_point			org;
	t_vect			dir;
	t_vect			hit;
	double			n1;
}					t_ray;

typedef struct s_math
{
	double			a;
	double			b;
	double			c;
	double			delta;
}					t_math;

typedef struct s_cam
{
	t_point			lokat;
	t_point			lokfrm;
	t_vect			v;
	t_vect			u;
	t_vect			w;
	double			ambiante;
	double			fov;
	double			plnw;
	double			plnh;
	struct s_cam	*next;
}					t_cam;

typedef struct s_lights
{
	t_color			color;
	t_point			pos;
	t_vect			direction;
	double			intensity;
	t_ray			hit_to_light;
	int				direct;
	int				angle;
	struct s_lights	*next;
}					t_lights;

typedef struct s_rt
{
	int				filter_type;
	t_obj			*obj;
	t_obj			*tmpo;
	t_ray			ray;
	t_cam			*cam;
	t_cam			*tmpc;
	t_lights		*lights;
	t_lights		*tmpl;
	t_sol			t;
	t_math			calc;
	double			dot1;
	int				maxrfr;
	int				maxrfl;
	char			*str;
	int				fd;
	int				menu;
	int				ck;
	int				start;
	int				end;
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Renderer	*rend_bar;
	t_vect			*screen;
	t_event			event;
}					t_rt;

t_color				multi_color(t_color c1, double scal);
t_color				multi_tcolor(t_color c1, t_color c2);
t_color				add_color(t_color c1, t_color c2);
t_vect				rotation_xyz(t_vect v, t_vect a);
t_ray				initray(t_cam *cam, int x, int y);
double				max(double v1, double v2);
double				dot(t_vect a, t_vect b);
double				multidbl(double v1, double v2, double v3);
double				checkt(t_math calc);
double				intersect(t_obj **object, t_ray ray);
double				sphrintr(t_obj **sphere, t_ray ray);
double				cyldintr(t_obj **cyld, t_ray ray);
double				coneintr(t_obj **cone, t_ray ray);
double				parapinter(t_obj **para, t_ray ray);
double				planiter(t_obj **pln, t_ray ray);
int					keypress(int key, void *param);
int					ft_exit(t_rt *rt);
void				setnormal(t_obj *close, t_ray *ray, double t);
void				initcamera(t_cam *cam);
void				draw(t_rt rt);
void				ft_free(t_obj **obj, t_lights **lights, t_cam **cam);
t_vect				plus(t_vect v1, t_vect v2);
t_vect				moins(t_vect v1, t_vect v2);
t_vect				multi(t_vect v1, double v2);
t_vect				normalize(t_vect v1);
t_vect				normsphr(t_ray *ray, t_obj *obj, double t);
t_vect				normcyld(t_ray *ray, t_obj *obj, double t);
t_vect				normcone(t_ray *ray, t_obj *obj, double t);
t_vect				crosspro(t_vect v1, t_vect v2);
t_lights			*initlights(void);
t_obj				*initobj(void);
t_cam				*initcam(void);
t_vect				stk(char **value);
size_t				ft_strlend(char **s);
t_color				checkcolorvalue(char **value);
int					parse(t_rt*rt);
int					sphere(t_obj *obj, char *str, int fd);
int					plane(t_obj *obj, char *str, int fd);
int					cylinder(t_obj *obj, char *str, int fd);
int					cone(t_obj *obj, char *str, int fd);
int					paraploid(t_obj *obj, char *str, int fd);
int					lights(t_lights *lights, char *str, int fd);
int					camera(t_cam *cam, char *str, int fd);
int					ck(char *str, char *check, int len);
int					chkone(char *str, int len);
int					ft_plane(t_rt *rt, char *str);
int					ft_cone(t_rt *rt, char *str);
int					ft_cylinder(t_rt *rt, char *str);
int					ft_sphere(t_rt *rt, char *str);
int					ft_paraploid(t_rt *rt, char *str);
int					ft_lights(t_rt *rt, char *str);
int					ft_cam(t_rt *rt, char *str);
void				init_sdl(t_rt *rt);
void				sdl_error(char *message);
void				loop(t_rt *rt);
void				loop_program(t_rt *rt);
int					parse_texture(t_obj *obj, char *str);
int					stockobj(t_obj *obj, int id, char *s, int fd);
double				ft_atof(char *str);
t_2d_i				get_uv(t_obj *obj, t_2d_i size, t_vect hit);
void				texture(t_obj *obj, t_vect hit);
t_sol				check_min_max(t_math math);
int					ft_cube(t_rt *rt, char *str);
t_ray				initrayrfl(t_rt *rt, t_ray ray, t_obj *closeobj);
t_ray				initrayrfr(t_rt *rt, t_ray ray, t_obj *closeobj);
int					shadow(t_rt *rt, t_lights *lights, t_obj *close);
t_color				diffuspclr(t_ray ray, t_obj *close, t_lights *lights);
t_color				reflection(t_rt *rt, t_obj *close,
						t_lights *l, t_ray rayor);
t_color				refraction(t_rt *rt, t_obj *close,
						t_lights *l, t_ray rayor);
double				limeted_cone(t_obj *cone, t_ray r, t_sol sol);
double				limeted_cly(t_obj *cyl, t_ray r, t_sol sol);
void				menu(t_rt *rt);
int					inside_rect(t_rt *rt, SDL_Rect r);
double				ft_matter(int matter);
void				filter_mb(t_rt *rt);
void				filtre_sepia(t_rt *rt);
void				filtres(t_rt *rt);
void				multi_thread(t_rt *rt);
int					light_direct(t_rt *rt, t_obj *close, t_lights *li);
void				putimage(t_rt *rt, t_color *col, t_var *v);
int					inside_rect(t_rt *rt, SDL_Rect r);
void				negative_objc(t_obj *obj);

#endif