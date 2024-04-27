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
            c.real = (double)x / WIDTH * (MAX_REAL - MIN_REAL) + MIN_REAL;
            c.delulu = (double)y / HEIGHT * (MAX_IMAGINARY - MIN_IMAGINARY) + MIN_IMAGINARY;
            
            z.real = 0;
            z.delulu = 0;

            int i = 0;
            while ((z.real * z.real + z.delulu * z.delulu <= 4) && i < M_ITER)
            {
                double tmp = z.real * z.real - z.delulu * z.delulu + c.real;
                z.delulu = 2 * z.real * z.delulu + c.delulu;
                z.real = tmp;
                i++;
            }
            //printf("Current point (x, y): (%d, %d)\n", x, y);
            //printf("c: real = %f, imaginary = %f\n", c.real, c.delulu);
            //printf("z: real = %f, imaginary = %f\n", z.real, z.delulu);

            if (i == M_ITER)
                color = BLACK;
            else
                color = blend_colours(BLACK, LIME, (double)i / M_ITER);
            //printf("Color assigned to pixel (%d, %d): %#x\n", x, y, color);
            ft_put_pixel(fract, x, y, color);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fract->mlx, fract->window, fract->img.img, 0, 0);
}

int	blend_colours(int colour1, int colour2, double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - t) * ((colour1 >> 16) & 0xFF) + t * \
		((colour2 >> 16) & 0xFF) * 5);
	g = (int)((1 - t) * ((colour1 >> 8) & 0xFF) + t * \
		((colour2 >> 8) & 0xFF) * 5);
	b = (int)((1 - t) * (colour1 & 0xFF) + t * \
		(colour2 & 0xFF) * 5);
	r = (int)(r + (255 - r) * t * 1.5);
	g = (int)(g + (255 - g) * t * 0.2);
	b = (int)(b + (255 - b) * t * 4);
	return ((r << 16) | (g << 8) | b);
}

int color_map(int i) {
    double t = (double)i / M_ITER;

    // Linear interpolation between black (0) and white (1)
    int red = (int)(255 * t);
    int green = (int)(255 * t);
    int blue = (int)(255 * t);

    // Combine RGB components into a single color value
    return (red << 16) | (green << 8) | blue;
}
