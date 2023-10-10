/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:02:15 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/10/10 21:29:09 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fn(void)
{
	return(write(1, "x", 1));
}

int	main(void)
{
	void	*mlxi;
	void	*win;

	mlxi = mlx_init();
	win = mlx_new_window(mlxi, 1442, 1098, "Hello!");
	mlx_pixel_put(mlxi, win, 100, 50, 0x224477);
	mlx_key_hook(win, fn, (void *)0);
	mlx_loop(mlxi);
}
