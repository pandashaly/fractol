/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:40:24 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/19 13:50:18 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int main(int ac, char **av)
{
  t_fract *fractol;

  ft_args_check(&fract, ac, av);
  ft_init_fractol(&fract);
    create_window;
    create_image;
    events_init;
    data_init;
  ft_set_hooks(&fractol);
  ft_init_image();
  ft_render_fractol;
  mlx_loop(fract.mlx);
  ft_close_window(&fract);
}*/

int	main(int ac, char **av)
{
  t_fract fract;
  ft_args_checks(&fract, ac, av);
  ft_keyhooks(&fract);
  ft_init_image(&fract);
	mlx_loop(fract.mlx);
}
