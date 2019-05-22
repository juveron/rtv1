/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juveron <juveron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:22:19 by jvitry            #+#    #+#             */
/*   Updated: 2019/05/22 15:20:29 by juveron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	exit_get_number(int fd, char *line, char **tab, t_scene *scene)
{
	tab_free(tab, line);
	while (get_next_line(fd, &line) == 1)
		free(line);
	close(fd);
	free_my_scene(scene);
	printexit();
}

int		get_numbers(t_scene *scene, char **av)
{
	int		fd;
	char	*line;
	char	**tab;
	int		cam;

	cam = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		tab = ft_strsplit(line, ' ');
		if (tab[0] && (ft_strcmp(tab[0], "sphere") == 0
				|| ft_strcmp(tab[0], "plan") == 0
				|| ft_strcmp(tab[0], "cylindre") == 0
				|| ft_strcmp(tab[0], "cone") == 0))
			scene->n_obj++;
		else if (tab[0] && (ft_strcmp(tab[0], "light") == 0))
			scene->n_light++;
		else if (tab[0] && (ft_strcmp(tab[0], "camera") == 0))
			cam++;
		else
			exit_get_number(fd, line, tab, scene);
		tab_free(tab, line);
	}
	close(fd);
	return (cam);
}

int		get_objnext(t_scene *scene, char **tab)
{
	if (ft_strcmp(tab[0], "cylindre") == 0)
		if (set_cylindre(scene, tab) == -1)
			return (-1);
	if (ft_strcmp(tab[0], "cone") == 0)
		if (set_cone(scene, tab) == -1)
			return (-1);
	if (ft_strcmp(tab[0], "light") == 0)
		if (set_light(scene, tab) == -1)
			return (-1);
	if (ft_strcmp(tab[0], "camera") == 0)
		if (set_cam(scene, tab) == -1)
			return (-1);
	return (1);
}

int		get_obj(t_scene *scene, int fd)
{
	char	**tab;
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		tab = ft_strsplit(line, ' ');
		if (ft_strcmp(tab[0], "sphere") == 0)
			if (set_sphere(scene, tab) == -1)
				return (tab_free(tab, line));
		if (ft_strcmp(tab[0], "plan") == 0)
			if (set_plan(scene, tab) == -1)
				return (tab_free(tab, line));
		if (get_objnext(scene, tab) == -1)
			return (tab_free(tab, line));
		tab_free(tab, line);
	}
	return (1);
}

void	ft_parseur(char **av, t_scene *scene)
{
	int		fd;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		printexit();
	scene->n_obj = 0;
	scene->n_light = 0;
	if (get_numbers(scene, av) != 1 || scene->n_obj == 0)
	{
		free_my_scene(scene);
		printexit();
	}
	if (!(scene->list = (t_formlist *)ft_memalloc(scene->n_obj
				* sizeof(t_formlist)))
		|| !(scene->light = (t_vecteur *)ft_memalloc(scene->n_light
				* sizeof(t_vecteur))))
	{
		free_my_scene(scene);
		exit(EXIT_FAILURE);
	}
	scene->i = 0;
	scene->k = 0;
	scene->list[scene->n_obj].form = NULL;
	if (get_obj(scene, fd) == -1)
		printexit();
	close(fd);
}
