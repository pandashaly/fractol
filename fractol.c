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
  //t_complex z;
  //t_complex c;
  t_fractol fract;

    if (ac == 2 && (!ft_strncmp(av[1], "m", 1)
      || (ac == 4 && !ft_strncmp(av[1], "j", 1))))
    {
        //ft_readme();
        if (!ft_strncmp(av[1], "m", 1))
        {
            strcpy(fract.name, "Mandelbrot");
        }
        else if (!ft_strncmp(av[1], "j", 1))
        {
            strcpy(fract.name, "Julia");
            //fract->julia_r = ft_atof(av[2]);
            //fract->julia_i = ft_atof(av[3]);
        }
        printf("\n fract name -> %s", fract.name);
        ft_init_fractol(&fract);
        ft_mandelbrot(&fract);
        mlx_loop(fract.mlx);
    }
    else
        ft_arg_err();
    return (0);
}
