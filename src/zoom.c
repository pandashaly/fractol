/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:30:41 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 21:30:47 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_mouse_hook(int button, int x, int y, t_fractol *fract)
{
    double  mouse_x;
    double  mouse_y;

	mouse_x = (double)x / WIDTH;
	mouse_y = (double)y / HEIGHT;
	if (button == M_ZOOM_IN)
    {
		fract->zoom *= ZOOM;
        ft_bullseye(fract, mouse_x, mouse_y);
    }
	else if (button == M_ZOOM_OUT)
    {
		fract->zoom /= ZOOM;
        ft_bullseye(fract, mouse_x, mouse_y);
    }
    ft_init_fractol(fract);
	return (0);
}

void ft_bullseye(t_fractol *fract, double mouse_x, double mouse_y)
{
    if (ft_strcmp(fract->name, "Julia") == 0)
        ft_julia_zoom(fract, mouse_x, mouse_y);
    else
    {
        fract->shift_r = (mouse_x  - 0.5)
            * ((MAX_REAL - MIN_REAL) / fract->zoom) + fract->shift_r;
        fract->shift_i = (mouse_y - 0.5)
            * ((MAX_IMAGINARY - MIN_IMAGINARY) / fract->zoom) + fract->shift_i;
    }
}

void    ft_julia_zoom(t_fractol *fract, double mouse_x, double mouse_y)
{
    fract->shift_r = (mouse_x  - 0.5)
        * ((2.0 - -2.0) / fract->zoom) + fract->shift_r;
    fract->shift_i = (mouse_y - 0.5)
    * ((2.0 - -2.0) / fract->zoom) + fract->shift_i;
}
