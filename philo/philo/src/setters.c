/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:38:18 by walnaimi          #+#    #+#             */
/*   Updated: 2024/07/08 19:24:47 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * Functions for setting data values with thread safety.
 *
 * - set_keep_iterating: Sets the 'keep_iterating' flag 
 *   in 't_data' structure to the specified boolean value.
 *   - Ensures thread safety by locking 'mut_keep_iter'
 *   mutex before updating the flag and unlocking afterward.
 *
 * - set_philo_state: Sets the state of a philosopher
 *   ('philo') to the specified 'state'.
 *   - Ensures thread safety by locking 'mut_state'
 *   mutex before updating the state if the philosopher is not DEAD,
 *     and unlocks the mutex afterward.
 */

void	set_keep_iterating(t_data *data, bool set_to)
{
	pthread_mutex_lock(&data->mut_keep_iter);
	data->keep_iterating = set_to;
	pthread_mutex_unlock(&data->mut_keep_iter);
}

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->mut_state);
	if (philo->state != DEAD)
		philo->state = state;
	pthread_mutex_unlock(&philo->mut_state);
}
