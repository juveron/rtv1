/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <jvitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:26:41 by jvitry            #+#    #+#             */
/*   Updated: 2019/05/09 15:38:33 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_camera	s_cam(t_vecteur lkfrom, t_vecteur lkat, t_vecteur vup, double fov)
{
	t_vecteur	v[3];
	t_vecteur	temp[2];
	t_camera	cam;
	double		half_height;
	double		half_width;

	cam.origin = v_set(lkfrom.x, lkfrom.y, lkfrom.z);
	fov = fov * M_PI / 180;
	half_height = tan(fov / 2);
	half_width = ((double)W_LENGHT / (double)W_WIDTH) * half_height;
	v[2] = v_normalize(v_less(lkfrom, lkat));
	v[1] = v_normalize(v_cross(vup, v[2]));
	v[0] = v_cross(v[2], v[1]);
	cam.lowleftcor = v_set(-half_width, -half_height, -1.0);
	temp[0] = v_mult(v[1], half_width);
	temp[1] = v_mult(v[0], half_height);
	cam.lowleftcor = v_less(v_less(v_less(cam.origin, temp[0]), temp[1]), v[2]);
	cam.horizontal = v_mult(v[1], 2 * half_width);
	cam.vertical = v_mult(v[0], 2 * half_height);
	return (cam);
}
