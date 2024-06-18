/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_substr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:18:47 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/09 15:18:48 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_parse_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	size;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	s_len -= start;
	size = (s_len < len) * s_len + (s_len >= len) * len;
	sub = malloc(size + 1);
	if (!sub)
		return (0);
	ft_strlcpy(sub, (char *)s + start, size + 1);
	return (sub);
}
