/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juveron <juveron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:26:01 by juveron           #+#    #+#             */
/*   Updated: 2018/11/30 14:25:35 by juveron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_extract_line(char **ptr, char **line, int fd, int ret)
{
	char	*tmp;
	int		x;

	x = 0;
	while (ptr[fd][x] != '\n' && ptr[fd][x] != '\0')
		x++;
	if (ptr[fd][x] == '\n')
	{
		*line = ft_strsub(ptr[fd], 0, x);
		tmp = ft_strdup(ptr[fd] + x + 1);
		free(ptr[fd]);
		ptr[fd] = tmp;
		if (ptr[fd][0] == '\0')
			ft_strdel(&ptr[fd]);
	}
	else if (ptr[fd][x] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(ptr[fd]);
		ft_strdel(&ptr[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*ptr[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ptr[fd] == NULL)
			ptr[fd] = ft_strnew(1);
		tmp = ft_strjoin(ptr[fd], buf);
		free(ptr[fd]);
		ptr[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (ptr[fd] == NULL || ptr[fd][0] == '\0'))
		return (0);
	return (ft_extract_line(ptr, line, fd, ret));
}
