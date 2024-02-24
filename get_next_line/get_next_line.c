/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:03:33 by walnaimi          #+#    #+#             */
/*   Updated: 2024/01/18 09:53:23 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*strchr_n_split(char *stocky)
{
	char	*line;
	int		i;

	i = 0;
	while (stocky[i] != '\0' && stocky[i++] != '\n')
		;
	if (stocky[i] == '\0')
		return (ft_strdup(stocky));
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stocky[i] != '\n' && stocky[i] != '\0')
	{
		line[i] = stocky[i];
		i++;
		if (stocky[i] == '\n')
			line[i] = stocky[i];
	}
	if (stocky[i] == '\n')
		line[i] = stocky[i];
	line[++i] = '\0';
	return (line);
}

static char	*get_line(int fd, char *stocky, char *buffy)
{
	int	bytes_read;

	bytes_read = 1;
	while (!ft_strchr(buffy, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffy, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffy);
			free(stocky);
			return (NULL);
		}
		buffy[bytes_read] = '\0';
		if (bytes_read)
			stocky = ft_strjoin(stocky, buffy);
		if (!ft_strlen(stocky))
		{
			free(buffy);
			free(stocky);
			return (NULL);
		}
	}
	free(buffy);
	buffy = NULL;
	return (stocky);
}

char	*get_next_line(int fd)
{
	static char	*stocky;
	char		*buffy;
	char		*line;
	int			linelen;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	buffy = malloc(BUFFER_SIZE + 1);
	if (!buffy)
		return (NULL);
	buffy[0] = '\0';
	stocky = get_line(fd, stocky, buffy);
	if (!stocky)
		return (NULL);
	line = strchr_n_split(stocky);
	if (!line)
		return (NULL);
	linelen = ft_strlen(line);
	while (stocky[linelen])
		stocky[i++] = stocky[linelen++];
	stocky[i] = '\0';
	return (line);
}
