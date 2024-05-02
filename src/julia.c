/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:14:24 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 18:17:40 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_init_julia(t_fractol *fract, double julia_r, double julia_i)
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
			c.real = julia_r;
			c.delulu = julia_i;
			z.real = (double)x / WIDTH * (2.0 - -2.0) /fract->zoom + -2.0 + fract->shift_r;
			z.delulu = (double)y / HEIGHT * (2.0
					- -2.0) / fract->zoom + -2.0 + fract->shift_i;
			i = ft_julia(&z, &c);
			ft_draw(fract, x, y, i);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->img.img, 0, 0);
}

int	ft_julia(t_complex *z, t_complex *c)
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
