/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:24:30 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/10/13 20:24:35 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    set_julia(int argc, char **argv, t_data *frac)
{
    int flag;

    flag = 0;
    frac->lim->cr = 0.9;
    frac->lim->cim = 0.35;
    if (argc == 4)
    {
        flag += ft_atof(argv[2], &frac->lim->cr);
        flag += ft_atof(argv[3], &frac->lim->cim);
    }
    if (argc == 2 || flag > 0 || argc == 3 || argc > 4)
    {
        ft_printf("You can follow the name of julia by 2 numbers\n");
        ft_printf("to change the constant part of the equation:\n");
        ft_printf("Example: ./fractol julia 0.3 -0.56\n");
        if (flag > 0 || argc == 3 || argc > 4)
            exit (1);
    }
    frac->lim->xmin = -2;
    frac->lim->xmax = 2;
    frac->lim->ymin = -2;
    frac->lim->ymax = 2;
}

int ft_atof(char *str, double *c)
{
    int     i;
    double  x;
    double  d;

    i = 0;
    x = 0;
    d = 0.1;
    if (str[i] == '-')
        i++;
    while(str[i] && (str[i] >= '0' && str[i] <= '9'))
        x = x * 10 + (str[i++] - '0');
    if (str[i] && str[i++] == '.')
    {
        while (str[i] && (str[i] >= '0' && str[i] <= '9'))
        {
            x += (str[i++] - '0') * d;
            d *= 0.1;
        }
    }
    if (str[i] || (str[0] == '-' && x == 0))
        return (1);
    if (str[0] == '-')
        x *= -1;
    *c = x;
    return (0);
}