/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:20:04 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 15:10:26 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_arg_err(void)
{
	ft_putstr_fd("Invalid arguments.\nPlease enter:\n\t", 1);
	ft_putstr_fd("./fractol m\nOR \n\t./fractol j <value_1> <value_2>", 1);
	ft_putstr_fd("<.fractol j -0.2 +0.5>    or    ", 1);
	ft_putstr_fd("./fractol j -0.685 -0.3121>\n", 1);
	exit(EXIT_FAILURE);
}

/*void  ft_args_checks(char *name, int ac, char **av)
{
	if (ac == 2 && (!ft_strncmp(av[1], "m", 1)
		|| (ac == 4 && !ft_strncmp(av[1], "j", 1))))
	{
		ft_readme();
		if (!ft_strncmp(av[1], "m", 1))
			ft_strcpy(fract->name, "Mandelbrot");
		else if (!ft_strncmp(av[1], "j", 1))
			ft_strcpy(fract->name, "Julia");
	}
	else
		ft_arg_err();
}*/
