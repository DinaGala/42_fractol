/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:24:44 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/10/13 20:24:46 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    set_mandelbrot(t_data *frac)
{
//    ft_printf("enter set:\n"); //erase
    frac -> type = 1;
    frac -> lim.xmin = -2.1;
    frac -> lim.xmax = 0.7;
    frac -> lim.ymin = -1.2;
    frac -> lim.ymax = 1.2;
    frac -> lim.cr = 0;
    frac -> lim.cim = 0;
 //   printf("x min: %f  ymax: %f\n", frac -> lim.xmin, frac -> lim.ymax); //erase
}

void    draw_mandel(t_data *frac)
{
    double  x;
    double  y;
    double  temp;

    x = 0;
    y = 0;
    frac -> i = -1;
 //   ft_printf("Entered draw mandel\n"); //erase
 //   printf("y: %f  x: %f\n", frac->y, frac->x); //erase
    while ((x * x + y * y) <= 6.0 && ++frac->i < 100)
    {
        temp = x * x - y * y + frac->x;
        y = 2 * x * y + frac->y;
        x = temp;
    }
}