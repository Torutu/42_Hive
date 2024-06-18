/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:21:14 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/09 15:21:16 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	char	*cur;
	int		len;

	s = (char *)str;
	len = ft_strlen(s);
	cur = s + len;
	while (*cur != (unsigned char)c)
	{
		if (cur == s)
			return (NULL);
		cur--;
	}
	return (cur);
}
