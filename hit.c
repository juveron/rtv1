/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juveron <juveron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:13:51 by jvitry            #+#    #+#             */
/*   Updated: 2019/05/10 17:53:21 by juveron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			hit_cylindre(t_cylindre *cyl,
	t_ray *ray, double *min_max, t_record *rec)
{
	t_vecteur	oc;
	double		tab[5];

	oc = v_cross(cyl->dir, ray->dir);
	tab[0] = v_dot(oc, oc);
	tab[1] = 2 * v_dot(oc, v_cross(cyl->dir, v_less(ray->ori, cyl->base)));
	oc = v_cross(cyl->dir, v_less(ray->ori, cyl->base));
	tab[2] = v_dot(oc, oc) - cyl->radius * cyl->radius;
	tab[3] = tab[1] * tab[1] - 4 * tab[0] * tab[2];
	if (tab[3] > 0)
	{
		tab[4] = (-1 * tab[1] - sqrt(tab[3])) / (2 * tab[0]);
		if (tab[4] < min_max[1] && tab[4] > min_max[0])
		{
			cyl_rec(ray, tab[4], cyl, rec);
			return (1);
		}
		tab[4] = (-1 * tab[1] + sqrt(tab[3])) / (2 * tab[0]);
		if (tab[4] < min_max[1] && tab[4] > min_max[0])
		{
			cyl_rec(ray, tab[4], cyl, rec);
			return (1);
		}
	}
	return (0);
}

int			hit_cone(t_cone *cone, t_ray *ray, double *min_max, t_record *rec)
{
	double	*tab;

	tab = cone_tab(cone, ray);
	if (tab[4] > 0)
	{
		tab[3] = (-1 * tab[1] - sqrt(tab[4])) / (2 * tab[0]);
		if (tab[3] < min_max[1] && tab[3] > min_max[0])
		{
			cone_rec(ray, tab[3], cone, rec);
			ft_memdel((void **)&tab);
			return (1);
		}
		tab[3] = (-1 * tab[1] + sqrt(tab[4])) / (2 * tab[0]);
		if (tab[3] < min_max[1] && tab[3] > min_max[0])
		{
			cone_rec(ray, tab[3], cone, rec);
			ft_memdel((void **)&tab);
			return (1);
		}
	}
	ft_memdel((void **)&tab);
	return (0);
}

static void	setrec(t_record *rec, t_plan *plan, t_ray *ray)
{
	if (v_dot(ray->dir, plan->vdir) > 0)
	{
		rec->normal.x = -rec->normal.x;
		rec->normal.y = -rec->normal.y;
		rec->normal.z = -rec->normal.z;
	}
	rec->inside = 1;
}

int			hit_plan(t_plan *plan, t_ray *ray, double *min_max, t_record *rec)
{
	t_vecteur	oc;
	double		d;
	double		temp;

	oc = v_less(ray->ori, plan->point);
	d = v_dot(ray->dir, plan->vdir);
	if (d != 0)
	{
		temp = -v_dot(oc, plan->vdir) / d;
		if (temp < min_max[1] && temp > min_max[0])
		{
			rec->t = temp;
			rec->p = v_add(ray->ori, v_mult(ray->dir, rec->t));
			rec->normal = v_normalize(v_set(plan->vdir.x, plan->vdir.y, \
						plan->vdir.z));
			setrec(rec, plan, ray);
			return (1);
		}
	}
	return (0);
}

int			hit_qqch(t_formlist *list,
	t_ray *ray, double *min_max, t_record *rec)
{
	int	i;
	int	hit_anything;

	i = -1;
	hit_anything = 0;
	while (++i < list[0].size)
	{
		if (list[i].type == 1 && hit_sphere(list[i].form, ray, min_max, rec))
			ret_inter(list[i], min_max, rec, &hit_anything);
		if (list[i].type == 2 && hit_plan(list[i].form, ray, min_max, rec))
			ret_inter(list[i], min_max, rec, &hit_anything);
		if (list[i].type == 3 && hit_cylindre(list[i].form, ray, min_max, rec))
			ret_inter(list[i], min_max, rec, &hit_anything);
		if (list[i].type == 4 && hit_cone(list[i].form, ray, min_max, rec))
			ret_inter(list[i], min_max, rec, &hit_anything);
	}
	return (hit_anything);
}
