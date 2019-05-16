/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:25:42 by jvitry            #+#    #+#             */
/*   Updated: 2017/11/17 15:25:43 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*content_cpy;
	size_t	size;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		content_cpy = NULL;
		size = 0;
	}
	else
	{
		if (!(content_cpy = malloc(content_size)))
			return (NULL);
		ft_memcpy(content_cpy, (void*)content, content_size);
		size = content_size;
	}
	new->content = content_cpy;
	new->content_size = size;
	new->next = NULL;
	return (new);
}
