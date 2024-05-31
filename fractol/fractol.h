#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include "./inc/libft/libft.h"
#include "./inc/printf/ft_printf.h"
#include "./MLX42/include/MLX42/MLX42.h"

#define WIDTH 1280
#define HEIGHT 720
#define ESCR 4

#define FIRE1 0xFF1500FF
#define FIRE2 0xFF4000FF
#define FIRE3 0xFF8000FF
#define FIRE4 0xFFA500FF
#define FIRE5 0xFFBF00FF

#define WATER1 0x00122EFF
#define WATER2 0x062847FF
#define WATER3 0x0B3E5FFF
#define WATER4 0x115478FF
#define WATER5 0x176a90FF

#define EARTH1 0x351b04FF
#define EARTH2 0x4e341dFF
#define EARTH3 0x384e1dFF
#define EARTH4 0x1e3504FF
#define EARTH5 0x223b05FF

typedef struct s_color
{
	uint32_t  color_1;
	uint32_t  color_2;
	uint32_t  color_3;
	uint32_t  color_4;
	uint32_t  color_5;
	int		  color_count1;
	int		  color_count2;
	int		  color_count3;
	int       color_count4;
	int		  color_count5;
}			   t_color;

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
	t_color		fcolor;
    mlx_t       *mlx;
    mlx_image_t *img;
    double      esc_value;
    double      off_x;
    double      off_y;
    double      zoom;
	int			max_dim;
	int			iter;
	int			zoom_in_count;
	int			zoom_out_count;
	double			size;
}              t_fractol;

void ene(t_fractol *f);
void init(t_fractol *f);
//----------------------------maf_utils.c
t_complex	complex_add(t_complex, t_complex b);
t_complex	complex_square(t_complex a);
void	calculate_offsets(t_fractol *f);
double	scale(double unscaled, double old_max, double new_min, double new_max);
//----------------------------check_n_strings.c
void check_args(t_fractol *f, char **av, int ac);
void check_colors(char color,t_fractol *f);
//----------------------------draw.c
void drawhook(void *f);
void draw_fractal(t_fractol *f);
void type_check(t_fractol *f);
void draw_mandel(t_fractol *f);
void draw_julia(t_fractol *f);
void draw_barn(t_fractol *f);
//----------------------------colors.c
void iter_check(int iter, t_fractol *f);
//----------------------------rgba.c
int red(int rgba);
int green(int rgba);
int blue(int rgba);
int alpha(int rgba);
int rgba(int r, int g, int b, int a);
//----------------------------color_group.c
void color_pallet(int color_num,t_fractol *f);
//----------------------------hooks.c
void	scrollhook(double xdelta, double ydelta, void *f);
//----------------------------atof.c
double ft_atof(const char *str);

#endif
