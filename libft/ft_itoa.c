/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <jvitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:53:29 by jvitry            #+#    #+#             */
/*   Updated: 2017/11/17 11:27:00 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		nbrlen(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int			len;
	int			signe;
	char		*str;

	signe = 1;
	len = nbrlen(n);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (n != 0)
	{
		if (n < 0)
		{
			str[0] = '-';
			signe = -1;
		}
		str[len - 1] = (((n % 10) * (signe)) + '0');
		n = (n / 10);
		len--;
	}
	return (str);
}
