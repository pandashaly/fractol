/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:13:49 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 16:13:52 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_init_burningship(t_fractol *fract)
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
			i = ft_burningship(&z, &c);
			ft_draw(fract, x, y, i);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->img.img, 0, 0);
}

int	ft_burningship(t_complex *z, t_complex *c)
{
	int		i;
	double	tmp;

	i = 0;
	tmp = 0;
	while ((z->real * z->real + z->delulu * z->delulu <= 4) && i < M_ITER)
	{
		tmp = z->real * z->real - z->delulu * z->delulu + c->real;
		z->delulu = fabs(2 * z->real * z->delulu) + c->delulu;
		z->real = tmp;
		i++;
	}
	return (i);
}
