/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:15:23 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 16:15:26 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_readme(void)
{
	ft_printf("\nWelcome to my fractal!\n");
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

void	ft_malloc_err(void)
{
	perror("MALLOC ERROR: ");
	exit(EXIT_FAILURE);
}

int	ft_close_window(t_fractol *fract)
{
	mlx_destroy_image(fract->mlx, fract->img.img);
	mlx_destroy_window(fract->mlx, fract->window);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	exit(EXIT_SUCCESS);
}
