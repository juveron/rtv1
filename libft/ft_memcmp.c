/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:51:13 by jvitry            #+#    #+#             */
/*   Updated: 2017/11/14 16:51:14 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1bis;
	const unsigned char	*s2bis;

	s1bis = s1;
	s2bis = s2;
	while (n--)
	{
		if (*s1bis != *s2bis)
		{
			return (*s1bis - *s2bis);
		}
		s1bis++;
		s2bis++;
	}
	return (0);
}
