/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:15:42 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 16:15:44 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*int	main(int ac, char **av)
{
	t_fractol fract;

		if ((ac == 2 && (!ft_strncmp(av[1], "m", 1)))
			|| (ac == 4 && !ft_strncmp(av[1], "j", 1)))
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
}*/

int	main(int ac, char **av)
{
	t_fractol	fract;

	if (ac >= 2)
	{
		if ((ac == 2 && (!ft_strncmp(av[1], "m", 1)))
			|| (ac == 2 && !ft_strncmp(av[1], "b", 1)))
			ft_2fract_args(&fract, av[1]);
		else if ((ac == 4 && (!ft_strncmp(av[1], "j", 1)))
			|| (ac == 4 && !ft_strncmp(av[1], "f", 1)))
			ft_4fract_args(&fract, av[1], av[2], av[3]);
	}
	else
		ft_arg_err();
	if (fract.name[0] != '\0')
	{
		fract.diff_colorscheme = false;
		ft_init_canvas(&fract);
		ft_init_fractol(&fract);
		mlx_loop(fract.mlx);
	}
	return (0);
}
