/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <jvitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:29:07 by jvitry            #+#    #+#             */
/*   Updated: 2019/05/09 15:26:11 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **begin_list)
{
	t_list	*t;
	t_list	*f;

	t = *begin_list;
	while (t)
	{
		f = t;
		t = t->next;
		free(f);
	}
	*begin_list = t;
}
