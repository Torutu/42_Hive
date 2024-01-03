/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:03:33 by walnaimi          #+#    #+#             */
/*   Updated: 2024/01/03 17:49:18 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
	char 		*newline_ptr;
    int 		buff;

    buff = read(fd, buffer, BUFFER_SIZE);

    if (buff <= 0)
    {
        buffer[0] = '\0';
        return buffer;
    }
    newline_ptr = strchr(buffer, '\n');

    if (newline_ptr != NULL)
    {
        *newline_ptr = '\0';
        return buffer;
    }

    return buffer;
}
int main() {
    int fd;

    fd = open("text.txt", O_RDONLY);
    char *line = get_next_line(fd);
    while (line[0] != '\0') {
        printf("%s.\n", line);
        line = get_next_line(fd);
    }

    close(fd);

    return 0;
}