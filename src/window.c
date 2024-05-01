/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:59:00 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 15:12:28 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
	//fract->m_iter = 200;
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
	printf("yay done");
}
