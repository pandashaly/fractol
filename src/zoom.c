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
        printf("button zoomout > %d\n", button);
		fract->zoom /= ZOOM;
        ft_bullseye(fract, mouse_x, mouse_y);
    }
    ft_init_fractol(fract);
    printf("zooooom -> %f\n", fract->zoom);
	return (0);
}

void ft_bullseye(t_fractol *fract, double mouse_x, double mouse_y)
{
    fract->shift_r = (mouse_x  - 0.5) * ((MAX_REAL - MIN_REAL) / fract->zoom) + fract->shift_r;
    fract->shift_i = (mouse_y - 0.5) * ((MAX_IMAGINARY - MIN_IMAGINARY) / fract->zoom) + fract->shift_i;
    printf("\nmouse %f, %f\n", mouse_x, mouse_y);
    printf("center %d, %d\n", WIDTH / 2, HEIGHT / 2);
    printf("shift r_i %f, %f\n", fract->shift_r, fract->shift_i);
}
