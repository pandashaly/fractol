/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:00:20 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 17:03:24 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	blend_colours(int colour1, int colour2, double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - t) * ((colour1 >> 16) & 0xFF) + t * \
		((colour2 >> 16) & 0xFF) * 5);
	g = (int)((1 - t) * ((colour1 >> 8) & 0xFF) + t * \
		((colour2 >> 8) & 0xFF) * 5);
	b = (int)((1 - t) * (colour1 & 0xFF) + t * \
		(colour2 & 0xFF) * 5);
	r = (int)(r + (255 - r) * t * 1.5);
	g = (int)(g + (255 - g) * t * 0.2);
	b = (int)(b + (255 - b) * t * 4);
	return ((r << 16) | (g << 8) | b);
}

void	ft_psychedellic(t_fractol *fract)
{
	static int	color_arr[] = {BLACK, RED, GREEN, YELLOW, BLUE,
		WHITE, LIGHTNING, LIME, LILAC, PINK, LAVA, CYAN, ORANGE};
	static int	color_code = 0;

	color_code = (color_code + 1) % (sizeof(color_arr) / sizeof(color_arr[0]));
	fract->color = color_arr[color_code];
	ft_init_fractol(fract);
}

t_rbg	color_map(float t, int colorscheme)
{
	if (colorscheme == 1)
		return (classic(t));
	else if (colorscheme == 2)
		return (alternate(t));
	else if (colorscheme == 3)
		return ((t_rbg){255, 255, 255});
	return ((t_rbg){255, 0, 0});
}
