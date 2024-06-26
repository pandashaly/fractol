/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorschemes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:43:05 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 16:43:29 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_set_colorscheme(t_fractol *fract, int key)
{
	if (key >= 1 && key <= 3)
	{
		fract->colorscheme = key;
		fract->diff_colorscheme = true;
	}
	else if (key == 0)
		fract->diff_colorscheme = false;
}

t_rbg	classic(float x)
{
	t_rbg	color;

	x *= PI * 2.0;
	color.r = (int)(0.5 + sin(x) * 255);
	color.g = (int)(0.5 + sin(x + 1.0) * 127.5);
	color.b = (int)(0.5 + sin(x + 2.0) * 127.5);
	return (color);
}

t_rbg	alternate(float x)
{
	t_rbg	color;

	x *= PI * 2.0;
	color.r = (int)(0.5 + sin(x + 1.0) * 127.5);
	color.g = (int)(0.5 + sin(x + 2.0) * 127.5);
	color.b = (int)(0.5 + sin(x) * 127.5);
	return (color);
}
