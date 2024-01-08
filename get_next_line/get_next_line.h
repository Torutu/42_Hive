/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:57:20 by walnaimi          #+#    #+#             */
/*   Updated: 2024/01/08 15:20:24 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stdlib.h>
# include<fcntl.h>
# include<stdio.h>
# include<unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char    *get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int 	ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_rhyme(char *s);
char	*ft_read(int fd, char *str);
char	*next_rhyme(char *str);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif
