/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:48:48 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/21 16:17:36 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_mouse_hook(int button, int x, int y, t_fractol *fract)
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



int ft_esc_key(int key, t_fractol *fract)
{
    if (key == XK_Escape)
        ft_close_window(fract);
    return (0);
}

void    ft_keyhooks(t_fractol *fract)
{
    mlx_hook(fract->window, 17, 0, ft_close_window, fract);
    mlx_mouse_hook(fract->window, ft_mouse_hook, fract);
    mlx_hook(fract->window, 3, 1L << 1, ft_esc_key, fract);
}


