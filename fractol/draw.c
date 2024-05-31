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
					else if (f->type == 3)
					{
						draw_barn(f);
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
			/*printf("f->z.x =%lf\n",f->z.x);
			printf("f->z.y =%lf\n",f->z.y);
			printf("f->c.x =%lf\n",f->c.x);
			printf("f->c.y =%lf\n",f->c.y);
			printf("f->esc =%lf\n",f->esc);*/
			if (i == f->iter)
			{
				color = 0x000000FF;
				mlx_put_pixel(f->img, f->x, f->y, color);
			}
			else
				iter_check(i,f);
}
void draw_barn(t_fractol *f)
{
	f->z.x = 0.0;
	f->z.y = 0.0;
	int	i = 0;
	while (i < f->iter)
	{
		double r = rand() % (1 + 1 - 0) + 0;
		if (r < 0.01)
		{
			f->c.x = 0.0;
			f->c.y = 0.16 * f->z.y;
		}
		else if (r < 0.86)
		{
			f->c.x = 0.85 * f->z.x + 0.04 * f->z.y;
			f->c.y = -0.04 * f->z.x + 0.85 * f->z.y + 1.6;
		}
		else if (r < 0.93)
		{
			f->c.x = 0.2 * f->z.x - 0.26 * f->z.y;
			f->c.y = 0.23 * f->z.x + 0.22 * f->z.y + 1.6;
		}
		else
		{
			f->c.x = -0.15 * f->z.x + 0.28 * f->z.y;
			f->c.y = 0.26 * f->z.x + 0.24 * f->z.y + 0.44;
		}
		mlx_put_pixel(f->img, f->c.x, f->c.y, 0x000000FF);
		f->z.x = f->c.x;
		f->z.y = f->c.y;
		i++;
	}
}
