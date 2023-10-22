/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:24:20 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/10/13 20:24:22 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    set_ship(t_data *frac)
{
    frac->type = 3;
    frac->lim.xmin = -2.2;
    frac->lim.xmax = 1.3;
    frac->lim.ymin = -2;
    frac->lim.ymax = 1.4;
 //   frac->lim.cr = 0;
 //   frac->lim.cim = 0;
}

void    draw_ship(t_data *frac)
{
    double  x;
    double  y;
    double  temp;

    x = 0;
    y = 0;
    frac -> i = -1;
 //   ft_printf("Entered draw mandel\n"); //erase
 //   printf("y: %f  x: %f\n", frac->y, frac->x); //erase
    while ((x * x + y * y) <= 4.0 && ++frac->i < 100)
    {
        temp = x * x - y * y + frac->x;
        y = fabs(2 * x * y) + frac->y;
        x = temp;
    }
}

void    draw_zhuzhleva(t_data *frac)
{
    double  x;
    double  y;
    double  temp;

    x = 0;
    y = 0;
    frac -> i = -1;
 //   ft_printf("Entered draw mandel\n"); //erase
 //   printf("y: %f  x: %f\n", frac->y, frac->x); //erase
    while ((x * x + y * y) <= 4.0 && ++frac->i < 1000)
    {
        temp = x * x - y * y + frac->x;
        y = fabs(2 * x) * y + frac->y;
        x = temp;
    }
}