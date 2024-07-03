/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:38:42 by walnaimi          #+#    #+#             */
/*   Updated: 2024/07/03 15:41:13 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * Functions for time management and thread synchronization:
 *
 * - wait_until: Waits until a specified wakeup time is reached, with a small margin for accuracy.
 *               Uses usleep to pause execution until the time condition is met.
 *
 * - ft_usleep: Simulates a sleep delay by polling the current time until the specified sleep_time has elapsed.
 *
 * - get_time: Retrieves the current system time in milliseconds since the Unix epoch using gettimeofday().
 */

void	wait_until(u_int64_t wakeup_time)
{
	int			margin;
	u_int64_t	time;

	margin = 5;
	while (1)
	{
		time = get_time();
		if (wakeup_time <= time + margin)
		{
			while (wakeup_time > time)
				time = get_time();
			break ;
		}
		else
		{
			usleep(1000 * (wakeup_time - time - margin));
		}
	}
}

void	ft_usleep(uint64_t sleep_time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(500);
}

u_int64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}
