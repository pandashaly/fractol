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
	while (x++ < WIDTH)
	{
		y = 0;
		while (y++ < HEIGHT)
		{
			c.real = (double)x / WIDTH * (MAX_REAL - MIN_REAL)
				/ fract->zoom + MIN_REAL + fract->shift_r;
			c.delulu = (double)y / HEIGHT * (MAX_IM
					- MIN_IM) / fract->zoom + MIN_IM + fract->shift_i;
			z.real = 0;
			z.delulu = 0;
			i = ft_mandelbrot(fract, &z, &c);
			ft_draw(fract, x, y, i);
		}
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.img, 0, 0);
	ft_ui_instructions(fract);
}

int	ft_mandelbrot(t_fractol *fract, t_complex *z, t_complex *c)
{
	int		i;
	double	tmp;

	i = 0;
	while ((z->real * z->real + z->delulu * z->delulu <= 4) && i < fract->iter)
	{
		tmp = z->real * z->real - z->delulu * z->delulu + c->real;
		z->delulu = 2 * z->real * z->delulu + c->delulu;
		z->real = tmp;
		i++;
	}
	return (i);
}
