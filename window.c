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

void  ft_keyhooks(t_fractol *fractol)
{
  mlx_key_hook(fractol->mlx_window, ft_esc_key, fractol);
}

int   ft_esc_key(int key, t_fractol *fractol)
{
  if (key == KEY_ESC)
    ft_close_window(fractol);
  return (0);
}

int   ft_close_window(t_fractol *fractol)
{
  mlx_destroy_image(fractol->mlx_init_bruv, fractol->img);
  mlx_destroy_window(fractol->mlx_init_bruv, fractol->mlx_window);
  free(fractol->mlx_init_bruv);
  exit(EXIT_SUCCESS);
}

void  ft_arg_err(void)
{
  ft_putstr_fd("Invalid arguments.\nPlease enter:\n\t", 1);
  ft_putstr_fd("./fractol mandelbrot\nOR \n\t./fractol julia <value_1> <value_2>", 1); 
  exit(0);
}

void  ft_args_checks(t_fractol *fractol, int ac, char **av)
{
  if (ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10)
      || (ac == 4 && !ft_strncmp(av[1], "julia", 5))))
    ft_init_window(fractol);
  else
    ft_arg_err();
}

void  ft_init_window(t_fractol *fractol)
{
  fractol->mlx_init_bruv = mlx_init();
  fractol->mlx_window = mlx_new_window(fractol->mlx_init_bruv, 
      WIDTH, HEIGHT, "Fract-ol <3");
  ft_keyhooks(fractol);
}

int	main(int ac, char **av)
{
  t_fractol fractol;
  ft_args_checks(&fractol, ac, av);
  ft_keyhooks(&fractol);


  void *img;

  img = mlx_new_image(fractol.mlx_init_bruv, WIDTH, HEIGHT);
	mlx_string_put(fractol.mlx_init_bruv, fractol.mlx_window, WIDTH * 0.5,
      HEIGHT * 0.5, 0xeda7ff, "Hello Donut! <3");
	mlx_loop(fractol.mlx_init_bruv);
}
