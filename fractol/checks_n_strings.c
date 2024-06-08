#include "fractol.h"
#include <stdio.h>

void	check_colors(char *color,t_fractol *f)
{
	int color_type;
	if (!ft_strncmp (color, "f", 2) || !ft_strncmp(color, "F", 2) || !ft_strncmp(color, "Fire", 5))
	{
		color_type = 1;
		color_pallet(color_type,f);
	}
	else if (!ft_strncmp(color, "w", 2) || !ft_strncmp(color, "W", 2) || !ft_strncmp(color, "Water", 6))
	{
		color_type = 2;
		color_pallet(color_type,f);
	}
	else if (!ft_strncmp(color, "e", 2) || !ft_strncmp(color, "E", 2) || !ft_strncmp(color, "Earth", 6))
	{
		color_type = 3;
		color_pallet(color_type,f);
	}
	else
	{
		color = 0;
		intro_msg(f);
	}
}

void	check_args(t_fractol *f, char **av, int ac)
{
	char* c;

	if (!ft_strncmp(av[1], "mandel", 7) && ac == 3)
	{
		f->type = 1;
		c = av[2];
		check_colors(c,f);
	}
	else if(!ft_strncmp(av[1], "julia", 6) && ac == 5)
	{
		f->type = 2;
		c = av[4];
		f->c.x = ft_atof(av[2]);
		f->c.y = ft_atof(av[3]);
		check_colors(c,f);
	}
	else
		intro_msg(f);
}
