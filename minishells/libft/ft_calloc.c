/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:30:43 by walnaimi          #+#    #+#             */
/*   Updated: 2023/11/16 20:51:48 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The calloc() function is used to reserve a block of memory large enough
to store a specified number of objects, with each object having a specified
size in bytes. It then returns a pointer to this reserved memory.
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	if (count && size && count > (UINT_MAX / size))
		return (NULL);
	memory = malloc(count * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, count * size);
	return (memory);
}
