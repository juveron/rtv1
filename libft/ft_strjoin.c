/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <jvitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:03:27 by jvitry            #+#    #+#             */
/*   Updated: 2017/11/23 10:18:45 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static char			*fjoi(char *dst, char const *s2, unsigned int i, char *tmp)
{
	size_t			len;
	unsigned int	j;

	len = ft_strlen(tmp);
	j = 0;
	while (j < len)
	{
		dst[i] = tmp[j];
		i++;
		j++;
	}
	if (tmp == s2)
		return (dst);
	return (fjoi(dst, s2, i, (char *)s2));
}

char				*ft_strjoin(char *s1, char const *s2)
{
	size_t			size;
	char			*join;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	join = ft_memalloc(size + 1);
	if (!join)
		return (NULL);
	i = 0;
	fjoi(join, s2, i, (char *)s1);
	return (join);
}
