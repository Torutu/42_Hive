#include "fractol.h"

void	ene(t_fractol *f)
{
	mlx_close_window(f->mlx);
	mlx_delete_image(f->mlx, f->img);
	mlx_terminate(f->mlx);
	exit(0);
}
void	errormsg(t_fractol *f)
{
	ft_printf("./fractol [fractal] (if julia[x][y]) [color]\n");
	ft_printf("fractals = mandel , julia\n");
	ft_printf("colors   = fire , water, earth\n");
	ft_printf("for julia pick a small number\n");
	ene(f);
}

void my_mlx_init(t_fractol *f)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if	(!(f->mlx))
		ene(f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if	(!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
		ene(f);
}

void init(t_fractol *f)
{
	f->esc =	   4;
	f->z.x =	   0;
	f->z.y =	   0;
	f->c.x =	   0;
	f->c.y =	   0;
	f->x   =	   0;
	f->y   =	   0;
	f->esc_value = 4;
	f->zoom =	   1;
	if (WIDTH > HEIGHT)
		f->max_dim = WIDTH;
	else
		f->max_dim = HEIGHT;
	my_mlx_init(f);
}

