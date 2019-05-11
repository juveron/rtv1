/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <jvitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:20:44 by jvitry            #+#    #+#             */
/*   Updated: 2019/05/09 15:30:58 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static t_list	*get_data(t_list **list, int fd)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(list, tmp);
	tmp = *list;
	return (tmp);
}

static int		ft_endgnl(char **buffer, char **line)
{
	unsigned long long int	i;
	int						flag;

	i = -1;
	flag = 0;
	ft_memdel((void **)line);
	*line = ft_strdup(*buffer);
	ft_memdel((void **)buffer);
	while ((*line)[++i])
		if ((*line)[i] == '\n')
		{
			flag = 1;
			(*line)[i] = '\0';
			*buffer = ft_strdup(&((*line)[i + 1]));
			break ;
		}
	if (i && !flag)
	{
		ft_memdel((void **)buffer);
		*buffer = NULL;
		return (1);
	}
	return (1 && flag);
}

static int		ft_fjoin(char **save, char *buffer)
{
	char	*tmp;

	tmp = ft_strdup(*save);
	ft_strdel((char **)save);
	if (!(*save = (char *)malloc(sizeof(char)
					* (ft_strlen(tmp) + BUFF_SIZE + 1))))
		return (0);
	*save = ft_strcpy(*save, tmp);
	*save = ft_strcat(*save, buffer);
	ft_strdel(&tmp);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static	t_list	*list;
	t_list			*tmp;
	char			buffer[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	tmp = get_data(&list, fd);
	if (!(*line = (char *)ft_strnew(1)))
		return (-1);
	if (!tmp->content)
		if (!(tmp->content = ft_strnew(1)))
			return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		if (!(ft_fjoin((char **)&tmp->content, buffer)))
			return (-1);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (ft_endgnl((char **)&tmp->content, line));
}
