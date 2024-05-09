/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:16:08 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 16:16:11 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_put_pixel(t_fractol *fract, int x, int y, int rbg)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = fract->img.addy + (y * fract->img.line_length
				+ x * (fract->img.bpp / 8));
		*(unsigned int *)dst = rbg;
	}
}

void	ft_draw(t_fractol *fract, int x, int y, int i)
{
	int		rbg;
	double	t;
	t_rbg	color;

	rbg = 0;
	if (fract->diff_colorscheme)
	{
		if (i == fract->iter)
		{
			rbg = blend_colours(BLACK, fract->color, (double)i / fract->iter);
			ft_put_pixel(fract, x, y, rbg);
		}
		else
		{
			t = (double)i / fract->iter;
			color = color_map(t, fract->colorscheme);
			rbg = (color.r << 16) | (color.g << 8) | color.b;
			ft_put_pixel(fract, x, y, rbg);
		}
	}
	else
	{
		if (i == fract->iter)
			rbg = BLACK;
		else
			rbg = blend_colours(BLACK, fract->color, (double)i / fract->iter);
		ft_put_pixel(fract, x, y, rbg);
	}
}
