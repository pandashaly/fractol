/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:18:24 by ssottori          #+#    #+#             */
/*   Updated: 2024/01/16 15:58:33 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

int main(void)
{
    void	*mlx;
    void	*mlx_win;
	void	*grass;

    // Initialize MiniLibX
    mlx = mlx_init();

    // Create a window
    mlx_win = mlx_new_window(mlx, 800, 200, "So_Long");

	grass = mlx_xpm_file_to_image(mlx, "Grass.xpm", &width, &height);

	mlx_put_image_to_window(mlx, mlx_win, grass, x, y);

    // Display the window and enter the event loop
    mlx_loop(mlx);

    return 0;
}
