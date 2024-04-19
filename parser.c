/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:20:04 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/19 13:56:33 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void  ft_arg_err(void)
{
  ft_putstr_fd("Invalid arguments.\nPlease enter:\n\t", 1);
  ft_putstr_fd("./fractol m\nOR \n\t./fractol j <value_1> <value_2>", 1); 
  exit(0);
}

void  ft_args_checks(t_fract *fract, int ac, char **av)
{
  if (ac == 2 && (!ft_strncmp(av[1], "m", 1)
      || (ac == 4 && !ft_strncmp(av[1], "j", 1))))
    ft_init_window(fract);
  else if (ac == 2 && (!ft_strncmp(av[1], "test", 4)))
      ft_init_test(fract);
  else
    ft_arg_err();
}
