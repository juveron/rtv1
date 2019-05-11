/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:37:19 by jvitry            #+#    #+#             */
/*   Updated: 2017/11/13 11:41:00 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char *)malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	new[size] = '\0';
	return (new);
}
