/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:36:41 by walnaimi          #+#    #+#             */
/*   Updated: 2024/07/08 19:23:04 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * drop_forks: Releases the forks held by a philosopher.
 *
 * update_last_meal_time: Updates the last meal time for a philosopher.
 *
 * update_nb_meals_had: Increments the number of meals a philosopher has had.
 *
 * sleep_for_eating: Pauses execution for the time it takes a philosopher to eat.
 *
 * eat: Manages the entire eating process for a philosopher,
 * including taking forks, setting state to eating,
 *   printing messages, updating last meal time,sleeping for the eating duration,
 *   updating the number of meals had, and dropping forks.
 */

#include "../include/philo.h"

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_last_eat_time);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->mut_last_eat_time);
}

void	update_nb_meals_had(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_nb_meals_had);
	philo->nb_meals_had++;
	pthread_mutex_unlock(&philo->mut_nb_meals_had);
}

void	sleep_for_eating(t_philo *philo)
{
	ft_usleep(get_eat_time(philo->data));
}

int	eat(t_philo *philo)
{
	if (take_forks(philo) != 0)
		return (1);
	set_philo_state(philo, EATING);
	print_msg(philo->data, philo->id, EAT);
	update_last_meal_time(philo);
	sleep_for_eating(philo);
	update_nb_meals_had(philo);
	drop_forks(philo);
	return (0);
}
