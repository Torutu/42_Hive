/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:05:44 by walnaimi          #+#    #+#             */
/*   Updated: 2023/11/18 14:57:41 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
atoi function is used to change part of a text (string)
into a whole number (integer)
*/

#include "libft.h"

int	ft_check_off(int sign)
{
	if (sign == 1)
		return ((int)FT_LONG_MAX);
	return ((int)-FT_LONG_MAX - 1L);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	num;
	long	pre;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		pre = num;
		num = (num * 10) + (str[i] - '0');
		if (num < 0 || pre > num)
			return (ft_check_off(sign));
		i++;
	}
	return (num * sign);
}
