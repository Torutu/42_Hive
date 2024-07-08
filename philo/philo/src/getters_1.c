/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:37:13 by walnaimi          #+#    #+#             */
/*   Updated: 2024/07/08 19:23:16 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * This file contains functions to safely
 * access shared data in a philosopher simulation.
 *
 * - get_keep_iter: Retrieves the boolean flag indicating
 *   whether the simulation should continue iterating.
 *
 * - get_nb_philos: Retrieves the number of philosophers
 *   participating in the simulation.
 *
 * - get_philo_state: Retrieves the current state of
 *   a philosopher (e.g., eating, thinking, or dead).
 *
 * - get_nb_meals_philo_had: Retrieves the number
 *   of meals a philosopher has consumed.
 *
 * - get_start_time: Retrieves the start time of the simulation.
 *
 * Each function uses mutex locks to ensure
 * thread-safe access to the shared data structures,
 * preventing race conditions and ensuring
 * data integrity during concurrent execution.
 */

bool	get_keep_iter(t_data *data)
{
	bool	keep_iterating;

	pthread_mutex_lock(&data->mut_keep_iter);
	keep_iterating = data->keep_iterating;
	pthread_mutex_unlock(&data->mut_keep_iter);
	return (keep_iterating);
}

int	get_nb_philos(t_data *data)
{
	int	nb_philos;

	pthread_mutex_lock(&data->mut_nb_philos);
	nb_philos = data->nb_philos;
	pthread_mutex_unlock(&data->mut_nb_philos);
	return (nb_philos);
}

t_state	get_philo_state(t_philo *philo)
{
	t_state	state;

	pthread_mutex_lock(&philo->mut_state);
	state = philo->state;
	pthread_mutex_unlock(&philo->mut_state);
	return (state);
}

int	get_nb_meals_philo_had(t_philo *philo)
{
	int	nb_meals_had;

	pthread_mutex_lock(&philo->mut_nb_meals_had);
	nb_meals_had = philo->nb_meals_had;
	pthread_mutex_unlock(&philo->mut_nb_meals_had);
	return (nb_meals_had);
}

uint64_t	get_start_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->mut_start_time);
	time = data->start_time;
	pthread_mutex_unlock(&data->mut_start_time);
	return (time);
}
