/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:40:24 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/22 19:17:45 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int main(int ac, char **av)
{
  t_fract *fractol;

  ft_args_check(&fract, ac, av);
  ft_init_fractol(&fract);
    create_window; [x]
    create_image; [x]
    events_init; [x] make mouse hooks
    data_init;
  ft_set_hooks(&fractol);
  ft_init_image();
  ft HOW TO FORMULAAA????????
  ft_render_fractol;
  mlx_loop(fract.mlx);
  ft_close_window(&fract);
}*/

int	main(int ac, char **av)
{
  t_fractol fract;

    ft_args_checks(&(fract.name), ac, av);
    if (!ft_strncmp(fract.name, "Mandelbrot", 5))
          ft_init_fractol(&fract);
    else if (!ft_strncmp(fract.name, "Julia", 5))
    {
        fract->julia_r = ft_atof(av[2]);
        fract->julia_i = ft_atof(av[3]);
        ft_init_fractol(&fract);
    }
    //ft_render(&fract);
	mlx_loop(fract.mlx);
    return (0);
}
