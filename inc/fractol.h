/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:35:54 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/14 14:29:50 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// =======LIBRARIES
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

// ========WINDOW SIZE
# define WIDTH 1000
# define HEIGHT 1000

// ========COLORS
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define RED      0xFF0000
# define MAGENTA			0xFF00FF
# define LIME			0xCCFF00
# define ORANGE			0xFF6600
# define PURPLE			0x9932CC
# define CYAN			0x33CCCC
# define PINK			0xFF66B2
# define ELECTRIC		0x0066FF
# define LIGHTNING		0x00CCFF
# define LAVA			0xFF3300
# define YELLOW			0xFFFF00
# define PASTELYELLOW	0xFFFF99
# define	PASTELPINK		0xFFB6C1
# define LILAC      0xEFB1FF

typedef struct s_fractol
{

  void  *mlx_init_bruv;
  void  *mlx_window;
  t_image img;

} t_fractol;

void  ft_pixel_put(t_fractol *fractol, int x, int y, int rgb);

#endif
