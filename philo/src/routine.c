/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:38:09 by walnaimi          #+#    #+#             */
/*   Updated: 2024/07/03 15:40:26 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * Function for simulating the life cycle of a
 * philosopher and printing the number of meals eaten.
 *
 * - routine: Simulates the routine of a philosopher,
 *   including eating, sleeping, and thinking.
 *   - Updates the last meal time and adjusts sleep
 *   time for even-numbered philosophers.
 *   - Continues looping until the philosopher's state changes to DEAD.
 *   - Calls eat, ft_sleep, and think functions in sequence.
 *
 */

void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *) philo_p;
	update_last_meal_time(philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time - 10);
	while (get_philo_state(philo) != DEAD)
	{
		if (eat(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (think(philo) != 0)
			break ;
	}
	return (NULL);
}
