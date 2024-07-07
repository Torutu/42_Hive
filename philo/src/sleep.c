/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:38:25 by walnaimi          #+#    #+#             */
/*   Updated: 2024/07/03 15:40:51 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * Function for simulating the sleep state of a philosopher.
 *
 * - ft_sleep: Sets the philosopher's state to SLEEPING.
 *   - Checks if the philosopher has transitioned to the
 *     DEAD state during the sleep state setup.
 *   - Prints a sleep message associated with the philosopher's ID.
 *   - Uses ft_usleep to simulate sleep for the specified sleep time.
 *
 * Returns 0 if sleep completes successfully,
 * otherwise returns 1 if the philosopher transitions to the DEAD state.
 */

int	ft_sleep(t_philo *philo)
{
	set_philo_state(philo, SLEEPING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	print_msg(philo->data, philo->id, SLEEP);
	ft_usleep(get_sleep_time(philo->data));
	return (0);
}
