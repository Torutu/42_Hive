/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:28:07 by walnaimi          #+#    #+#             */
/*   Updated: 2023/11/18 14:51:19 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The bzero() function is used to set a specific number of bytes in a
given memory area to zero. If you want to clear a portion of memory (set it to 0)
you can use bzero(). The "n" parameter specifies how many bytes
you want to set to zero. If "n" is 0, bzero() won't do anything

bzero() is like erasing or resetting a part of computer memory to contain 
all zeros
*/

void	ft_bzero(void *s, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
