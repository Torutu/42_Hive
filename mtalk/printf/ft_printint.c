/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:58:23 by walnaimi          #+#    #+#             */
/*   Updated: 2023/11/27 17:04:24 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_putnum(int nb)
{
	if (nb == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (0);
	}
	else if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nb = -nb;
		ft_putnum(nb);
	}
	else if (nb > 9)
	{
		if (ft_putnum(nb / 10) == -1 || ft_putnum(nb % 10) == -1)
			return (-1);
	}
	else
		if (ft_printchr(nb + 48) == -1)
			return (-1);
	return (0);
}

int	ft_numcount(long int num)
{
	int	count;

	count = 0;
	if (num <= 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_printint(int num)
{
	if (ft_putnum(num) == -1)
		return (-1);
	return (ft_numcount(num));
}
