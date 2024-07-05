/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:09:15 by walnaimi          #+#    #+#             */
/*   Updated: 2023/12/05 11:55:39 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

# define HEX_L "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"

int	ft_printf(const char *s, ...);
int	ft_printint(int num);
int	ft_printchr(char c);
int	ft_printstr(char *str);
int	ft_numcount(long int num);
int	ft_printhex(unsigned long int num, char c);
int	count_hex(unsigned long int num);
int	ft_printptr(unsigned long int num);
int	ft_printuint(unsigned int num);

#endif