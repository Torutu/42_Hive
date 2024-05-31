#include "fractol.h"

int main(int ac, char **av)
{
    t_fractol f;
	if(ac == 1)
	{
		ft_printf("./fractol mandel\n./fractol Julia x y\n");
		exit(0);
	}
        check_args(&f,av,ac);
        init(&f);
        draw_fractal(&f);
		mlx_scroll_hook(f.mlx, &scrollhook, &f);
		mlx_loop_hook(f.mlx, &drawhook, &f);
        mlx_loop(f.mlx);
	    mlx_terminate(f.mlx);
        return (EXIT_SUCCESS);
}
