#include "libft.h"

double  ft_atof(const char *str)
{
        double  res;
        double  res2;
        char    *c;
        int     len;
        int     sign;

        sign = 1;
        c = (char *)str;
        if (str[0] == '-')
        {
                sign *= -1;
                c++;
        }
        res = (double)ft_atoi(c);
        while (*c && *c != '.')
                c++;
        if (*c == '.')
                c++;
        res2 = (double)ft_atoi(c);
        len = ft_strlen(c);
        while (len--)
		{
                res2 /= 10;
		}
        return (sign * (res + res2));
}
