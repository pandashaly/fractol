/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:15:54 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 16:15:57 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_init_mandelbrot(t_fractol *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			x;
	int			y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c.real = (double)x / WIDTH * (MAX_REAL - MIN_REAL) + MIN_REAL;
			c.delulu = (double)y / HEIGHT * (MAX_IMAGINARY
					- MIN_IMAGINARY) + MIN_IMAGINARY;
			z.real = 0;
			z.delulu = 0;
			i = ft_mandelbrot(&z, &c);
			ft_draw(fract, x, y, i);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->img.img, 0, 0);
}

int	ft_mandelbrot(t_complex *z, t_complex *c)
{
	int		i;
	double	tmp;

	i = 0;
	while ((z->real * z->real + z->delulu * z->delulu <= 4) && i < M_ITER)
	{
		tmp = z->real * z->real - z->delulu * z->delulu + c->real;
		z->delulu = 2 * z->real * z->delulu + c->delulu;
		z->real = tmp;
		i++;
	}
	return (i);
}

void	ft_draw(t_fractol *fract, int x, int y, int i)
{
	int		rbg;
	double	t;
	t_rbg	color;

	rbg = 0;
	if (fract->diff_colorscheme)
	{
		t = (double)i / M_ITER;
		color = color_map(t, fract->colorscheme);
		rbg = (color.r << 16) | (color.g << 8) | color.b;
		ft_put_pixel(fract, x, y, rbg);
	}
	else
	{
		if (i == M_ITER)
			rbg = BLACK;
		else
			rbg = blend_colours(BLACK, fract->color, (double)i / M_ITER);
		ft_put_pixel(fract, x, y, rbg);
	}
}

int	blend_colours(int colour1, int colour2, double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - t) * ((colour1 >> 16) & 0xFF) + t * \
		((colour2 >> 16) & 0xFF) * 5);
	g = (int)((1 - t) * ((colour1 >> 8) & 0xFF) + t * \
		((colour2 >> 8) & 0xFF) * 5);
	b = (int)((1 - t) * (colour1 & 0xFF) + t * \
		(colour2 & 0xFF) * 5);
	r = (int)(r + (255 - r) * t * 1.5);
	g = (int)(g + (255 - g) * t * 0.2);
	b = (int)(b + (255 - b) * t * 4);
	return ((r << 16) | (g << 8) | b);
}

/*int color_map(int i) {
	double t = (double)i / M_ITER;

	// Linear interpolation between black (0) and white (1)
	int red = (int)(255 * t);
	int green = (int)(255 * t);
	int blue = (int)(255 * t);

	// Combine rbg components into a single color value
	return (red << 16) | (green << 8) | blue;
}*/

void	ft_psychedellic(t_fractol *fract)
{
	static int	color_arr[] = {BLACK, RED, GREEN, YELLOW, BLUE,
		WHITE, LIGHTNING, LIME, LILAC, PINK, LAVA, CYAN, ORANGE};
	static int	color_code = 0;

	color_code = (color_code + 1) % (sizeof(color_arr) / sizeof(color_arr[0]));
	fract->color = color_arr[color_code];
	ft_init_fractol(fract);
}

t_rbg	color_map(float t, int colorscheme)
{
	if (colorscheme == 1)
		return (classic(t));
	else if (colorscheme == 2)
		return (alternate(t));
	return ((t_rbg){255, 0, 0});
}
