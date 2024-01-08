/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:40:11 by walnaimi          #+#    #+#             */
/*   Updated: 2024/01/08 15:36:46 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d == 0 && s == 0)
		return (0);
	while (n > 0)
	{
		*(d++) = *(s++);
		n--;
	}
	return (dst);
}
int ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (*str != c)
	{
		if (*str == '\0')
			return 0;
		str++;
		i++;
	}
	return (i);
}
char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}
char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int len1;
	int len2;
	char *dest;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	dest = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		dest[len1] = s2[i];
		len1++;
	}
	dest[len1] =  '\0';
	return (dest);
}
