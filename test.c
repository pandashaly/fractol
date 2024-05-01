/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:31:34 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 14:42:14 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../inc/fractol.h"

void  ft_init_test(t_fractol *fract)
{
    ft_init_window(fract);
    fract->img.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
    fract->img.addy = mlx_get_data_addr(fract->img.img,
        &fract->img.bpp, &fract->img.line_length, &fract->img.endian);
    ft_run_test(fract);
    mlx_put_image_to_window(fract->mlx, fract->window, fract->img.img, 0, 0);
    ft_keyhooks(fract);
}

void  ft_run_test(t_fractol *fract)
{
    int n = 300;

    color_map(fract, WIDTH, HEIGHT);
    while (n < 306)
    {
        printf("%d", n);
        draw_circle(fract, 960, 540, n);
        n++;
    }
}

void    draw_circle(t_fractol *fract, int centre_x, int centre_y, int radius)
{
    double angle = 0;
    double angle_step =  PI / (360);
    int x;
    int y;

    while (angle <= 2 * PI)
    {
        x = centre_x + (int)(radius * cos(angle) + 0.5);
        y = centre_y + (int)(radius * sin(angle) + 0.5);
        int i = -1;
        while(i <= 1)
        {
            int j = -1;
            while (j <= 1)
            {
                int pixel_x = (int)(x + i + 0.5);
                int pixel_y = (int)(y + j + 0.5);
                ft_put_pixel(fract, pixel_x, pixel_y, 0x000000);
                j++;
            }
            i++;
        }
        angle += angle_step;
    }
}

/*int	color_map(t_fractol *fract, int w, int h)
{
    int	x;
    int	y;
    int	color;

    x = w;
    while (x--)
    {
        y = h;
        while (y--)
        {
            color = (x * 255) / w + ((((w - x) * 255) / w) << 16) + (((y * 255) / h) << 8);
            ft_put_pixel(fract, x, y, color);
        }
    }
    return (0);
}*/

