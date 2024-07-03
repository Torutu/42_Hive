/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:38:51 by walnaimi          #+#    #+#             */
/*   Updated: 2024/07/03 15:38:52 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * Miscellaneous utility functions for the dining philosophers problem:
 *
 * - handle_1_philo: Handles the special case where there's only one philosopher.
 *                   Takes the left fork, sleeps for the die time, then sets the philosopher to DEAD state.
 *
 * - nb_meals_option: Checks if the number of meals option is enabled.
 *                    Returns true if data->nb_meals > 0, otherwise false.
 *
 * - free_data: Frees dynamically allocated memory and destroys mutexes used in t_data struct.
 *              Destroys mutexes for forks, philosopher states, meals had, last eat time, and other control mutexes.
 *
 * - print_msg: Prints a formatted message with timestamp, philosopher id, and message content.
 *              Uses mutex locking to ensure thread-safe printing if keep_iterating is true.
 *
 * - print_mut: Prints a simple message to stdout, protected by mutex to ensure thread safety.
 */

int	handle_1_philo(t_philo *philo)
{
	take_left_fork(philo);
	ft_usleep(get_die_time(philo->data));
	set_philo_state(philo, DEAD);
	return (1);
}

bool	nb_meals_option(t_data *data)
{
	if (data->nb_meals > 0)
		return (true);
	return (false);
}

void	free_data(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nb_philos(data);
	i = -1;
	while (++i < nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mut_state);
		pthread_mutex_destroy(&data->philos[i].mut_nb_meals_had);
		pthread_mutex_destroy(&data->philos[i].mut_last_eat_time);
	}
	pthread_mutex_destroy(&data->mut_die_t);
	pthread_mutex_destroy(&data->mut_eat_t);
	pthread_mutex_destroy(&data->mut_sleep_t);
	pthread_mutex_destroy(&data->mut_nb_philos);
	pthread_mutex_destroy(&data->mut_print);
	pthread_mutex_destroy(&data->mut_keep_iter);
	pthread_mutex_destroy(&data->mut_start_time);
	free(data->philo_ths);
	free(data->philos);
	free(data->forks);
}

void	print_msg(t_data *data, int id, char *msg)
{
	uint64_t	time;

	time = get_time() - get_start_time(data);
	pthread_mutex_lock(&data->mut_print);
	if (get_keep_iter(data))
		printf("%lu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mut_print);
}

void	print_mut(t_data *data, char *msg)
{
	pthread_mutex_lock(&data->mut_print);
	printf("%s\n", msg);
	pthread_mutex_unlock(&data->mut_print);
}
