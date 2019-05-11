/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juveron <juveron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 13:35:10 by jvitry            #+#    #+#             */
/*   Updated: 2019/05/10 17:54:41 by juveron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	sphere_rec(t_ray *ray, double t, t_sphere *s, t_record *rec)
{
	rec->t = t;
	rec->p = v_add(ray->ori, v_mult(ray->dir, rec->t));
	rec->normal = v_div(v_less(rec->p, s->center), s->radius);
}

void	cyl_rec(t_ray *ray, double t, t_cylindre *cyl, t_record *rec)
{
	t_vecteur uv;
	t_vecteur oc;

	rec->t = t;
	rec->p = v_add(ray->ori, v_mult(ray->dir, rec->t));
	oc = v_less(rec->p, cyl->base);
	uv = v_mult(cyl->dir, v_dot(cyl->dir, oc));
	rec->normal = v_normalize(v_less(oc, uv));
}

void	cone_rec(t_ray *ray, double t, t_cone *cone, t_record *rec)
{
	double		uv;
	t_vecteur	temp;
	t_vecteur	oc;

	rec->t = t;
	rec->p = v_add(ray->ori, v_mult(ray->dir, rec->t));
	oc = v_less(rec->p, cone->apex);
	if (v_dot(v_normalize(cone->dir), v_normalize(oc)) > 0)
		temp = v_set(cone->dir.x, cone->dir.y, cone->dir.z);
	else
		temp = v_set(-cone->dir.x, -cone->dir.y, -cone->dir.z);
	uv = v_norm(oc) / cos(cone->angle / 2);
	rec->normal = v_normalize(v_less(oc, v_mult(temp, uv)));
}

double	*cone_tab(t_cone *cone, t_ray *ray)
{
	double		*tab;
	t_vecteur	oc;

	if (!(tab = (double *)malloc(sizeof(double) * 6)))
		return (NULL);
	tab[5] = tan(cone->angle / 2);
	tab[5] = tab[5] * tab[5];
	oc = v_less(ray->ori, cone->apex);
	tab[0] = v_dot(ray->dir, ray->dir) - (1 + tab[5]) *
		v_dot(ray->dir, cone->dir) * v_dot(ray->dir, cone->dir);
	tab[1] = 2 * (v_dot(ray->dir, oc) - (1 + tab[5]) *
			v_dot(ray->dir, cone->dir) * v_dot(oc, cone->dir));
	tab[2] = v_dot(oc, oc) - (1 + tab[5]) * v_dot(oc, cone->dir)
		* v_dot(oc, cone->dir);
	tab[4] = tab[1] * tab[1] - 4 * tab[0] * tab[2];
	return (tab);
}

void	ret_inter(t_formlist list, double *min_max, t_record *rec, int *hit)
{
	*hit = 1;
	set_min_max(min_max[0], rec->t, min_max);
	rec->color = v_set(list.color.x, list.color.y, list.color.z);
}
