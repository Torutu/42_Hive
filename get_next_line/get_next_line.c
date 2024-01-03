/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:03:33 by walnaimi          #+#    #+#             */
/*   Updated: 2024/01/03 16:03:00 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 11

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    int buff;

    buff = read(fd, buffer, sizeof(buffer));

    if (buff <= 0)
    {
        buffer[0] = '\0';
        return buffer;
    }

    // Find the position of the newline character (if any)
    char *newline_ptr = strchr(buffer, '\n');

    if (newline_ptr != NULL)
    {
    // If newline found, replace it with '\0' to terminate the string
        *newline_ptr = '\0';
        return buffer;
    }

    // If no newline is found, return the entire buffer
    return buffer;
}
int main() {
    int fd;

    fd = open("text.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char *line = get_next_line(fd);
    while (line[0] != '\0') {
        printf("%s\n", line);
        line = get_next_line(fd);
    }

    close(fd);

    return 0;
}
/*int main()
{
	int fd;

	fd = open("text.txt", O_RDONLY);
	//char *line =  get_next_line(fd);
	//while(line)
	//{
		//printf("%s", line);
		//line = get_next_line(fd);
	//}

	printf("%s", get_next_line(fd));

	close(fd);

    return 0;
}*/