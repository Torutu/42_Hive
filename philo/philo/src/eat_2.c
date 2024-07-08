/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:37:02 by walnaimi          #+#    #+#             */
/*   Updated: 2024/07/08 19:22:48 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * This file contains functions related to managing the forks and 
 * eating process of a philosopher.
 *
 * - drop_left_fork: Releases the left fork held by a philosopher.
 *
 * - drop_right_fork: Releases the right fork held by a philosopher.
 *
 * - take_left_fork: Attempts to take the left fork.
 *   Returns 1 if the philosopher has died or is in a dead state,
 *   otherwise locks the left fork and prints a message indicating the action.
 *
 * - take_right_fork: Attempts to take the right fork.
 *   Returns 1 if the philosopher has died or is in a dead state,
 *   otherwise locks the right fork and prints a message indicating the action.
 *
 * - take_forks: 
 *   Coordinates the process of a philosopher taking both forks needed to eat.
 *   - Handles special case for a single philosopher scenario.
 *   - compare the two available forks and see which one should be taken first
 *   - the first fork is taken and we check if the philo is dead already or not.
 *   - take the second fork and we check again if the philo is dead or not,
 *		if dead then we drop first fork.
 *   - Returns 1 if any failure occurs during the process.
 *   to test the order of threads use printf %p;
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
	if (philo->left_f < philo->right_f)
	{
		if (take_left_fork(philo) != 0)
			return (1);
		if (take_right_fork(philo) != 0)
		{
			drop_left_fork(philo);
			return (1);
		}
	}
	else
	{
		if (take_right_fork(philo) != 0)
			return (1);
		if (take_left_fork(philo) != 0)
		{
			drop_right_fork(philo);
			return (1);
		}
	}
	return (0);
}
