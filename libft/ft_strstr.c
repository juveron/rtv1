/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 10:05:01 by jvitry            #+#    #+#             */
/*   Updated: 2017/11/28 18:10:51 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int b;
	int a;

	a = 0;
	b = 0;
	i = 0;
	while (to_find[i] != '\0')
		i++;
	if (i == 0)
		return ((char*)str);
	while (str[a] != '\0')
	{
		while (str[a] == to_find[b])
		{
			a++;
			b++;
			if (to_find[b] == '\0')
				return ((char*)str + (a - b));
		}
		a = a - b;
		b = 0;
		a += 1;
	}
	return (0);
}
