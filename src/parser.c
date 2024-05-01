/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:14:37 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 16:14:40 by ssottori         ###   ########.fr       */
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

void	ft_4fract_args(t_fractol *fract, char *av1, char *av2, char *av3)
{
	if (!ft_strncmp(av1, "j", 1))
	{
		ft_strcpy(fract->name, "Julia");
		fract->julia_r = ft_atof(av2);
		fract->julia_i = ft_atof(av3);
	}
	else if (!ft_strncmp(av1, "f", 1))
	{
		ft_strcpy(fract->name, "Feather");
		fract->fx = ft_atof(av2);
		fract->fy = ft_atof(av3);
	}
}

void	ft_2fract_args(t_fractol *fract, char *av1)
{
	if (!ft_strncmp(av1, "m", 1))
		ft_strcpy(fract->name, "Mandelbrot");
	else if (!ft_strncmp(av1, "b", 1))
		ft_strcpy(fract->name, "Burning Ship");
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
