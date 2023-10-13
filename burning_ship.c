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

void    set_bship(t_data *frac)
{
    frac->lim->xmin = -2;
    frac->lim->xmax = 0.7;
    frac->lim->ymin = -1.5;
    frac->lim->ymax = 1.5;
    frac->lim->cr = 0;
    frac->lim->cim = 0;
}
