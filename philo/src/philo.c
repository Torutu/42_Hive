/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:38:03 by walnaimi          #+#    #+#             */
/*   Updated: 2024/07/03 15:38:04 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * run_threads: starts threads for each philospher and monitor them.
 * 
 * join_threads: wait for all philosopher and monitoring threads to finish and ends.
 *
 * philosophers: Initializes the dats and runs it by calling run threads and end it with join threads.
 *
 * main: the program starts here. checks input then calls philosophers.
 */

int	run_threads(t_data *data)
{
	int	i;
	int	nb_of_philos;

	nb_of_philos = get_nb_philos(data);
	i = -1;
	data->start_time = get_time();
	while (++i < nb_of_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL,
				&routine, &data->philos[i]))
			return (1);
	}
	if (pthread_create(&data->monit_all_alive, NULL,
			&all_alive_routine, data))
		return (1);
	if (nb_meals_option(data) == true
		&& pthread_create(&data->monit_all_full, NULL,
			&all_full_routine, data))
		return (1);
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nb_philos(data);
	i = -1;
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	if (nb_meals_option(data) == true
		&& pthread_join(data->monit_all_full, NULL))
		return (1);
	while (++i < nb_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return (1);
	}
	return (0);
}

int	philosophers(int argc, char **argv)
{
	t_data	data;

	if (init_data(&data, argc, argv) != 0)
		return (MALLOC_ERROR);
	init_philos(&data);
	init_forks(&data);
	run_threads(&data);
	join_threads(&data);
	free_data(&data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_input(argc, argv) != 0)
	{
		print_instruction();
		return (WRONG_INPUT);
	}
	if (philosophers(argc, argv) != 0)
		return (MALLOC_ERROR);
	return (0);
}

