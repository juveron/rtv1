/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <jvitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:20:47 by jvitry            #+#    #+#             */
/*   Updated: 2019/05/09 15:29:31 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinch(char **s1, char c)
{
	char	*new;
	size_t	i;
	size_t	len;

	if (!*s1 || !c)
		return (NULL);
	len = ft_strlen(*s1);
	new = ft_strnew(len + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < len)
		*(new + i) = *(*s1 + i);
	*(new + i) = c;
	free(*s1);
	*s1 = NULL;
	return (new);
}
