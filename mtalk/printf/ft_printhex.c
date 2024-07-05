/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:55:07 by walnaimi          #+#    #+#             */
/*   Updated: 2023/11/25 17:12:31 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex(unsigned long int num, char c)
{
	if (num > 15)
		if (ft_hex(num / 16, c) == -1 || ft_hex(num % 16, c) == -1)
			return (-1);
	if (num <= 9)
	{
		num = num + '0';
		if (write(1, &num, 1) == -1)
			return (-1);
	}
	else if (num <= 15)
	{
		if (c == 'x' || c == 'p')
		{
			if (write(1, &HEX_L[num], 1) == -1)
				return (-1);
		}
		else
		{
			if (write(1, &HEX_U[num], 1) == -1)
				return (-1);
		}
	}
	return (0);
}

int	count_hex(unsigned long int num)
{
	int	count;

	count = 0;
	if (num == 0)
		count++;
	while (num != 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

int	ft_printhex(unsigned long int num, char c)
{
	if (ft_hex(num, c) == -1)
		return (-1);
	return (count_hex(num));
}
