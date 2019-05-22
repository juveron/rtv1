/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juveron <juveron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:52:22 by jvitry            #+#    #+#             */
/*   Updated: 2019/05/20 14:12:55 by juveron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vecteur	libe(void **r, void **min_max, t_vecteur vr)
{
	ft_memdel(r);
	ft_memdel(min_max);
	return (vr);
}

int			tab_free(char **tab, char *line)
{
	int i;

	i = -1;
	while (tab[++i])
		ft_memdel((void **)&tab[i]);
	ft_memdel((void **)&tab);
	ft_memdel((void **)&line);
	return (-1);
}

void		printexit(void)
{
	ft_putendl_fd("Erreur de fichier de configuration", 2);
	exit(1);
}

void		set_min_max(double min, double max, double *min_max)
{
	min_max[0] = min;
	min_max[1] = max;
}
