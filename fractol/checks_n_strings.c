#include "fractol.h"
#include <stdio.h>

void	check_colors(char color,t_fractol *f)
{
	int color_type;
	color_type = 0;
	if ('f' == color)
	{
		color_type = 1;
		color_pallet(color_type,f);
	}
	else if ('w' == color)
	{
		color_type = 2;
		color_pallet(color_type,f);
	}
	else if ('e' == color)
	{
		color_type = 3;
		color_pallet(color_type,f);
	}
	else
	{
		//color = 0;
		intro_msg;
	}
	color_pallet(color_type,f);
}

void	check_args(t_fractol *f, char **av, int ac)
{
	char c;

	if (ft_strncmp(av[1], "mandel", 7) == 0 && ac == 3)
	{
		f->type = 1;
		c = av[2][0];
		check_colors(c,f);
	}
	else if(ft_strncmp(av[1], "julia", 6) == 0 && ac == 5)
	{
		f->type = 2;
		c = av[4][0];
		f->c.x = ft_atof(av[2]);
		f->c.y = ft_atof(av[3]);
		check_colors(c,f);
	}
	else
		intro_msg;

}
