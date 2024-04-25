/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:47:35 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/21 16:35:16 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixel(t_fractol *fract, int x, int y, int rbg)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = fract->img.addy + (y * fract->img.line_length
				+ x * (fract->img.bpp / 8));
		*(unsigned int *)dst = rbg;
    //printf("Setting pixel at (x, y) = (%d, %d) with color %#x\n", x, y, rbg);
	}
}

double	ft_atof(char *str)
{
	double  integer;
	double	fraction;
	int		sign;
    double  pwr;

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
