/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:37:55 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/10/24 20:38:03 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol_bonus.h"

void    ft_pixel_put(t_data *frac, int x, int y, int color)
{
    char    *pix;

    pix = frac->img.ppt + (frac->img.line * y + x * (frac->img.bits / 8));
    *(int*)pix = color;
}

int ft_color(t_data *frac)
{
    if (frac->i == 100)
        return (0x000000);
    else if (frac->type == 3)
        return (frac->i * frac->color << 16 \
        | frac->color << 8 \
        | frac->i);
    else if (frac->type == 1)
        return (frac->i * frac->color << 16 \
        | frac->i * frac->color << 8 \
        | frac->i);
    else
        return (240 * frac->i * frac->color << 16 \
        | 50 * frac->i * frac->color << 8 \
        | frac->i * frac->color);
}

int ft_key_hook(int key, t_data *frac)
{
    if (key == ESC)
        ft_free(frac);
    else if (key == SHIFT)
    {    
        if (frac->color < 1000)
            frac->color *= 3;
        else
            frac->color = 1;
    }
    else
        return (1);
    fractal_draw(frac);
    return (0);
}

int ft_read_keys(int key, t_data *frac)
{
    if (key > 122 && key < 127)
        ft_move(key, frac);
    fractal_draw(frac);
    return (0);
}

int ft_mouse_hook(int key, int  x, int  y, t_data *frac)
{
    if (frac -> type == 2 && key == LEFT_CLICK)
	{

        frac->lim.cr = -2 + (frac->lim.xmax - frac->lim.xmin) * \
        (double)x / WIDTH;
		frac->lim.cim = -2 + (frac->lim.ymax - frac->lim.ymin) * \
        (double)y / HEIGHT;
	}
    if (key == ZOOM_IN || key == ZOOM_OUT)
        ft_zoom(key, (double)x / WIDTH, (double)y / (HEIGHT), frac);
    fractal_draw(frac);
    return (0);
}
