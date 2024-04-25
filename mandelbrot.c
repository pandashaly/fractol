/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:19:48 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/23 00:19:50 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*void    ft_mandelbrot(t_fractol *fract, t_complex *z, t_complex *c)
{
    int color = 0;
   
    double tmp;

    int x = 0;
    while (x < WIDTH)
    {
        int y = 0;
        while (y < HEIGHT)
        {
            z->real = 0;
            z->delulu = 0;

            int i = 0;
            while ((z->real * z->real + z->delulu * z->delulu <= 3) && i < M_ITER)
            {
                tmp = (z->real * z->real) - (z->delulu * z->delulu) + c->real;
                z->delulu = ((double)2 * z->real * z->delulu) + c->delulu;
                z->real = tmp;
                i++;
            }
            if (i == M_ITER)
                color = BLACK;
            else
                color = WHITE;
            ft_put_pixel(fract, x, y, color);
            y++;
        }
        x++;
    }
}*/ 

void ft_mandelbrot(t_fractol *fract)
{
    int color = 0;
    t_complex z;
    t_complex c;

    int x = 0;
    while (x < WIDTH)
    {
        int y = 0;
        while (y < HEIGHT)
        {
            // Initialize z and c for the current point (x, y)
            c.real = (double)x / WIDTH * (MAX_REAL - MIN_REAL) + MIN_REAL;
            c.delulu = (double)y / HEIGHT * (MAX_IMAGINARY - MIN_IMAGINARY) + MIN_IMAGINARY;
            
            z.real = 0;
            z.delulu = 0;

            int i = 0;
            while ((z.real * z.real + z.delulu * z.delulu <= 4) && i < M_ITER)
            {
                // Update z using the Mandelbrot formula
                double tmp = z.real * z.real - z.delulu * z.delulu + c.real;
                z.delulu = 2 * z.real * z.delulu + c.delulu;
                z.real = tmp;
                i++;
            }
            //printf("Current point (x, y): (%d, %d)\n", x, y);
            //printf("c: real = %f, imaginary = %f\n", c.real, c.delulu);
            //printf("z: real = %f, imaginary = %f\n", z.real, z.delulu);

            if (i == M_ITER)
                color = WHITE;
            else
                color = i;
            //printf("Color assigned to pixel (%d, %d): %#x\n", x, y, color);
            ft_put_pixel(fract, x, y, color);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fract->mlx, fract->window, fract->img.img, 0, 0);
}

