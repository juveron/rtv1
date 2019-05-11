/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:50:04 by jvitry            #+#    #+#             */
/*   Updated: 2017/11/14 16:50:09 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstbis;
	const char	*srcbis;

	dstbis = (char *)dst;
	srcbis = (const char *)src;
	while (n--)
		*dstbis++ = *srcbis++;
	return (dst);
}
