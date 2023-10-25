/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:23:59 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/10/25 22:24:03 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	set_mandelbrot(t_data *frac)
{
	frac -> type = 1;
	frac -> color = 9;
	frac -> lim.xmin = -2.1;
	frac -> lim.xmax = 0.7;
	frac -> lim.ymin = -1.2;
	frac -> lim.ymax = 1.2;
	frac -> lim.cr = 0;
	frac -> lim.cim = 0;
}

void	draw_mandel(t_data *frac)
{
	double	x;
	double	y;
	double	temp;

	x = 0;
	y = 0;
	frac -> i = -1;
	while ((x * x + y * y) <= 6.0 && ++frac->i < 100)
	{
		temp = x * x - y * y + frac->x;
		y = 2 * x * y + frac->y;
		x = temp;
	}
}
