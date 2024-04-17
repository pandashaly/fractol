/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:35:54 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/14 20:12:01 by ssottori         ###   ########.fr       */
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
# include <X11/X.h> //X11 functions & data types for graphics and window management
# include <X11/keysym.h> //to identify keyboard events. allows you to map keycodes to more human-readable key symbols

// ========WINDOW SIZE
# define WIDTH 1000
# define HEIGHT 1000

// ========COLORS
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define RED            0xFF0000
# define MAGENTA		0xFF00FF
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
# define PASTELPINK		0xFFB6C1
# define LILAC          0xEFB1FF

// =========KEYS
# define KEY_ESC 53

typedef struct s_fract
{

  void  *mlx;
  void  *window;
  void  *img;

} t_fract;

void  ft_pixel_put(t_fract *fractol, int x, int y, int rgb);
void  ft_init_window(t_fract *fractol);
void  ft_arg_err(void);
void  ft_args_checks(t_fract *fractol, int ac, char **av);
void  ft_keyhooks(t_fract *fractol);
int   ft_esc_key(int key, t_fract *fractol);
int   ft_close_window(t_fract *fractol);

#endif
