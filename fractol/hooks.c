#include "fractol.h"
#include <stdio.h>

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
		nf->zoom_out_count = 0;
		printf("down\n %lf\n",nf->zoom);
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
		nf->zoom_in_count = 0;
		printf("up\n %lf\n",nf->zoom);
	}
	if (nf->type == 1)
		draw_fractal(nf);
}

