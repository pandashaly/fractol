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

void  ft_keyhooks(t_fract *fract)
{
  mlx_key_hook(fract->window, ft_esc_key, fract);
}

int   ft_esc_key(int key, t_fract *fract)
{
  if (key == KEY_ESC)
    ft_close_window(fract);
  return (0);
}

int   ft_close_window(t_fract *fract)
{
  mlx_destroy_image(fract->mlx, fract->img);
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


  void *img;

  img = mlx_new_image(fract.mlx, WIDTH, HEIGHT);
	mlx_string_put(fract.mlx, fract.window, WIDTH * 0.5,
      HEIGHT * 0.5, RED, "Hello Donut! <3");
	mlx_loop(fract.mlx);
}
