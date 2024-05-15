/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:41:38 by walnaimi          #+#    #+#             */
/*   Updated: 2024/05/15 19:06:17 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <string.h>
#include <stdio.h>

void	ene(t_fractol *f)
{
	mlx_close_window(f->mlx);
	mlx_delete_image(f->mlx, f->img);
	mlx_terminate(f->mlx);
	exit(1);
}
void init(t_fractol *f)
{
    f->esc = 4;
    f->z.x = 0;
    f->z.y = 0;
    f->c.x = 0;
    f->c.y = 0;
    f->x = 0;
    f->y = 0;
    f->esc_value = 4;
    f->zoom = 1;
    //mlx_set_setting(MLX_MAXIMIZED, true); 
    f->mlx = mlx_init(WIDTH, HEIGHT, "hi", true);
    if (!(f->mlx))    
        ene(f);
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    if (!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
        ene(f);
    /*printf("f->z.x = %lf\nf->z.y = %lf\n",f->z.x,f->z.y);
    printf("f->c.x = %lf\nf->c.y = %lf\n",f->c.x,f->c.y);
    printf("f->x = %d\nf->y = %d\n",f->x,f->y);
    printf("esc_value = %lf\n",f->esc_value);
    printf("type = (%d)\n1 = Mandel\n2 = Julia\n",f->type);*/
}

int check_args(t_fractol *f, char **av,int ac)
{
    if (strncmp(av[1], "mandel", 7) == 0 && ac == 2)
    {
        f->type = 1;
        printf("it is Mandel and the type is %d\n", f->type);
    }
    else if(strncmp(av[1], "julia", 6) == 0 && ac == 2)
    {
        f->type = 2;
        printf("it is Julia and the type is %d\n", f->type);
    }
    else
    {
        printf("[checl_args]:./fractol <mandel> or <julia>\n");
        exit(0);
    }
    return 0;
}
t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex	complex_square(t_complex a)
{
	t_complex	c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}
void	calculate_offsets(t_fractol *f)
{
	double	range;

	range = 4.0;
	if (WIDTH > HEIGHT)
        {
		    f->off_y = ((double)HEIGHT / (double)WIDTH - 1.0) * range / 2;
            printf("width,f->off_y =%lf\n",f->off_y);
        }
	else if (HEIGHT > WIDTH)
		f->off_x = ((double)WIDTH / (double)HEIGHT - 1.0) * range / -2;
}
double	scale(double unscaled, double old_max, double new_min, double new_max)
{
	double	old_min;

	old_min = 0.0;
	return ((new_max - new_min) * (unscaled - old_min) / (old_max - old_min)
		+ new_min);
}
void draw(t_fractol *f)
{
    calculate_offsets(f);
    uint32_t color = 0;
    double is_it_escape = 0.0;
    while (f->x < WIDTH)
    {
        while (f->y < HEIGHT)
        {
            int i;
            i = 0;
            f->z.x = 0.0;
            f->z.y = 0.0;
            f->c.x = (scale(f->x, WIDTH, -2, +2) * f->zoom) + f->off_x;
            f->c.y = (scale(f->y, HEIGHT, +2, -2) * f->zoom) + f->off_y;
            //******************test*********************
            printf("f->x:%d\nf->y:%d\nshift_y:%lf\n",f->x,f->y,f->off_y);
            double yscale = scale(f->y, HEIGHT, +2, -2);
            double xscale = scale(f->x, WIDTH, -2, +2);
            printf("yscale:%lf\n",yscale);
            printf("xscale:%lf\n",xscale);
            printf("f->zoom:%lf\n",f->zoom);
            //*******************************************
             while (i < MAXITERATIONS)
             {
                f->z = complex_add(complex_square(f->z), f->c);
                is_it_escape = (f->z.x * f->z.x) + (f->z.y * f->z.y);
                //printf("f.z.x = %lf\nf.z.y = %lf\nis is this escape?:%lf\n",f->z.x,f->z.y,is_it_escape);
                if ((f->z.x * f->z.x) + (f->z.y * f->z.y) >= f->esc)
                    break;
                i++;
            }
                
                if (i == MAXITERATIONS)
                    color = 0x000000FF;
                else
                    color = 0xFF0000FF;
                mlx_put_pixel(f->img, f->x, f->y, color);
                f->y++;
                //printf("f->y is:%d\n",f->y);
        }
    f->x++;
    //printf("f->x is:%d\n", f->x);
    f->y = 0;
    }

}

int main(int ac, char **av)
{
    t_fractol f;

        check_args(&f,av,ac);
        init(&f);
        draw(&f);
        mlx_loop(f.mlx);
	    mlx_terminate(f.mlx);
        return (EXIT_SUCCESS);
}