/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:49:52 by jvitry            #+#    #+#             */
/*   Updated: 2017/11/17 12:56:23 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str_src;
	char	*str_dst;

	str_src = (char*)src;
	str_dst = (char*)dst;
	if (str_src < str_dst)
	{
		str_src = str_src + len - 1;
		str_dst = str_dst + len - 1;
		while (len > 0)
		{
			*str_dst-- = *str_src--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*str_dst++ = *str_src++;
			len--;
		}
	}
	return (dst);
}
