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

	mouse_x = (x - (WIDTH / 2)) / ((0.5 * WIDTH) * fract->zoom);
	mouse_y = (y - (HEIGHT / 2)) / ((0.5 * HEIGHT) * fract->zoom);
	if (button == M_ZOOM_IN)
    {
		fract->zoom += ZOOM;
        ft_bullseye(fract, mouse_x, mouse_y);
        ft_init_fractol(fract);
    }
	else if (button == M_ZOOM_OUT)
    {
		fract->zoom -= ZOOM;
        ft_bullseye(fract, mouse_x, mouse_y);
        ft_init_fractol(fract);
    }
	return (0);
}

void ft_bullseye(t_fractol *fract, double mouse_x, double mouse_y)
{
    fract->shift_r = (mouse_x * (MAX_REAL - MIN_REAL)) * fract->zoom;
    fract->shift_i = (mouse_y * (MAX_IMAGINARY - MIN_IMAGINARY)) * fract->zoom;
    printf("\nmouse %f, %f\n", mouse_x, mouse_y);
    printf("center %d, %d\n", WIDTH / 2, HEIGHT / 2);
    printf("shift r_i %f, %f\n", fract->shift_r, fract->shift_i);
}

void	zoom_in(t_fractol *fract, double mouse_x, double mouse_y)
{
	double	zoom_factor;

	zoom_factor = 0.95;

  //changing the oom factor to keep cursur in same place
	fract->shift_r += (mouse_x - fract->shift_r) * (1 - zoom_factor);
	fract->shift_i += (mouse_y - fract->shift_i) * (1 - zoom_factor);
	fract->zoom *= zoom_factor;
}

void	zoom_out(t_fractol *fract, double mouse_x, double mouse_y)
{
	double	zoom_factor;

	zoom_factor = 1.01;

	fract->shift_r += (mouse_x - fract->shift_r) * (1 - zoom_factor);
	fract->shift_i += (mouse_y - fract->shift_i) * (1 - zoom_factor);
	fract->zoom *= zoom_factor;
}
