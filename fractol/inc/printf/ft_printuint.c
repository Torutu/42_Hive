/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:57:23 by walnaimi          #+#    #+#             */
/*   Updated: 2023/11/27 16:07:29 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putunum(unsigned int num)
{
	if (num > 9)
	{
		if (ft_putunum(num / 10) == -1 || ft_putunum(num % 10) == -1)
			return (-1);
	}
	else
	{
		if (ft_printchr(num + 48) == -1)
			return (-1);
	}
	return (0);
}

int	ft_printuint(unsigned int num)
{
	if (ft_putunum(num) == -1)
		return (-1);
	return (ft_numcount(num));
}
