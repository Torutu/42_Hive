#include "fractol.h"

int red(int rgba)
{
	return((rgba >> 24) & 0xFF);
}

int green(int rgba)
{
	return((rgba >> 16) & 0xFF);
}

int blue(int rgba)
{
	return((rgba >> 8) & 0xFF);
}

int alpha(int rgba)
{
	return (rgba & 0xFF);
}

int rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
