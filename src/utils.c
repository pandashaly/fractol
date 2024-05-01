/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:15:04 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 17:12:26 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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

/*void  ft_julia_data(t_fractol *fract)
{
	fract->max_r = 2.5;
	fract->min_r = -2.5;
	fract->max_i = 1.5;
	fract->min_i = -1.5;
}

*/
