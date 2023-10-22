/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:08:20 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/10/22 16:08:42 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_move(int key, t_data *frac)
{
    double  x_len;
    double  y_len;

    x_len = frac->lim.xmax - frac->lim.xmin;
    y_len = frac->lim.ymax - frac->lim.ymin;
    if (key == ARROW_RIGHT)
    {
        frac->lim.xmin += x_len * MOVE;
        frac->lim.xmax += x_len * MOVE;
        
    }
    if (key == ARROW_LEFT)
    {
        frac->lim.xmin -= x_len * MOVE;
        frac->lim.xmax -= x_len * MOVE;
    }
    if (key == ARROW_UP)
    {
        frac->lim.ymin -= y_len * MOVE;
        frac->lim.ymax -= y_len * MOVE;
    }
    if (key == ARROW_DOWN)
    {
        frac->lim.ymin += y_len * MOVE;
        frac->lim.ymax += y_len * MOVE;
    }
}

void    ft_zoom(int key, double x, double y, t_data *frac)
{
    double  x_len;
    double  y_len;

    x_len = frac->lim.xmax - frac->lim.xmin;
    y_len = frac->lim.ymax - frac->lim.ymin;
 //   printf("coordinates: x - %f, y - %f\n", (double)x, (double)y); // erase
    if (key == ZOOM_IN)
    {
        frac->lim.xmin -= ((x_len / ZOOM) - x_len) * x;
        frac->lim.xmax += ((x_len / ZOOM) - x_len) * (1 - x);
        frac->lim.ymin -= ((y_len / ZOOM) - y_len) * y;
        frac->lim.ymax += ((y_len / ZOOM) - y_len) * (1 - y);
    }
    if (key == ZOOM_OUT)
    {
        frac->lim.xmin -= ((x_len * ZOOM) - x_len) * x;
        frac->lim.xmax += ((x_len * ZOOM) - x_len) * (1 - x);
        frac->lim.ymin -= ((y_len * ZOOM) - y_len) * y;
        frac->lim.ymax += ((y_len * ZOOM) - y_len) * (1 - y);
    }
}