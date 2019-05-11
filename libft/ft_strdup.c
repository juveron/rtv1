/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:45:31 by jvitry            #+#    #+#             */
/*   Updated: 2017/11/17 12:48:51 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		s_size;

	s_size = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * s_size + 1);
	if (copy != NULL)
	{
		ft_strcpy(copy, s1);
		return (copy);
	}
	else
		return (0);
}
