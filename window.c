/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:59:00 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/16 18:25:21 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdio.h>
#include <math.h>

void	ft_put_pixel(t_fract *fract, int x, int y, int rbg)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = fract->img.addy + (y * fract->img.line_length
				+ x * (fract->img.bpp / 8));
		*(unsigned int *)dst = rbg;
	}
}

void    draw_circle(t_fract *fract, int centre_x, int centre_y, int radius)
{
    double angle = 0;
    double angle_step =  3.141592653 / 720;
    int x;
    int y;

    while (angle <= 2 * 3.141592653)
    {
        x = centre_x + radius * cos(angle);
        y = centre_y + radius * sin(angle);
        ft_put_pixel(fract, x, y, 0x000000);
        angle += angle_step;
    }
}

void    ft_init_image(t_fract *fract)
{
    fract->img.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
    fract->img.addy = mlx_get_data_addr(fract->img.img, &fract->img.bpp, &fract->img.line_length, &fract->img.endian);
    color_map(fract, WIDTH, HEIGHT);
    ft_put_pixel(fract, 960, 540, 0xFF0000);
    draw_circle(fract, 960, 540, 300);
    draw_circle(fract, 960, 540, 302);
    draw_circle(fract, 960, 540, 301);
    draw_circle(fract, 960, 540, 303);
    mlx_put_image_to_window(fract->mlx, fract->window, fract->img.img, 0, 0);
   }

int	color_map(t_fract *fract, int w, int h)
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
}


int   ft_keyboard(int keysym, t_fract *fract)
{
  if (keysym == XK_Escape)
    ft_close_window(fract);
  return (0);
}

void  ft_keyhooks(t_fract *fract)
{
  mlx_hook(fract->window, 17, 0, ft_close_window, fract);
  mlx_hook(fract->window, 3, 1L << 1, ft_keyboard, fract);
}

int   ft_close_window(t_fract *fract)
{
  mlx_destroy_image(fract->mlx, fract->img.img);
  mlx_destroy_window(fract->mlx, fract->window);
  free(fract->mlx);
  exit(EXIT_SUCCESS);
}

void  ft_arg_err(void)
{
  ft_putstr_fd("Invalid arguments.\nPlease enter:\n\t", 1);
  ft_putstr_fd("./fractol mandelbrot\nOR \n\t./fractol julia <value_1> <value_2>", 1); 
  exit(0);
}

void  ft_args_checks(t_fract *fract, int ac, char **av)
{
  if (ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10)
      || (ac == 4 && !ft_strncmp(av[1], "julia", 5))))
    ft_init_window(fract);
  else
    ft_arg_err();
}

void  ft_init_window(t_fract *fract)
{
  fract->mlx = mlx_init();
  fract->window = mlx_new_window(fract->mlx, 
      WIDTH, HEIGHT, "Fract-ol <3");
  ft_keyhooks(fract);
}

int	main(int ac, char **av)
{
  t_fract fract;
  ft_args_checks(&fract, ac, av);
  ft_keyhooks(&fract);
  ft_init_image(&fract); 
    //mlx_string_put(fract.mlx, fract.window, WIDTH * 0.5,
      //HEIGHT * 0.5, LILAC, "Hello Donut! <3");
	mlx_loop(fract.mlx);
}
