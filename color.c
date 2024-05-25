#include "fractol.h"

void iter_check(int iter,t_fractol *f)
{
	uint32_t color;
	color = 0;
	if (iter == MAXITERATIONS)
		color = 0x000000FF;
	else if(iter <= 2)
		color = f->fcolor.color_1;
	else if(iter <= 4)
		color = f->fcolor.color_2;
	else if(iter <= 8)
		color = f->fcolor.color_3;
	else if(iter <= 10)
		color = f->fcolor.color_4;
	else
		color = f->fcolor.color_5;
	mlx_put_pixel(f->img, f->x, f->y, color);
}
