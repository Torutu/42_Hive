/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:26:07 by walnaimi          #+#    #+#             */
/*   Updated: 2023/11/16 19:45:26 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	v;

	if (len == 0 && haystack == 0)
		return (NULL);
	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		v = 0;
		if (haystack[i] == needle[v])
		{
			while (i + v < len && haystack[i + v] == needle[v])
			{
				v++;
				if (!needle[v])
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (0);
}
