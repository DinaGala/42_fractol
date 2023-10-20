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
//	ft_printf("Enter ft_free \n"); //erase
	if (frac && frac->win)
		mlx_destroy_window(frac->init, frac->win);
//	if (frac && frac->img && frac->img->ipt)
//		mlx_destroy_image(frac->init, frac->img->ipt);
//	mlx_destroy_display(frac->init);
//	free(frac->init);
//	frac->init = NULL;
	exit (1);
}

int	fractal_draw(t_data *frac)
{
	int	a;
	int	b;

	a = -1;
	printf("entering draw, ymax %f ymin %f\n", frac->lim.ymax, frac->lim.ymin); //erase
	while (++a < WIDTH)
	{
		frac->x = frac->lim.xmin + (double)a * (frac->lim.xmax - \
			frac->lim.xmin) / WIDTH;
		b = -1;
		if (a < 4)
			printf("x %f b %i\n", frac->x, a); //erase
		while (++b < HEIGHT)
		{
			frac->y = frac->lim.ymin + (double)b * (frac->lim.ymax - \
			frac->lim.ymin) / HEIGHT;
			if (a == 0)
				printf("ymin %f b %f, max %f, diff %f, height %i\n", frac->lim.ymin, (double)b, frac->lim.ymax, frac->lim.ymax - \
			frac->lim.ymin, HEIGHT); //erase
			if (frac->type == 1)
				draw_mandel(frac);
	//		ft_printf("I'm in the fractal_draw"); //erase
			else if (frac->type == 2)
				draw_julia(frac);
			else if (frac->type == 3)
				draw_ship(frac);
//			ft_printf("Before pixel put"); //erase
			ft_pixel_put(frac, a, b, ft_color(frac));
		}
//		ft_printf("after pixel put %i \n", a); //erase
	}
//	ft_printf("before put to window \n"); //erase
	mlx_put_image_to_window(frac->init, frac->win, frac->img->ipt, 0, 0);
	return (1);
//	ft_printf("after put to window \n"); //erase
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
	{
		free(frac->init);
		exit (1);
	}
	frac->img = &img;
	frac->img->ipt = mlx_new_image(frac->init, WIDTH, HEIGHT);
	if (!frac->img->ipt)
		exit (ft_free(frac));
//	printf("before new get data addr, ymax %f \n", frac->lim.ymax); //erase
	frac->img->ppt = mlx_get_data_addr(frac->img->ipt, &frac->img->bits, \
	&frac->img->line, &frac->img->endian);
//	printf("after new get data addr, ymax %f \n", frac->lim.ymax); //erase
//	printf("after initialize, ymax %f \n", frac->lim->ymax); //erase
	fractal_draw(frac);
//	ft_printf("after initialize \n"); //erase
}

void	parse(int ac, char **argv, t_data *frac)
{
	t_lim   lim;

	ft_memset(&lim, 0, sizeof(t_lim));
	frac->lim = lim;
	if (ac == 2 && !ft_strncmp(argv[1], "mandelbrot", 10) && !*(argv[1] + 10))
	{
		set_mandelbrot(frac);
	}	
	else if (ac >= 2 && !ft_strncmp(argv[1], "julia", 5) && !*(argv[1] + 5))
	{
		frac->type = 2;
		set_julia(ac, argv, frac);
	}
	else if (ac == 2 && !ft_strncmp(argv[1], "burning_ship", 12) \
	&& !*(argv[1] + 12))
		set_ship(frac);
	else
	{
		ft_printf("Introduce one of the available fractals:\n");
		ft_printf("1. mandelbrot\n2. julia\n3. burning_ship\n");
		exit (1);
	}
//	printf("leaving set, ymax %f \n", frac->lim.ymax); //erase
}

int	main(int argc, char **argv)
{
	t_data	frac;
//	t_img	img;

//	ft_memset(&frac, 0, sizeof(t_data));
	parse(argc, argv, &frac);
//	ft_printf("After parsing"); //erase
	initialize(argv[1], &frac);
//	frac.init = mlx_init();
//	frac.win = mlx_new_window(frac.init, WIDTH, HEIGHT, "try");
//	frac.img = &img;
//	frac.img->ipt = mlx_new_image(frac.init, WIDTH, HEIGHT);
//	frac.img->ppt = mlx_get_data_addr(frac.img->ipt, &frac.img->bits, \
//	&frac.img->line, &frac.img->endian);
//	ft_pixel_put(&frac, 5, 5, 0x224477);
//	mlx_put_image_to_window(frac.init, frac.win, frac.img->ipt, 0, 0);
	mlx_hook(frac.win, 17, 0, ft_free, &frac);
//	mlx_hook(frac.win, 53, 0, ft_free, &frac);
	mlx_key_hook(frac.win, ft_key_hook, &frac);
//	mlx_hook(frac.win, ARROW_LEFT, 0, ft_move, &frac);
//	mlx_key_hook(frac.win, ft_key_hook, &frac);
//	mlx_key_hook(frac.win, fn, (void *)0);

	mlx_loop(frac.init);
//	ft_free(&frac);
	return (0);
}
