/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:02:11 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/10/18 21:02:53 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_pixel_put(t_data *frac, int x, int y, int color)
{
    char    *pix;

    pix = frac->img->ppt + (frac->img->line * y + x * (frac->img->bits / 8));
    *(int*)pix = color; //what is going to happen if i do not cast it?
}

int ft_color(t_data *frac)
{
    if (frac->i == 1000)
        return (0x000000);
    else if (frac->i > 80)
        return (0x129640);
    else if (frac->i > 20)
        return (0x227640);
    else if (frac->i > 5)
        return (0x767640);
    else
        return (0x373889);
}

int ft_key_hook(int key, t_data *frac)
{
    if (key == ESC)
        ft_free(frac);
    if (key > 122 && key < 127)
        ft_move(key, frac);
    else
        return (1);
    fractal_draw(frac);
    return (0);
}

void    ft_move(int key, t_data *frac)
{
    double  x_len;
    double  y_len;

    x_len = frac->lim.xmax - frac->lim.xmin;
    y_len = frac->lim.ymax - frac->lim.ymin;
    if (key == ARROW_LEFT)
    {
        frac->lim.xmin -= x_len * MOVE;
        frac->lim.xmax -= x_len * MOVE;
    }
    if (key == ARROW_RIGHT)
    {
        frac->lim.xmin += x_len * MOVE;
        frac->lim.xmax += x_len * MOVE;
    }
    if (key == ARROW_DOWN)
    {
        frac->lim.ymin -= y_len * MOVE;
        frac->lim.ymax -= y_len * MOVE;
    }
    if (key == ARROW_UP)
    {
        frac->lim.ymin += y_len * MOVE;
        frac->lim.ymax += y_len * MOVE;
    }
}