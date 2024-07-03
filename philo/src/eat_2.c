/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:37:02 by walnaimi          #+#    #+#             */
/*   Updated: 2024/07/03 15:39:06 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * This file contains functions related to managing the forks and eating process of a philosopher.
 *
 * - drop_left_fork: Releases the left fork held by a philosopher.
 *
 * - drop_right_fork: Releases the right fork held by a philosopher.
 *
 * - take_left_fork: Attempts to take the left fork. Returns 1 if the philosopher has died or is in a dead state,
 *   otherwise locks the left fork and prints a message i	ndicating the action.
 *
 * - take_right_fork: Attempts to take the right fork. Returns 1 if the philosopher has died or is in a dead state,
 *   otherwise locks the right fork and prints a message indicating the action.
 *
 * - take_forks: Coordinates the process of a philosopher taking both forks needed to eat.
 *   - Handles special case for a single philosopher scenario.
 *   - Attempts to take the right fork first, then the left fork.
 *   - If taking the left fork fails, releases the right fork.
 *   - Returns 1 if any failure occurs during the process.
 */

void	drop_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_f);
}

void	drop_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_f);
}

int	take_left_fork(t_philo *philo)
{
	if (philo_died(philo) || get_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->left_f);
	print_msg(philo->data, philo->id, TAKE_FORKS);
	return (0);
}

int	take_right_fork(t_philo *philo)
{
	if (philo_died(philo) || get_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->right_f);
	print_msg(philo->data, philo->id, TAKE_FORKS);
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (get_nb_philos(philo->data) == 1)
		return (handle_1_philo(philo));
	if (take_right_fork(philo) != 0)
		return (1);
	if (take_left_fork(philo) != 0)
	{
		drop_right_fork(philo);
		return (1);
	}
	return (0);
}
