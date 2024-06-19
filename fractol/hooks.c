#include "fractol.h"

void keyhook(mlx_key_data_t keydata, void *f)
{
	t_fractol *nf;

	nf = f;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
			ene(nf);
}

void	scrollhook(double xdelta, double ydelta, void *f)
{
	t_fractol *nf;

	nf = f;
	(void)xdelta;

	if (ydelta < 0 )
	{
		nf->zoom *= 0.95;
		if (nf->zoom_in_count == 15)
		{
			nf->iter++;
			nf->zoom_in_count = 0;
		}
		nf->zoom_in_count++;
		if (nf->zoom_out_count > 0)
			--nf->zoom_out_count;
	}
	else if (ydelta > 0 )
	{
		nf->zoom *= 1.05;
		if (nf->zoom_out_count == 15)
		{
			nf->iter--;
			nf->zoom_out_count = 0;
		}
		nf->zoom_out_count++;
		if (nf->zoom_in_count > 0)
			--nf->zoom_in_count;
	}
		draw_fractal(nf);
}

