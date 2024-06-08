#include "fractol.h"

void	drawhook(void *f)
{
	t_fractol	*nf;

	nf = f;
	draw_fractal(nf);
}

void	draw_fractal(t_fractol *f)
{
        f->x = 0;
        f->y = 0;
        while (f->x < WIDTH)
        {
                while (f->y < HEIGHT)
                {
					if (f->type == 1)
					{
						draw_mandel(f);
					}
					else if (f->type == 2)
					{
						draw_julia(f);
					}
					else
					{
						ene(f);
					}
                        f->y++;
                }
                f->x++;
                f->y = 0;
        }
}

void draw_mandel(t_fractol *f)
{
			int32_t color;
            int i;
            i = 0;
            f->z.x = 0.0;
            f->z.y = 0.0;
            f->c.x = (scale(f->x, f->max_dim, -2, +2) * f->zoom) + f->off_x;
            f->c.y = (scale(f->y, f->max_dim, +2, -2) * f->zoom) + f->off_y;
            while (i < f->iter)
            {
                f->z = complex_add(complex_square(f->z), f->c);
                if ((f->z.x * f->z.x) + (f->z.y * f->z.y) > f->esc)
                    break;
                i++;
            }

			if (i == f->iter)
			{
				color = 0x000000FF;
				mlx_put_pixel(f->img, f->x, f->y, color);
			}
			else
				iter_check(i,f);
}

void draw_julia(t_fractol *f)
{
			int32_t color;
            int i;
            i = 0;
            f->z.x = (scale(f->x, f->max_dim, -2, +2) * f->zoom) + f->off_x;
            f->z.y = (scale(f->y, f->max_dim, +2, -2) * f->zoom) + f->off_y;
            while (i < f->iter)
            {
                f->z = complex_add(complex_square(f->z), f->c);
                if ((f->z.x * f->z.x) + (f->z.y * f->z.y) > f->esc)
                    break;
                i++;
            }
			if (i == f->iter)
			{
				color = 0x000000FF;
				mlx_put_pixel(f->img, f->x, f->y, color);
			}
			else
				iter_check(i,f);
}
