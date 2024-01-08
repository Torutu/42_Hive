/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:03:33 by walnaimi          #+#    #+#             */
/*   Updated: 2024/01/08 15:37:31 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"
char	*ft_read(int fd, char *str)
{
	int bytes;
	char buff[BUFFER_SIZE + 1];

	bytes = 1;
	while (!ft_strchr(str,'\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			return NULL;
		}
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}
char	*ft_rhyme(char *s)
{
	int		 i;
	char	*rhyme;

	i = 0;
	if (!s[i])
		return (NULL);;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	rhyme = malloc(i + 1);
	if (!rhyme)
		return (NULL);
	rhyme[i--] = 0;
	while (i >= 0)
	{
		rhyme[i] = s[i];
		i--;
	}
	return (rhyme);
}
char	*next_rhyme(char *str)
{
	ssize_t i;
	ssize_t j;
	char   *s;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	s = malloc(ft_strlen(str) - i + 1);
	if (!s)
		return NULL;
	i++;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	free (str);
	return (s);
}
char *get_next_line(int fd)
{
    static char        *str;
	char 				*c;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	c = ft_rhyme(str);
	str = next_rhyme(str);
	return (c);
}
/*
int main()
{
    int fd;

    fd = open("text.txt", O_RDONLY);
    char *line = get_next_line(fd);
    
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }

    close(fd);

    return 0;
}
*/