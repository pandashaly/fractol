/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:45:03 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 18:45:06 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// =======LIBRARIES
# include "../libs/mlx/mlx.h"
# include <math.h>
# include "../libs/libft/inc/libft.h"
# include "../libs/libft/inc/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

// ========WINDOW SIZE
# define WIDTH 800
# define HEIGHT 600
# define M_ITER 1000

//# define WIDTH 1366
//# define HEIGHT 768
// ========COLORS
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define RED            0xFF0000
# define MAGENTA		0xFF00FF
# define LIME			0xCCFF00
# define ORANGE			0xFF6600
# define PURPLE			0x9932CC
# define CYAN			0x33CCCC
# define PINK			0xFF66B2
# define ELECTRIC		0x0066FF
# define LIGHTNING		0x00CCFF
# define LAVA			0xFF3300
# define YELLOW			0xFFFF00
# define PASTELYELLOW	0xFFFF99
# define PASTELPINK		0xFFB6C1
# define LILAC          0xEFB1FF

// =========JULIA
# define J1 -0.760
# define J11 -0.407
# define J2 -0.173
# define J22 -0.666
# define J3 -1.389
# define J33 0.000
# define J4 -0.178
# define J44 -0.650
# define J5 -0.215
# define J55 -0.602

// =========KEYS
# define KEY_ESC 53

// =========MOUSE
# define M_LEFT_CLICK 1
# define M_RIGHT_CLICK 2
# define M_MID_CLICK 3
# define M_ZOOM_IN 4
# define M_ZOOM_OUT 5

# define PI 3.141592653

// =========SIZES
# define MAX_REAL       1.5
# define MIN_REAL      -2.5
# define MAX_IM  1.5
# define MIN_IM -1.5
# define ZOOM 1.4
# define SHIFT 0.1
# define MIN_ZOOM 0.001
# define MAX_ZOOM 1000.0

// ==========STRUCTS

typedef struct s_palette
{
	int	cycle;
	int	colors[16];
}	t_palette;

typedef struct s_data
{
	double	m_iter;
}	t_data;

typedef struct s_img
{
	void	*img;
	char	*addy;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_rbg
{
	int	r;
	int	b;
	int	g;
}	t_rbg;

typedef struct t_complex
{
	double	real;
	double	delulu;
}	t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	char		name[15];
	t_img		img;
	double		julia_i;
	double		julia_r;
	double		fx;
	double		fy;
	t_complex	z;
	t_complex	c;
	int			color;
	int			colorscheme;
	bool		diff_colorscheme;
	double		zoom;
	double		shift_r;
	double		shift_i;
	int			iter;
}	t_fractol;

//t_rbg ultrafractal(float x);
//t_rbg hex_to_rgb(int hex);
void    ft_UI_instructions(t_fractol *fract);
void	ft_julia_zoom(t_fractol *fract, double mouse_x, double mouse_y);
//t_rbg	color_interpolate(t_rbg c1, t_rbg c2, t_rbg c3, t_rbg c4, float x);
void	zoom_in(t_fractol *fract, double mouse_x, double mouse_y);
void	zoom_out(t_fractol *fract, double mouse_x, double mouse_y);
void	ft_bullseye(t_fractol *fract, double mouse_x, double mouse_y);
//t_palette	*get_palettes(void);
t_rbg	color_map(float t, int colorscheme);
t_rbg	classic(float x);
t_rbg	alternate(float x);
void	ft_set_colorscheme(t_fractol *fract, int key);
void	ft_psychedellic(t_fractol *fract);
int		ft_key_press(int key, t_fractol *fract);
void	ft_init_burningship(t_fractol *fract);
int		ft_burningship(t_fractol *fract, t_complex *z, t_complex *c);
void	ft_4fract_args(t_fractol *fract, char *av1, char *av2, char *av3);
void	ft_2fract_args(t_fractol *fract, char *av1);

double	ft_atof(char *str);
void	ft_init_data(t_fractol *fract);
void	ft_malloc_err(void);
void	ft_init_mandelbrot(t_fractol *fract);
int		ft_mandelbrot(t_fractol *fract, t_complex *z, t_complex *c);
int		ft_julia(t_fractol *fract, t_complex *z, t_complex *c);
void	ft_draw(t_fractol *fract, int x, int y, int i);
void	ft_init_canvas(t_fractol *fract);
void	ft_init_fractol(t_fractol *fract);
int		blend_colours(int colour1, int colour2, double t);
void	ft_init_julia(t_fractol *fract, double julia_r, double julia_i);
void	ft_put_pixel(t_fractol *fract, int x, int y, int rgb);
void	ft_init_window(t_fractol *fract);
void	ft_arg_err(void);
void	ft_keyhooks(t_fractol *fract);
void	ft_init_image(t_fractol *fract);
void	ft_readme(void);
void	ft_render(t_fractol *fract);
int		ft_esc_key(int key, t_fractol *fract);
int		ft_close_window(t_fractol *fract);
int		ft_mouse_hook(int button, int x, int y, t_fractol *fract);

#endif
