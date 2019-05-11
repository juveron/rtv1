/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <jvitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:16:37 by jvitry            #+#    #+#             */
/*   Updated: 2017/11/16 14:47:40 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_isfullspace(void)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char))))
		return (NULL);
	str[0] = 0;
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char	*c_s;
	int		i;
	int		j;
	int		len;
	char	*str;

	c_s = (char *)s;
	if (c_s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(c_s);
	while ((c_s[i] == '\n' || c_s[i] == '\t' || c_s[i] == ' ') && c_s[i])
		i++;
	if (i >= len)
		return (ft_isfullspace());
	while (c_s[len - 1] == '\n' || c_s[len - 1] == '\t' || c_s[len - 1] == ' ')
		len--;
	if (!(str = (char *)malloc(sizeof(char) * len - i + 1)))
		return (NULL);
	j = 0;
	while (i < len)
		str[j++] = c_s[i++];
	str[j] = '\0';
	return (str);
}
