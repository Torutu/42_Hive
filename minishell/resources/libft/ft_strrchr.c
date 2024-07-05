/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:46:55 by walnaimi          #+#    #+#             */
/*   Updated: 2023/11/16 19:45:28 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char const	*z_str;

	z_str = 0;
	while (*s)
	{
		if (*s == (char)c)
			z_str = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)z_str);
}
