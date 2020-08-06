/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:07:09 by epalomak          #+#    #+#             */
/*   Updated: 2019/11/25 15:50:44 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static	int	ft_line(char **src, char **line)
{
	int		i;
	char	*next;

	i = 0;
	while (src[0][i] != '\n' && src[0][i] != '\0')
		i++;
	if (src[0][i] == '\n')
	{
		*line = ft_strsub(src[0], 0, i);
		next = ft_strdup(src[0] + (i + 1));
		free(src[0]);
		src[0] = next;
	}
	else if (src[0][i] == '\0')
	{
		*line = ft_strdup(src[0]);
		ft_strdel(&src[0]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*str[MAX_FD];
	char		*tmp;

	if (!line || fd < 0 || fd > MAX_FD)
		return (-1);
	if (str[fd] == NULL)
		if (!(str[fd] = ft_strnew(0)))
			return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (ret < 0 || str[fd] == NULL)
		return (-1);
	if (ret == 0 && str[fd][0] == '\0')
		return (0);
	return (ft_line(&str[fd], line));
}
