/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:17:08 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/07 09:30:59 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("Bye bye!\n");
	ft_printf("You closed the window :(\n");
	exit(EXIT_SUCCESS);
}

int	ft_keyhook(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_exit(data);
	if (keycode
