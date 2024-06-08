#include "fractol.h"

void iter_check(int iter,t_fractol *f)
{
	uint32_t color;

	color = 0;

	int color_range;

	color_range = f->iter / 5;

	if (iter < color_range)
		color = f->fcolor.color_1;
	else if (iter < color_range * 2)
		color = f->fcolor.color_2;
	else if (iter < color_range * 3)
		color = f->fcolor.color_3;
	else if (iter < color_range * 4)
		color = f->fcolor.color_4;
	else
		color = f->fcolor.color_5;

	mlx_put_pixel(f->img, f->x, f->y, color);
}
