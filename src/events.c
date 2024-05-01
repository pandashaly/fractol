/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:48:48 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 14:52:05 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_mouse_hook(int button, int x, int y, t_fractol *fract)
{
	(void)x;
	(void)y;
	if (button == M_ZOOM_IN)
		fract->zoom += 1.1;
	else if (button == M_ZOOM_OUT)
		fract->zoom /= 1.1;
	return (0);
}

//int ft_keyhooks(int key, t_fractol, *fract)

int	ft_key_press(int key, t_fractol *fract)
{
	if (key == XK_space)
		ft_psychedellic(fract);
	else if (key >= XK_1 && key <= XK_3)
		ft_set_colorscheme(fract, key - XK_0);
	ft_init_fractol(fract);
	return (0);
}

/*int   ft_key_fun(int key, t_fractol *fract)
{
	if (key == XK_Left || keysym == XK_a)
		fract->shift_r += (0.1 * fract->zoom);
	else if (key == XK_Right || keysym == XK_d)
		fract->shift_r -= (0.1 * fract->zoom);
	else if (key == XK_Up || keysym == XK_w)
		fract->shift_i -= (0.1 * fract->zoom);
	else if (key == XK_Down || keysym == XK_s)
		fract->shift_i += (0.1 * fract->zoom);
	else if (key == XK_KP_Add)
		fract->iterations += 30;
	else if (key == XK_KP_Subtract)
		fract->iterations -= 30;
	else if (key == XK_space)
		ft_psychedellic(fract);
	ft_init_fractol(fract); 						
	return (0);
}*/

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
