/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juveron <juveron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:55:55 by jvitry            #+#    #+#             */
/*   Updated: 2019/05/10 17:54:09 by juveron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H

# define RTV1_H
# define W_LENGHT 1200
# define W_WIDTH 1200

# include "mlx.h"
# include "libft/includes/libft.h"
# include <math.h>
# include <float.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;
typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_mlx;
typedef struct	s_vecteur
{
	double	x;
	double	y;
	double	z;
}				t_vecteur;
typedef struct	s_record
{
	double		t;
	t_vecteur	p;
	t_vecteur	normal;
	t_vecteur	color;
	int			hit_anything;
	int 		inside;
}				t_record;
typedef struct	s_ray
{
	t_vecteur	ori;
	t_vecteur	dir;
}				t_ray;
typedef struct	s_sphere
{
	t_vecteur	center;
	double		radius;
	t_vecteur	c;
}				t_sphere;
typedef struct	s_cylindre
{
	t_vecteur	base;
	t_vecteur	dir;
	double		radius;
	t_vecteur	color;
}				t_cylindre;
typedef struct	s_cone
{
	t_vecteur	apex;
	t_vecteur	dir;
	double		angle;
	t_vecteur	color;
}				t_cone;
typedef struct	s_plan
{
	t_vecteur	point;
	t_vecteur	vdir;
	t_vecteur	color;
}				t_plan;
typedef struct	s_camera
{
	t_vecteur	origin;
	t_vecteur	lowleftcor;
	t_vecteur	horizontal;
	t_vecteur	vertical;
}				t_camera;
typedef struct	s_formlist
{
	void		*form;
	int			type;
	int			size;
	t_vecteur	color;
}				t_formlist;
typedef struct	s_scene
{
	t_formlist	*list;
	t_vecteur	*light;
	t_vecteur	camorigin;
	t_vecteur	camdir;
	int			n_light;
	int			n_obj;
	int			i;
	int			k;
}				t_scene;

t_vecteur		v_add(t_vecteur v1, t_vecteur v2);
t_vecteur		v_less(t_vecteur v1, t_vecteur v2);
t_vecteur		v_cross(t_vecteur v1, t_vecteur v2);
double			v_dot(t_vecteur v1, t_vecteur v2);
double			v_norm(t_vecteur v);
t_vecteur		v_mult(t_vecteur v1, double i);
int				v_equal(t_vecteur v1, t_vecteur v2);
t_vecteur		v_div(t_vecteur v1, double i);
t_vecteur		v_set(double x, double y, double z);
t_vecteur		v_normalize(t_vecteur v);
void			mlx_set(t_mlx *mlx);
int				my_key_funct(int keycode);
int				set_sphere(t_scene *scene, char **tab);
void			set_min_max(double min, double max, double *min_max);
int				hit_sphere(t_sphere *sphere, t_ray *ray,
		double *min_max, t_record *rec);
int				hit_qqch(t_formlist *list, t_ray *ray,
		double *min_max, t_record *rec);
t_formlist		*set_list(void);
t_camera		s_cam(t_vecteur lookfrom, t_vecteur lookat,
		t_vecteur vup, double fov);
void			sphere_rec(t_ray *ray, double t, t_sphere *s, t_record *rec);
void			cyl_rec(t_ray *ray, double t, t_cylindre *cyl, t_record *rec);
void			cone_rec(t_ray *ray, double t, t_cone *cone, t_record *rec);
double			*cone_tab(t_cone *cone, t_ray *ray);
void			ret_inter(t_formlist list, double *min_max,
		t_record *rec, int *hit);
t_vecteur		libe(void **r, void **min_max, t_vecteur vr);
t_vecteur		r_color(t_ray *ray, t_formlist *list,
		t_vecteur *light, int n_light);
void			printexit(void);
int				hit_sphere(t_sphere *sphere,
		t_ray *ray, double *min_max, t_record *rec);
void			tab_free(char **tab, char *line);
int				set_plan(t_scene *scene, char **tab);
int				set_cylindre(t_scene *scene, char **tab);
int				set_cone(t_scene *scene, char **tab);
int				set_light(t_scene *scene, char **tab);
int				set_cam(t_scene *scene, char **tab);
void			ft_parseur(char **av, t_scene *scene);
#endif
