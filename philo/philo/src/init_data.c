/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:37:31 by walnaimi          #+#    #+#             */
/*   Updated: 2024/07/08 19:24:08 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * This file contains functions for initializing
 * data structures and resources in a philosopher simulation.
 *
 * - init_forks: Initializes mutexes for each fork 
 *   and assigns them to philosophers.
 *   - Each philosopher is assigned two forks based
 *   on their position in the array.
 *
 * - init_philos: Initializes each philosopher
 *   with necessary data and mutexes for state, meal count, and last meal time.
 *
 * - malloc_data: Allocates memory for philosopher data structures,
 *   forks (mutexes), and thread identifiers.
 *
 * - init_data: Initializes simulation parameters and mutexes
 *   for time-related variables and synchronization.
 *   - Parses command-line arguments to set the number of philosophers,
 *   time parameters, and optional meal count.
 *   - Initializes mutexes for time parameters and synchronization flags.
 *   - Calls malloc_data to allocate memory for data structures.
 *
 * Each function ensures proper initialization and allocation of resources
 * necessary for running the philosopher simulation,
 * while using mutex locks to maintain thread safety and prevent
 * data races during concurrent execution.
 */

int	init_forks(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = data->philos;
	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	philos[0].left_f = &data->forks[0];
	philos[0].right_f = &data->forks[data->nb_philos - 1];
	while (++i < data->nb_philos)
	{
		philos[i].left_f = &data->forks[i];
		philos[i].right_f = &data->forks[i - 1];
	}
	return (0);
}

int	init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = data->philos;
	while (++i < data->nb_philos)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].nb_meals_had = 0;
		philos[i].state = IDLE;
		pthread_mutex_init(&philos[i].mut_state, NULL);
		pthread_mutex_init(&philos[i].mut_nb_meals_had, NULL);
		pthread_mutex_init(&philos[i].mut_last_eat_time, NULL);
		update_last_meal_time(&philos[i]);
	}
	return (0);
}

int	malloc_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philos == NULL)
	{
		printf("couldn't allocate memory init_philos.\n");
		return (MALLOC_ERROR);
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (data->forks == NULL)
	{
		printf("couldn't allocate memory for init_mutexes.\n");
		return (free(data->philos), MALLOC_ERROR);
	}
	data->philo_ths = malloc(sizeof(pthread_t) * data->nb_philos);
	if (data->philo_ths == NULL)
	{
		printf("couldn't allocate memory for init_threads.\n");
		return (free(data->philos), free(data->forks), MALLOC_ERROR);
	}
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_full_p = 0;
	data->keep_iterating = true;
	data->nb_philos = ft_atoi(argv[1]);
	data->die_time = (u_int64_t) ft_atoi(argv[2]);
	data->eat_time = (u_int64_t) ft_atoi(argv[3]);
	data->sleep_time = (u_int64_t) ft_atoi(argv[4]);
	data->nb_meals = -1;
	if (argc == 6)
		data->nb_meals = ft_atoi(argv[5]);
	pthread_mutex_init(&data->mut_eat_t, NULL);
	pthread_mutex_init(&data->mut_sleep_t, NULL);
	pthread_mutex_init(&data->mut_die_t, NULL);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_nb_philos, NULL);
	pthread_mutex_init(&data->mut_keep_iter, NULL);
	pthread_mutex_init(&data->mut_start_time, NULL);
	return (malloc_data(data));
}
