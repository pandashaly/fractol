/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:35:54 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/27 18:00:21 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include <libs/mlx.h>
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

# define IMG_W 32
# define IMG_H 32

enum	e_map
{
	T_EMPTY = '0',
	T_WALL = '1',
	T_COLLECTIBLE = 'C',
	T_PLAYER = 'P',
	T_EXIT = 'E',
	T_ENEMY = 'N',
};

int	map_name(const char *file);
void	sl_error(char *err);

#endif
