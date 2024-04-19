/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:35:54 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/19 13:59:28 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef fract_H
# define fract_H

// =======LIBRARIES
# include "mlx.h"
# include <math.h>
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
# define WIDTH 1920
# define HEIGHT 1080

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

// =========MOUSE
# define M_LEFT_CLICK 1
# define M_RIGHT_CLICK 2
# define M_MID_CLICK 3
# define M_ZOOM_IN 4
# define M_ZOOM_OUT 5

# define PI 3.141592653

// ==========STRUCTS
typedef struct s_img
{
	void	*img;
	char	*addy;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fract
{

  void  *mlx;
  void  *window;
  t_img   img;

} t_fract;

void  ft_run_test1(t_fract *fract);
void    ft_init_test(t_fract *fract);
void  ft_put_pixel(t_fract *fract, int x, int y, int rgb);
void    draw_circle(t_fract *fract, int centre_x, int centre_y, int radius);
void  ft_init_window(t_fract *fract);
void  ft_arg_err(void);
void  ft_args_checks(t_fract *fract, int ac, char **av);
void  ft_keyhooks(t_fract *fract);
void    ft_init_image(t_fract *fract);
int   ft_esc_key(int key, t_fract *fract);
int   ft_close_window(t_fract *fract);
int   color_map(t_fract *fract, int w, int h);

#endif
