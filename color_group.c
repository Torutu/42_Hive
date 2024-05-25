#include "fractol.h"

void	color_pallet(int color_num,t_fractol *f)
{
	if (color_num == 1)
	{
		f->fcolor.color_1 = FIRE1;
		f->fcolor.color_2 = FIRE2;
		f->fcolor.color_3 = FIRE3;
		f->fcolor.color_4 = FIRE4;
		f->fcolor.color_5 = FIRE5;
	}
	else if (color_num == 2)
	{
		f->fcolor.color_1 = WATER1;
		f->fcolor.color_2 = WATER2;
		f->fcolor.color_3 = WATER3;
		f->fcolor.color_4 = WATER4;
		f->fcolor.color_5 = WATER5;
	}
	else
	{
		f->fcolor.color_1 = EARTH1;
		f->fcolor.color_2 = EARTH2;
		f->fcolor.color_3 = EARTH3;
		f->fcolor.color_4 = EARTH4;
		f->fcolor.color_5 = EARTH5;
	}
}
