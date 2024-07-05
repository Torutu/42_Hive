/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:37:23 by walnaimi          #+#    #+#             */
/*   Updated: 2024/07/03 15:37:25 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * This file contains functions to safely retrieve
 * time-related parameters in a philosopher simulation.
 *
 * - get_die_time: Retrieves the time at which a philosopher should die.
 *
 * - get_sleep_time: Retrieves the time a philosopher spends sleeping.
 *
 * - get_eat_time: Retrieves the time a philosopher spends eating.
 *
 * - get_last_eat_time: Retrieves the last time a philosopher ate.
 *
 * Each function uses mutex locks to ensure
 * thread-safe access to the shared data structures,
 * preventing race conditions and ensuring
 * accurate time retrieval during concurrent execution.
 */

uint64_t	get_die_time(t_data *data)
{
	uint64_t	die_time;

	pthread_mutex_lock(&data->mut_die_t);
	die_time = data->die_time;
	pthread_mutex_unlock(&data->mut_die_t);
	return (die_time);
}

uint64_t	get_sleep_time(t_data *data)
{
	uint64_t	sleep_time;

	pthread_mutex_lock(&data->mut_sleep_t);
	sleep_time = data->sleep_time;
	pthread_mutex_unlock(&data->mut_sleep_t);
	return (sleep_time);
}

uint64_t	get_eat_time(t_data *data)
{
	uint64_t	eat_time;

	pthread_mutex_lock(&data->mut_eat_t);
	eat_time = data->eat_time;
	pthread_mutex_unlock(&data->mut_eat_t);
	return (eat_time);
}

uint64_t	get_last_eat_time(t_philo *philo)
{
	uint64_t	last_eat_time;

	pthread_mutex_lock(&philo->mut_last_eat_time);
	last_eat_time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->mut_last_eat_time);
	return (last_eat_time);
}
