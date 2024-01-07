/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:03:33 by walnaimi          #+#    #+#             */
/*   Updated: 2024/01/07 17:32:06 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	ch;

	str = (char *)s;
	ch = (char)c;
	i = 0;
	while (str[i] != ch)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (&str[i]);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*dest;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		dest = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (dest == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			dest[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			dest[len1] = s2[i];
			len1++;
		}
		dest[len1] = '\0';
		return (dest);
	}
	return (NULL);
}
char *get_next_line(int fd)
{
    static char buff[BUFFER_SIZE+1];
    char        *str;
    int         bytesRead;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    while(bytesRead)
    {
		bytesRead = read(fd, buff, BUFFER_SIZE);
        buff[bytesRead] = '\0';
        str = ft_strjoin(str, buff);
    }
    
    return str;
}
int main()
{
    int fd;

    fd = open("text.txt", O_RDONLY);
    printf("%s.\n",get_next_line(fd));

    close(fd);

    return 0;
}