/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*     init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:16:27 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 16:16:29 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_init_fractol(t_fractol *fract)
{
	if (ft_strcmp(fract->name, "Mandelbrot") == 0)
		ft_init_mandelbrot(fract);
	else if (ft_strcmp(fract->name, "Julia") == 0)
		ft_init_julia(fract, fract->julia_r, fract->julia_i);
	else if (ft_strcmp(fract->name, "Burning Ship") == 0)
		ft_init_burningship(fract);
	else
		ft_arg_err();
}

void	ft_init_image(t_fractol *fract)
{
	fract->img.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!fract->img.img)
	{
		mlx_destroy_window(fract->mlx, fract->window);
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		ft_malloc_err();
	}
	fract->img.addy = mlx_get_data_addr(fract->img.img,
			&fract->img.bpp,
			&fract->img.line_length,
			&fract->img.endian);
	mlx_put_image_to_window(fract->mlx,
		fract->window, fract->img.img, 0, 0);
}

void	ft_init_window(t_fractol *fract)
{
	fract->window = mlx_new_window(fract->mlx,
			WIDTH, HEIGHT,
			fract->name);
	if (!fract->window)
	{
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		ft_malloc_err();
	}
}

void	ft_init_data(t_fractol *fract)
{
	fract->zoom = 1;
	fract->shift_r = 0;
  fract->shift_i = 0;
  fract->iter = 200;
}

void	ft_init_canvas(t_fractol *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		ft_malloc_err();
	ft_init_window(fract);
	ft_init_image(fract);
	ft_init_data(fract);
	ft_keyhooks(fract);
	printf("Yay done!");
}
