/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:31:34 by ssottori          #+#    #+#             */
/*   Updated: 2024/04/17 14:41:15 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"


int main(void)
{
    t_fract fract;
    
    fract.mlx = mlx_init();
    //fractol.mlx_window = mlx_new_window(fractol.mlx_init_bruv, WIDTH, HEIGHT, "test");
    fract.img = mlx_new_image(fract.mlx, WIDTH, HEIGHT);
    //mlx_loop(fract.mlx);
}


