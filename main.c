/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <jvitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:03:05 by jvitry            #+#    #+#             */
/*   Updated: 2019/05/10 16:43:23 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray	set_ray(int i, int j, t_camera cam)
{
	t_ray		ray;
	t_vecteur	temp[3];
	double		u;
	double		v;

	u = (double)i / (double)W_LENGHT;
	v = (double)j / (double)W_WIDTH;
	ray.ori = cam.origin;
	temp[0] = v_mult(cam.horizontal, u);
	temp[1] = v_mult(cam.vertical, v);
	temp[2] = v_add(cam.lowleftcor, temp[0]);
	ray.dir = v_less(v_add(temp[1], temp[2]), cam.origin);
	return (ray);
}

void	raytracer(t_camera cam, t_scene *scene, t_mlx *mlx)
{
	int			col[4];
	double		tab[2];
	t_ray		ray;
	t_vecteur	couleur;

	tab[1] = W_WIDTH - 1;
	col[3] = 0;
	while (tab[1] >= 0)
	{
		tab[0] = 0;
		while (tab[0] < W_LENGHT)
		{
			ray = set_ray(tab[0], tab[1], cam);
			couleur = r_color(&ray, scene->list, scene->light, scene->n_light);
			col[0] = (int)(255 * couleur.x);
			col[1] = (int)(255 * couleur.y);
			col[2] = (int)(255 * couleur.z);
			mlx->img.data[col[3]] = col[0] * 256 * 256 + col[1] * 256 + col[2];
			col[3]++;
			tab[0]++;
		}
		tab[1]--;
	}
}

int		closer(void *param)
{
	(void)param;
	exit(0);
}

int		main(int ac, char **av)
{
	t_mlx		mlx;
	t_scene		*scene;
	t_camera	cam;

	if (ac != 2)
	{
		ft_putendl("Usage : ./rtv1 scene_valide");
		exit(0);
	}
	scene = (t_scene *)ft_memalloc(sizeof(t_scene));
	ft_parseur(av, scene);
	mlx_set(&mlx);
	cam = s_cam(scene->camorigin, scene->camdir, v_set(0, 1, 0), 90);
	raytracer(cam, scene, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_key_hook(mlx.win, my_key_funct, &mlx);
	mlx_hook(mlx.win, 17, 0, closer, (void *)&mlx);
	mlx_loop(mlx.mlx);
}
