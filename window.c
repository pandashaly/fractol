/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:59:00 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/19 14:07:27 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_init_image(t_fract *fract)
{
    fract->img.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
    fract->img.addy = mlx_get_data_addr(fract->img.img, &fract->img.bpp, &fract->img.line_length, &fract->img.endian);
    color_map(fract, WIDTH, HEIGHT);
    mlx_put_image_to_window(fract->mlx, fract->window, fract->img.img, 0, 0);
}

void  ft_init_window(t_fract *fract)
{
  fract->mlx = mlx_init();
  fract->window = mlx_new_window(fract->mlx, 
      WIDTH, HEIGHT, "Fractol <3");
  ft_keyhooks(fract);
}

