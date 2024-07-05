/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:54:00 by walnaimi          #+#    #+#             */
/*   Updated: 2023/11/25 15:15:42 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long int num)
{
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (ft_printhex(num, 'p') == -1)
		return (-1);
	return (count_hex(num) + 2);
}
