/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:48:48 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/19 15:06:09 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int ft_mouse_hook(int button, intx, int y, t_fract *fract)
{
    (void)x;
    (void)y;
    if (button == M_ZOOM_IN)
        fract->zoom += 1.1;
    else if (button == M_ZOOM_OUT)
        fract->zoom /= 1.1;
    return (0);
}*/

int ft_esc_key(int key, t_fract *fract)
{
    if (key == XK_Escape)
        ft_close_window(fract);
    return (0);
}

void    ft_keyhooks(t_fract *fract)
{
    mlx_hook(fract->window, 17, 0, ft_close_window, fract);
    mlx_hook(fract->window, 3, 1L << 1, ft_esc_key, fract);
   // mlx_hook(fract->window, 09 1L <<  21 ft_mouse_hook, fract);
}

int   ft_close_window(t_fract *fract)
{
  mlx_destroy_image(fract->mlx, fract->img.img);
  mlx_destroy_window(fract->mlx, fract->window);
  free(fract->mlx);
  exit(EXIT_SUCCESS);
}
