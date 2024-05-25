#include "fractol.h"

void type_check(t_fractol *f)
{
	if (f->type == 1)
		draw_mandel(f);
/*	else if (f->type == 2)
		f->c.x = av[2];
		f->c.y = av[3];
		draw_julia(f);*/
}

void draw_mandel(t_fractol *f)
{
    calculate_offsets(f);
    while (f->x < WIDTH)
    {
        while (f->y < HEIGHT)
        {
            int i;
            i = 0;
            f->z.x = 0.0;
            f->z.y = 0.0;
            f->c.x = (scale(f->x, f->max_dim, -2, +2) * f->zoom) + f->off_x;
            f->c.y = (scale(f->y, f->max_dim, +2, -2) * f->zoom) + f->off_y;
            while (i < MAXITERATIONS)
            {
                f->z = complex_add(complex_square(f->z), f->c);
                if ((f->z.x * f->z.x) + (f->z.y * f->z.y) >= f->esc)
                    break;
                i++;
            }
			iter_check(i,f);
            f->y++;
        }
    f->x++;
    //printf("f->x is:%d\n", f->x);
    f->y = 0;
    }
}


void draw_julia(t_fractol *f)
{
    calculate_offsets(f);
    while (f->x < WIDTH)
    {
        while (f->y < HEIGHT)
        {
            int i;
            i = 0;
            f->z.x = (scale(f->x, f->max_dim, -2, +2) * f->zoom) + f->off_x;
            f->z.y = (scale(f->y, f->max_dim, +2, -2) * f->zoom) + f->off_y;
            while (i < MAXITERATIONS)
            {
                f->z = complex_add(complex_square(f->z), f->c);
                if ((f->z.x * f->z.x) + (f->z.y * f->z.y) >= f->esc)
                    break;
                i++;
            }
			iter_check(i,f);
            f->y++;
        }
    f->x++;
    //printf("f->x is:%d\n", f->x);
    f->y = 0;
    }

}
