/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:21:02 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/21 15:45:17 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libs/libft/inc/ft_printf.h"

void	ft_readme(void)
{
	ft_printf("\nWelcome to my fractal!\nUnfortunately, MiniLibX's limited capabilities result in slow rendering 😞\n");
	ft_printf("\nTo move the fractal:  Press keys: W, A, S, D or Left, Right, Up, Down arrows\n");
	ft_printf("To zoom in:  Scroll mouse wheel up\n");
	ft_printf("To zoom out:  Scroll mouse wheel down\n");
	ft_printf("To switch colours:  Press: Space bar\n");
	ft_printf("To increase iterations:	Press key: + (from the number pad)\n");
	ft_printf("To decrease iterations:  Press key: -\n");
	ft_printf("To rotate Julia:	Mouse left or right click\n");
	ft_printf("To quit:  Press: ESC or click X on window, or ^C\n");
	ft_printf("\nTry: <./fractal julia -0.4 +0.6> or\n<./fractol julia -0.835 -0.2321>\n");
	ft_printf("\nWARNING: Attempting to resize or maximize the window will lose you to the BLACKHOLE!\n");
}

void	ft_malloc_err(void)
{
	perror("MALLOC ERROR: ");
	exit(EXIT_FAILURE);
}

int   ft_close_window(t_fractol *fract)
{
  mlx_destroy_image(fract->mlx, fract->img.img);
  mlx_destroy_window(fract->mlx, fract->window);
  mlx_destroy_display(fract->mlx);
  free(fract->mlx);
  exit(EXIT_SUCCESS);
}
