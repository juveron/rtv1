/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <jvitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:58:33 by jvitry            #+#    #+#             */
/*   Updated: 2019/05/09 15:39:34 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	attr_cylindre(t_cylindre *cylindre, char **tab)
{
	tab[3][ft_strlen(tab[3]) - 1] = '\0';
	tab[7][ft_strlen(tab[7]) - 1] = '\0';
	cylindre->base.x = ft_atof(tab[1] + 1);
	cylindre->base.y = ft_atof(tab[2]);
	cylindre->base.z = ft_atof(tab[3]);
	cylindre->radius = ft_atof(tab[4]);
	cylindre->dir.x = ft_atof(tab[5] + 1);
	cylindre->dir.y = ft_atof(tab[6]);
	cylindre->dir.z = ft_atof(tab[7]);
	cylindre->dir = v_normalize(cylindre->dir);
}

int		set_cylindre(t_scene *scene, char **tab)
{
	int	j;

	j = 0;
	while (tab[j++])
		;
	if (j - 1 != 11)
		return (-1);
	scene->list[scene->i].form = (t_cylindre *)ft_memalloc(sizeof(t_cylindre));
	attr_cylindre(scene->list[scene->i].form, tab);
	scene->list[scene->i].color.x = ft_atof(tab[8] + 1);
	scene->list[scene->i].color.y = ft_atof(tab[9]);
	tab[10][ft_strlen(tab[10]) - 1] = '\0';
	scene->list[scene->i].color.z = ft_atof(tab[10]);
	scene->list[scene->i].type = 3;
	scene->i++;
	j = 0;
	while (j < scene->i)
		scene->list[j++].size = scene->i;
	return (1);
}

void	attr_cone(t_cone *cone, char **tab)
{
	tab[3][ft_strlen(tab[3]) - 1] = '\0';
	tab[7][ft_strlen(tab[7]) - 1] = '\0';
	cone->apex.x = ft_atof(tab[1] + 1);
	cone->apex.y = ft_atof(tab[2]);
	cone->apex.z = ft_atof(tab[3]);
	cone->angle = ft_atof(tab[4]) * M_PI / 180;
	cone->dir.x = ft_atof(tab[5] + 1);
	cone->dir.y = ft_atof(tab[6]);
	cone->dir.z = ft_atof(tab[7]);
	cone->dir = v_normalize(cone->dir);
}

int		set_cone(t_scene *scene, char **tab)
{
	int	j;

	j = 0;
	while (tab[j++])
		;
	if (j - 1 != 11)
		return (-1);
	scene->list[scene->i].form = (t_cone *)ft_memalloc(sizeof(t_cone));
	attr_cone(scene->list[scene->i].form, tab);
	scene->list[scene->i].color.x = ft_atof(tab[8] + 1);
	scene->list[scene->i].color.y = ft_atof(tab[9]);
	tab[10][ft_strlen(tab[10]) - 1] = '\0';
	scene->list[scene->i].color.z = ft_atof(tab[10]);
	scene->list[scene->i].type = 4;
	scene->i++;
	j = 0;
	while (j < scene->i)
		scene->list[j++].size = scene->i;
	return (1);
}

int		set_cam(t_scene *scene, char **tab)
{
	int j;

	j = 0;
	while (tab[j++])
		;
	if (j - 1 != 7)
		return (-1);
	tab[3][ft_strlen(tab[3]) - 1] = '\0';
	tab[6][ft_strlen(tab[6]) - 1] = '\0';
	scene->camorigin.x = ft_atof(tab[1] + 1);
	scene->camorigin.y = ft_atof(tab[2]);
	scene->camorigin.z = ft_atof(tab[3]);
	scene->camdir.x = ft_atof(tab[4] + 1);
	scene->camdir.y = ft_atof(tab[5]);
	scene->camdir.z = ft_atof(tab[6]);
	return (1);
}
