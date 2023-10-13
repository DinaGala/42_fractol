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
    frac->type = 1;
    frac->lim->xmin = -2;
    frac->lim->xmax = 0.7;
    frac->lim->ymin = -1;
    frac->lim->ymax = 1;
    frac->lim->cr = 0;
    frac->lim->cim = 0;
}
