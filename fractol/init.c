#include "fractol.h"

void my_mlx_init(t_fractol *f)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if	(!(f->mlx))
		ene(f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if	(!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
		ene(f);
}

void color_count(t_fractol *f)
{
	f->fcolor.color_count1 = 2;
	f->fcolor.color_count2 = 4;
	f->fcolor.color_count3 = 6;
	f->fcolor.color_count4 = 8;
	f->fcolor.color_count5 = 10;
}
void init(t_fractol *f)
{
	f->esc =	   4;
	f->z.x =	   0;
	f->z.y =	   0;
	if (f->type == 1 || f->type == 3)
	{
		f->c.x =	   0;
		f->c.y =	   0;
	}
	f->x   =	   0;
	f->y   =	   0;
	f->esc_value = 4;
	f->zoom =	   1.0;
	f->mlx =	   NULL;
	f->img =       NULL;
	f->off_x =	   0;
	f->off_y =     0;
	f->iter =	   80;
	f->zoom_in_count = 0;
	f->zoom_out_count = 0;
	calculate_offsets(f);
	if (WIDTH > HEIGHT)
		f->max_dim = WIDTH;
	else
		f->max_dim = HEIGHT;
	my_mlx_init(f);
}

