#include "fractol.h"

void ene(t_fractol *f)
{
	mlx_close_window(f->mlx);
	mlx_delete_image(f->mlx, f->img);
	mlx_terminate(f->mlx);
	exit(-1);
}

void intro_msg(t_fractol *f)
{
	ft_printf("*********************************************\n");
	ft_printf("./fractol mandel [color]\n");
	ft_printf("./fractol julia [x] [y] [color]\n");
	ft_printf("[color]: Red = Fire,F,f | Blue = Water,W,w | Brown = Earth,E,e\n");
	ft_printf("*********************************************\n");
	if(f->inted == 1)
		ene(f);
	exit(0);
}

