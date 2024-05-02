/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:14:07 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 16:14:11 by ssottori         ###   ########.fr       */
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
    fract->shift_r += (mouse_x - 0.3) * SHIFT * fract->zoom;
    fract->shift_i -= (mouse_y - 0.3) * SHIFT * fract->zoom;
}

int	ft_key_press(int key, t_fractol *fract)
{
	if (key == XK_space)
		ft_psychedellic(fract);
	else if (key >= XK_0 && key <= XK_3)
		ft_set_colorscheme(fract, key - XK_0);
    else if (key == XK_m)
        ft_init_mandelbrot(fract);
    else if (key == XK_Right || key == XK_d)
		fract->shift_r += (0.1 * fract->zoom);
	else if (key == XK_Left || key == XK_a)
		fract->shift_r -= (0.1 * fract->zoom);
	else if (key == XK_Up || key == XK_w)
		fract->shift_i -= (0.1 * fract->zoom);
	else if (key == XK_Down || key == XK_s)
		fract->shift_i += (0.1 * fract->zoom);
	ft_init_fractol(fract); 						
	return (0);
}

int	ft_esc_key(int key, t_fractol *fract)
{
	if (key == XK_Escape)
		ft_close_window(fract);
	return (0);
}

void	ft_keyhooks(t_fractol *fract)
{
	mlx_hook(fract->window, 2, 1L << 0, ft_key_press, fract);
	mlx_hook(fract->window, 17, 0, ft_close_window, fract);
	mlx_mouse_hook(fract->window, ft_mouse_hook, fract);
	mlx_hook(fract->window, 3, 1L << 1, ft_esc_key, fract);
}
