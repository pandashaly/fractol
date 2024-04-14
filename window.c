/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:59:00 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/14 14:37:31 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdio.h>

/*void  *ft_pixel_put(t_fractol *fractol, int x, int y, int rgb)
{
  char *dst;

  if (x >= 0 && < WIDTH && y >= 0 && < HEIGHT)
  {
    dst = fractol->img_line + 
      (y * fractol->image.line_length + x * (fractol->img.bits_per_pixel / 8));
    *(unsigned int *)dst = rgb;
  }
}*/

void  ft_init_fractol(t_fractol *ractol, int ac, char **av)
{
  ft_args_check(fractol, ac, av);
{

void  ft_args_checks(t_fractol *fractol, int ac, char **av)
{
  if (ac < 2 || ac > 4)
    ft_err_msg();

void  ft_init_window(t_fractol *fractol)
{
  fractol->mlx_init_bruv = mlx_init();
  if (!fractol)
    exit(1);
  fractol->mlx_window = mlx_new window(fractol->mlx_init_bruv, 
      WIDTH, HEIGHT, "Fract-ol <3");
  if (!fractol->mlx_window)
    exit(1);
}

int	main(void)
{
  t_fractol fractol;
  ft_init_window(fractol);

	mlx_string_put(mlx_init_bruv, mlx_win, WIDTH * 0.5, HEIGHT * 0.5, 0xeda7ff, "Hello Donut! <3");
	mlx_loop(mlx_init_bruv);
}
