/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:44:20 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/09 20:45:20 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_readme(void)
{
	ft_printf("\nWelcome to my fractal explorations!\n");
	ft_printf("Unfortunately, MiniLibX's limited");
	ft_printf(" capabilities result in slow rendering 😞\n");
	ft_printf("Bigger the window or higher max iterations,");
	ft_printf("the slower it will be.\n");
	ft_printf("\nTo move the fractal: w, a, s, d or arrow keys\n");
	ft_printf("To zoom in:  Scroll mouse wheel up\n");
	ft_printf("To zoom out:  Scroll mouse wheel down\n");
	ft_printf("To cycle colours:  Space bar\n");
	ft_printf("To change colorschemes: Press 1, 2, or 3 - or 0 to reset.\n");
	ft_printf("To increase iterations:	+ (from the number pad)\n");
	ft_printf("To decrease iterations:  -\n");
	ft_printf("To quit:  ESC or click X on window, or ^C in terminal\n");
	ft_printf("\nTry: <./fractal julia -0.4 +0.6> or\n");
	ft_printf("<./fractol julia -0.835 -0.2321>\n");
	ft_printf("\nWARNING: Attempting to resize or ");
	ft_printf("maximize the window will get you fractol BLACKHOLED!\n\n\n");
}

void	ft_ui_instructions(t_fractol *fract)
{
	mlx_string_put(fract->mlx, fract->win, 23, 23, LILAC, "Controls Keys");
	mlx_string_put(fract->mlx, fract->win, 23, 53, LILAC,
		"Move = ^ v < > OR w a s d");
	mlx_string_put(fract->mlx, fract->win, 23, 73, LILAC, "Up Iters = +");
	mlx_string_put(fract->mlx, fract->win, 23, 93, LILAC, "Down Iters = -");
	mlx_string_put(fract->mlx, fract->win, 23, 113, LILAC, "Color = SPACE");
	mlx_string_put(fract->mlx, fract->win, 23, 133, LILAC,
		"Colorscheme = 1 2 3");
	mlx_string_put(fract->mlx, fract->win, 23, 153, LILAC, "Reset color = 0");
	mlx_string_put(fract->mlx, fract->win, 23, 173, LILAC, "Zoom = SCROLL");
	mlx_string_put(fract->mlx, fract->win, 23, 193, LILAC, "Exit = ESC");
}
