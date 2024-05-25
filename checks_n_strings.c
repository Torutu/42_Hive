#include "fractol.h"


void	check_colors(char color,t_fractol *f)
{
	int color_type;
	if ('f' == color)
	{
		color_type = 1;
		ft_printf("color is %c = fire\n", color);
		color_pallet(color_type,f);
	}
	else if ('w' == color)
	{
		color_type = 2;
		ft_printf("color is %c = water\n", color);
		color_pallet(color_type,f);
	}
	else if ('e' == color)
	{
		color_type = 3;
		ft_printf("color is %c = earth\n", color);
		color_pallet(color_type,f);
	}
	else
	{
		color = 0;
		ene(f);
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
		ft_printf("%c\n",c);
		check_colors(c,f);
		ft_printf("it is Mandel and the type is %d\n", f->type);
	}
	else if(ft_strncmp(av[1], "julia", 6) == 0 && ac == 5)
	{
		f->type = 2;
		c = av[4][0];
		check_colors(c,f);
		ft_printf("it is Julia and the type %d\n", f->type);
	}
	else
	{
		ft_printf("./fractol mandel\n./fractol Julia x y\n");
		exit(0);
	}
}
