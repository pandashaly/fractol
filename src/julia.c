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
			z.real = (double)x / WIDTH * (2.0 - -2.0)
				/ fract->zoom + -2.0 + fract->shift_r;
			z.delulu = (double)y / HEIGHT * (2.0
					- -2.0) / fract->zoom + -2.0 + fract->shift_i;
			i = ft_julia(fract, &z, &c);
			ft_draw(fract, x, y, i);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.img, 0, 0);
    ft_UI_instructions(fract);

}

int	ft_julia(t_fractol *fract, t_complex *z, t_complex *c)
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

//void    ft_julia_cycle(t_fractol *fract)
//{
void	ft_UI_instructions(t_fractol *fract)
{
	mlx_string_put(fract->mlx, fract->win, 23, 23, LILAC, "Controls Keys");
	mlx_string_put(fract->mlx, fract->win, 23, 53, LILAC, "Move = ^ v < > OR w a s d");
	mlx_string_put(fract->mlx, fract->win, 23, 73, LILAC, "Up Iters = +");
	mlx_string_put(fract->mlx, fract->win, 23, 93, LILAC, "Down Iters = -");
	mlx_string_put(fract->mlx, fract->win, 23, 113, LILAC, "Color = SPACE");
    mlx_string_put(fract->mlx, fract->win, 23, 133, LILAC, "Colorscheme = 1 2 3");
	mlx_string_put(fract->mlx, fract->win, 23, 153, LILAC, "Reset color = 0");
	mlx_string_put(fract->mlx, fract->win, 23, 173, LILAC, "Zoom = SCROLL");
	//mlx_string_put(fract->mlx, fract->win, 23, (HEIGHT - 123), LILAC, "Fract Explorer");
	//mlx_string_put(fract->mlx, fract->win, 23, (HEIGHT - 95), LILAC, "j = Julia");
	//mlx_string_put(fract->mlx, fract->win, 23, (HEIGHT - 75), LILAC, "m = Mandelbrot");
	//mlx_string_put(fract->mlx, fract->win, 23, (HEIGHT - 55), LILAC, "b = Burning Ship");
}
