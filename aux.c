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

void    ft_pixel_put(t_data *frac, int x, int y)
{
    char    *pix;

    pix = frac->img->ppt + frac->img->line * y + x * (frac->img->bits / 8);
    *(unsigned int*)pix = ft_color(frac); //what is going to happen if i do not cast it?
}

int ft_color(t_data *frac)
{
    if (frac->i == 100)
        return (0x000000);
    if (frac->i < 5)
        return (0x00ff00);
    else
        return (0x0000ff);
}