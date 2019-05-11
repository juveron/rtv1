/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juveron <juveron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:41:24 by juveron           #+#    #+#             */
/*   Updated: 2019/05/10 17:49:25 by juveron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	hit_sphere(t_sphere *sphere, t_ray *ray, double *min_max, t_record *rec)
{
	t_vecteur	oc;
	double		tab[5];

	oc = v_less(ray->ori, sphere->center);
	tab[0] = v_dot(ray->dir, ray->dir);
	tab[1] = 2.0 * v_dot(oc, ray->dir);
	tab[2] = v_dot(oc, oc) - sphere->radius * sphere->radius;
	tab[3] = tab[1] * tab[1] - 4 * tab[0] * tab[2];
	if (tab[3] > 0)
	{
		tab[4] = (-1 * tab[1] - sqrt(tab[3])) / (2 * tab[0]);
		if (tab[4] < min_max[1] && tab[4] > min_max[0])
		{
			sphere_rec(ray, tab[4], sphere, rec);
			return (1);
		}
		tab[4] = (-1 * tab[1] + sqrt(tab[3])) / (2 * tab[0]);
		if (tab[4] < min_max[1] && tab[4] > min_max[0])
		{
			sphere_rec(ray, tab[4], sphere, rec);
			return (1);
		}
	}
	return (0);
}
