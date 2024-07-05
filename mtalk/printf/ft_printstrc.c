/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstrc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:00:02 by walnaimi          #+#    #+#             */
/*   Updated: 2023/11/25 16:50:14 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	count;
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	i = 0;
	while (str[i])
	{
		count += write(1, &str[i++], 1);
		if (count != i)
			return (-1);
	}
	return (count);
}

int	ft_printchr(char c)
{
	return (write(1, &c, 1));
}
