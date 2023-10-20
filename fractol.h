/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:02:42 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/10/10 21:17:22 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
 
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "keys.h"
//# include <X11/keysymdef.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define HEIGHT 1000
# define WIDTH 1300
# define COLOR 

typedef struct s_lim
{
    double xmin;
    double xmax;
    double ymin;
    double ymax;
    double cr;
    double cim;
} t_lim;

typedef struct s_img
{
    void    *ipt;
    char    *ppt;
    int     bits;
    int     endian;
    int     line;
 } t_img;

typedef struct s_data
{
    void    *init;
    void    *win;
    int     type;
    double     x;
    double     y;
    int     i;
    t_lim   lim;
    t_img   *img;
  
} t_data;

/****  fractol.c - main and creating a window ******/
void	initialize(char *argv, t_data *frac);
int     ft_free(t_data *frac);
void    parse(int ac, char **argv, t_data *frac);
void	fractal_draw(t_data *frac);
/**************************************************/

/****  aux.c - general mlx functions ******/
void    ft_pixel_put(t_data *frac, int a, int b, int color);
int     ft_color(t_data *frac);

/****  mandelbrot.c - all functions related to mandelbrot ******/
void    set_mandelbrot(t_data *frac);
void    draw_mandel(t_data *frac);

/****  julia.c - all functions related to julia ******
void    set_julia(int argc, char **argv, t_data *frac);
int     ft_atof(char *str, double *c);
void    draw_julia(t_data *frac);*/

/****  burning_ship.c - all functions related to burning_ship ******
void    set_bship(t_data *frac);
void    draw_julia(t_data *frac);*/

#endif