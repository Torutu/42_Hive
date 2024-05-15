#ifndef FRACTOL_H
#define FRACTOL_H

#include "./inc/libft/libft.h"
#include "./inc/printf/ft_printf.h"
#include "./MLX42/include/MLX42/MLX42.h"

#define MAXITERATIONS 32
#define WIDTH 700
#define HEIGHT 500
#define ESCR 4

typedef struct s_complex
{
    double  x;
    double  y;
}              t_complex;

typedef struct s_fractol
{
    int         type;
    int         x;
    int         y;
    double      esc;
    t_complex   z;
    t_complex   c;
    mlx_t       *mlx;
    mlx_image_t *img;
    double      esc_value;
    double      off_x;
    double      off_y;
    double      zoom;
}              t_fractol;

void ene(t_fractol *f);
void init(t_fractol *f);

#endif