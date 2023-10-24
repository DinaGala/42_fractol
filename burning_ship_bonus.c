
#include "fractol_bonus.h"

void    set_ship(t_data *frac)
{
    frac->type = 3;
    frac->color = 3;
    frac->lim.xmin = -2.2;
    frac->lim.xmax = 1.3;
    frac->lim.ymin = -2;
    frac->lim.ymax = 1.4;
}

void    draw_ship(t_data *frac)
{
    double  x;
    double  y;
    double  temp;

    x = 0;
    y = 0;
    frac -> i = -1;
    while ((x * x + y * y) <= 7.0 && ++frac->i < 100)
    {
        temp = x * x - y * y + frac->x;
        y = fabs(2 * x * y) + frac->y;
        x = temp;
    }
}