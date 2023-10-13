/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:02:15 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/10/10 21:29:09 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//int	fn(void)
//{
//	return(write(1, "x", 1));
//}

int	ft_free(t_data *frac)
{
	if (frac->img->ipt)
		mlx_destroy_image(frac->init, frac->img->ipt);
	if (frac->win)
		mlx_destroy_window(frac->init, frac->win);
	mlx_destroy_display(frac->init);
	free(frac->init);
	return (1);
}

void	fractal_pixel_put(t_data *frac)
{
	frac->x = -1;
	while (frac->x++ < WIDTH)
	{
		frac->y = -1;
		while (frac->y++ < HEIGHT)
		{
			
		}

	}
}

void	initialize(char *name, t_data *frac)
{
	frac->init = NULL;
	frac->win = NULL;
	frac->init = mlx_init();
	if (!frac->init)
		exit (1);
	frac->win = mlx_new_window(frac->init, WIDTH, HEIGHT, name);
	if (!frac->win)
		exit (ft_free(frac));
	frac->img->ipt = mlx_new_image(frac->init, WIDTH, HEIGHT);
	if (!frac->img->ipt)
		exit (ft_free(frac));
	frac->img->ppt = mlx_get_data_addr(frac->img->ipt, &frac->img->bits, \
	&frac->img->line, &frac->img->endian);
	fractal_pixel_put(frac->img->ipt);
}

void	parse(int ac, char **argv, t_data *frac)
{
	if (ac == 2 && !ft_strncmp(argv[1], "mandelbrot", 10) && !*(argv[1] + 10))
		set_mandelbrot(frac);
	else if (ac >= 2 && !ft_strncmp(argv[1], "julia", 5) && !*(argv[1] + 5))
	{
		frac->type = 2;
		set_julia(ac, argv, frac);
	}
	else if (ac == 2 && !ft_strncmp(argv[1], "burning_ship", 12) \
	&& !*(argv[1] + 12))
		set_bship(frac);
	else
	{
		ft_printf("Introduce one of the available fractals:\n");
		ft_printf("1. mandelbrot\n2. julia\n3. burning_ship\n");
		exit (1);
	}
}


int	main(int argc, char **argv)
{
	t_data	frac;

	parse(argc, argv, &frac);
	initialize(argv[1], &frac);
	mlx_pixel_put(frac.init, frac.win, 100, 50, color);
	mlx_key_hook(frac.win, fn, (void *)0);
	mlx_loop(frac.init);
	ft_free(&frac);
	return (0);
}
