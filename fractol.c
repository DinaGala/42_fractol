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

int	ft_free(t_data *frac)
{
	ft_printf("Enter ft_free \n"); //erase
	if (frac->img->ipt)
		mlx_destroy_image(frac->init, frac->img->ipt);
	if (frac->win)
		mlx_destroy_window(frac->init, frac->win);
//	mlx_destroy_display(frac->init);
	free(frac->init);
	return (1);
}

void	fractal_draw(t_data *frac)
{
	int	a;
	int	b;

	a = -1;
	while (a++ < WIDTH)
	{
		frac->x = frac->lim->xmin + (double)a * (frac->lim->xmax - \
			frac->lim->xmin) / WIDTH;
		b = -1;
		while (b++ < HEIGHT)
		{
			frac->y = frac->lim->ymin + (double)b * (frac->lim->ymax - \
			frac->lim->ymin) / HEIGHT;
			if (frac->type == 1)
				draw_mandel(frac);
	//		ft_printf("I'm in the fractal_draw"); //erase
		//	else if (frac->type == 2)
		//		draw_julia(frac);
		//	else if (frac->type == 3)
		//		draw_ship(frac);
			ft_pixel_put(frac, a, b);
		}
		ft_printf("after pixel put %i \n", a); //erase
	}
	ft_printf("before put to window \n"); //erase
	mlx_put_image_to_window(frac->init, frac->win, frac->img->ipt, 0, 0);
	ft_printf("after put to window \n"); //erase
}

void	initialize(char *name, t_data *frac)
{
	t_img	img;

	frac -> init = NULL;
	frac -> win = NULL;
	frac -> i = -1;
	frac -> init = mlx_init();
	if (!frac->init)
		exit (1);
	frac->win = mlx_new_window(frac->init, WIDTH, HEIGHT, name);
	if (!frac->win)
		exit (ft_free(frac));
	frac->img = &img;
	frac->img->ipt = mlx_new_image(frac->init, WIDTH, HEIGHT);
	if (!frac->img->ipt)
		exit (ft_free(frac));
	frac->img->ppt = mlx_get_data_addr(frac->img->ipt, &frac->img->bits, \
	&frac->img->line, &frac->img->endian);
	fractal_draw(frac);
	ft_printf("after initialize \n"); //erase
}

void	parse(int ac, char **argv, t_data *frac)
{
	t_lim   lim;

	frac->lim = &lim;
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
//	ft_printf("After parsing"); //erase
	initialize(argv[1], &frac);
//	mlx_key_hook(frac.win, fn, (void *)0);
	mlx_loop(frac.init);
//	ft_free(&frac);
	return (0);
}
