/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchieric <fchieric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:17:03 by fchieric          #+#    #+#             */
/*   Updated: 2024/02/26 18:45:05 by fchieric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_alloc(char *ptr)
{
	char	*res;

	res = ft_calloc(ft_strlen(ptr) + BUFFER_SIZE + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (ptr)
		ft_strcat(res, ptr);
	free(ptr);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			readreturn;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readreturn = 1;
	line = NULL;
	while (!ft_strchr(line, '\n'))
	{
		if (!*buffer[fd])
			readreturn = read(fd, buffer[fd], BUFFER_SIZE);
		if (readreturn <= 0)
			break ;
		line = gnl_alloc(line);
		strcat_nl(line, buffer[fd]);
	}
	if (line && *line)
		return (line);
	free(line);
	return (NULL);
}
