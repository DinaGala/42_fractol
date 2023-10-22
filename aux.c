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

 /*   if (x == 0 && y == 0)
    {
        printf("in pixel put: ppt - %p\nline - %i\nbits - %i\n", frac->img.ppt, \
        frac->img.line, frac->img.bits); // erase
    }*/
    pix = frac->img.ppt + (frac->img.line * y + x * (frac->img.bits / 8));
  /*  if (x == 0 && y == 0)
        printf("pix - %s, pointer - %p\n", pix, (int*)pix); */
    *(int*)pix = color; //what is going to happen if i do not cast it?
}

int ft_color(t_data *frac)
{
    if (frac->i == 100)
        return (0x000000);
    else
        return (frac->color * frac->color * 200 * frac->i);
 /*   else if (frac->i > 20)
        return (0x227640);
    else if (frac->i > 5)
        return (0x767640);
    else
        return (0x373889); */
}

int ft_key_hook(int key, t_data *frac)
{
    if (key == ESC)
        ft_free(frac);
    else if (key == SHIFT)
        frac->color++;
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
		printf("coordinates: x - %f, y - %f\n", (double)x, (double)y); // erase
        frac->lim.cr = -3 + 6 * (double)x / WIDTH;
		frac->lim.cim = -3 + 6 * (double)y / HEIGHT;
        printf("next c: cr - %f, cim - %f\n", frac->lim.cr, frac->lim.cim); //erase
	}
    if (key == ZOOM_IN || key == ZOOM_OUT)
        ft_zoom(key, (double)x / WIDTH, (double)y / (HEIGHT), frac);
    fractal_draw(frac);
    return (0);
}