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

int	main(int ac, char **av)
{
  t_fractol fract;

    if ((ac == 2 && (!ft_strncmp(av[1], "m", 1))) || (ac == 4 && !ft_strncmp(av[1], "j", 1)))
    {
        //ft_readme();
        if (!ft_strncmp(av[1], "m", 1))
            strcpy(fract.name, "Mandelbrot");
        else if (!ft_strncmp(av[1], "j", 1))
        {
            strcpy(fract.name, "Julia");
            fract.julia_r = ft_atof(av[2]);
            fract.julia_i = ft_atof(av[3]);
        }
        ft_init_canvas(&fract);
        ft_init_fractol(&fract);
        mlx_loop(fract.mlx);
    }
    else
        ft_arg_err();
    return (0);
}
