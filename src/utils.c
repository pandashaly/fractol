/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:47:35 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 15:15:25 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_put_pixel(t_fractol *fract, int x, int y, int rbg)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = fract->img.addy + (y * fract->img.line_length
				+ x * (fract->img.bpp / 8));
		*(unsigned int *)dst = rbg;
	}
}

double	ft_atof(char *str)
{
	double	integer;
	double	fraction;
	int		sign;
	double	pwr;

	integer = 0;
	fraction = 0.0;
	sign = 1;
	pwr = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		++str;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str && *str != '.')
		integer = (integer * 10) + (*str++ - '0');
	if (*str == '.')
		++str;
	while (*str)
	{
		pwr /= 10;
		fraction = fraction + (*str++ - '0') * pwr;
	}
	return ((integer + fraction) * sign);
}

void	ft_init_fractol(t_fractol *fract)
{
	if (ft_strcmp(fract->name, "Mandelbrot") == 0)
		ft_init_mandelbrot(fract);
	else if (ft_strcmp(fract->name, "Julia") == 0)
		ft_init_julia(fract, fract->julia_r, fract->julia_i);
	else if (ft_strcmp(fract->name, "Burning Ship") == 0)
		ft_init_burningship(fract);
	else
		ft_arg_err();
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

/*void  ft_julia_data(t_fractol *fract)
{
	fract->max_r = 2.5;
	fract->min_r = -2.5;
	fract->max_i = 1.5;
	fract->min_i = -1.5;
}

*/

void	ft_set_colorscheme(t_fractol *fract, int key)
{
	if (key >= 1 && key <= 3)
	{
		fract->colorscheme = key;
		fract->diff_colorscheme = true;
	}
}
