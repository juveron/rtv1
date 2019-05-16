/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juveron <juveron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:59:49 by jvitry            #+#    #+#             */
/*   Updated: 2019/05/16 12:12:20 by juveron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vecteur	v_add(t_vecteur v1, t_vecteur v2)
{
	t_vecteur	v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	v3.z = v1.z + v2.z;
	return (v3);
}

t_vecteur	v_less(t_vecteur v1, t_vecteur v2)
{
	t_vecteur	v3;

	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;
	v3.z = v1.z - v2.z;
	return (v3);
}

t_vecteur	v_cross(t_vecteur v1, t_vecteur v2)
{
	t_vecteur	v3;

	v3.x = ((v1.y * v2.z) - (v1.z * v2.y));
	v3.y = ((v1.z * v2.x) - (v1.x * v2.z));
	v3.z = ((v1.x * v2.y) - (v1.y * v2.x));
	return (v3);
}

double		v_dot(t_vecteur v1, t_vecteur v2)
{
	double	r;

	r = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (r);
}

double		v_norm(t_vecteur v)
{
	double	norm;

	norm = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (norm);
}
