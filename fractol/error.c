#include "fractol.h"

void ene(t_fractol *f)
{
	mlx_close_window(f->mlx);
	mlx_delete_image(f->mlx, f->img);
	mlx_terminate(f->mlx);
/*	if (f)
	{
		free(f);
		f = NULL;
	}*/
	exit(-1);
}

void intro_msg(t_fractol *f)
{
	ft_printf("*********************************************\n");
	ft_printf("./fractol mandel [color]\n");
	ft_printf("./fractol julia [x] [y] [color]\n");
	ft_printf("colors : f = fire | w = water | e = earth\n");
	ft_printf("*********************************************\n");
	ene(f);
}

