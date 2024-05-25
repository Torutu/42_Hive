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
        type_check(&f);
        mlx_loop(f.mlx);
	    mlx_terminate(f.mlx);
        return (EXIT_SUCCESS);
}
