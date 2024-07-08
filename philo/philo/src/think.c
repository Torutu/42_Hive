/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:38:33 by walnaimi          #+#    #+#             */
/*   Updated: 2024/07/08 19:24:58 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * Function for simulating the thinking state of a philosopher.
 *
 * - think: Sets the philosopher's state to THINKING.
 *   - Checks if the philosopher has transitioned to the DEAD
 *   state during the thinking state setup.
 *   - Prints a thinking message associated with the philosopher's ID.
 *
 * Returns 0 if the thinking state setup completes
 * successfully, otherwise returns 1 if the
 * philosopher transitions to the DEAD state.
 */

int	think(t_philo *philo)
{
	set_philo_state(philo, THINKING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	print_msg(philo->data, philo->id, THINK);
	return (0);
}
