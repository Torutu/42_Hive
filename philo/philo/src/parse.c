/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:37:53 by walnaimi          #+#    #+#             */
/*   Updated: 2024/07/08 19:24:24 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * Functions for validating and printing
 * instructions for the philosopher simulation.
 *
 * - print_instruction: Prints usage instructions
 *   and example for running the program.
 *
 * - wrong_input_check: Checks command-line
 *   arguments for valid numerical inputs and optional constraints.
 *
 * - ft_atoi: Converts a string to an integer,
 *   handling signs and whitespace characters.
 *
 * - is_input_digit: Checks if all command-line arguments are numeric digits.
 *
 * - check_input: Validates the number and format of command-line
 *   arguments for the simulation.
 *   - Ensures correct input format and ranges
 *   for philosopher count, times, and optional meals count.
 *
 * Returns WRONG_INPUT if any validation fails,
 * otherwise returns 0 for valid input.
 */

void	print_instruction(void)
{
	printf("\t\tWRONG INPUT!\n\n");
	printf("./philo nb_philos time_to_die ");
	printf("time_to_eat time_to_sleep ");
	printf("number_of_times_each_philosopher_must_eat ");
	printf("(optional argument)\n");
	printf("Example:\n\n");
	printf("./philo 4 800 200 200 5\n");
	printf("each input should be from 1 to 2147483647\n");
}

int	wrong_input_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (WRONG_INPUT);
	if (ft_atoi(argv[i]) < 1 || ft_atoi(argv[i]) > 2147483647)
		return (WRONG_INPUT);
	while (++i < 5)
	{
		if (ft_atoi(argv[i]) < 1)
			return (WRONG_INPUT);
	}
	return (0);
}

u_int64_t	ft_atoi(char *str)
{
	int		count;
	long	result;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while (str[count] == '\r' || str[count] == '\t' || str[count] == ' '
		|| str[count] == '\f' || str[count] == '\v' || str[count] == '\n')
		count++;
	if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	if (!(str[count] >= '0' && str[count] <= '9'))
		return (0);
	while (str[count] >= '0' && str[count] <= '9')
		result = result * 10 + (str[count++] - '0');
	return (result * sign);
}

int	is_input_digit(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			if (argv[i][k] < '0' || argv[i][k] > '9')
			{
				return (WRONG_INPUT);
			}
			k++;
		}
		i++;
	}
	return (0);
}

int	check_input(int argc, char **argv)
{
	if (argc < 5)
		return (WRONG_INPUT);
	if (argc > 6)
		return (WRONG_INPUT);
	if (is_input_digit(argc, argv) != 0)
		return (WRONG_INPUT);
	if (wrong_input_check(argc, argv))
		return (WRONG_INPUT);
	return (0);
}
