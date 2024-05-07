/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:17:13 by walnaimi          #+#    #+#             */
/*   Updated: 2024/04/09 12:12:56 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <signal.h>

void	send_signal(pid_t pid, char c)
{
	int		i;
	char	temp_c;

	i = 8;
	temp_c = c;
	while (i > 0)
	{
		i--;
		temp_c = c >> i;
		if ((temp_c & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(69);
	}
}

int	main(int ac, char *av[])
{
	pid_t	server_pid;
	char	*message;
	int		i;

	if (ac != 3)
	{
		ft_printf("./client <pid> <message>\n");
		return (1);
	}
	message = av[2];
	server_pid = ft_atoi(av[1]);
	i = 0;
	while (message[i])
		send_signal(server_pid, message[i++]);
	send_signal(server_pid, '\0');
	return (0);
}
