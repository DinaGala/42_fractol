/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:23:10 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/10/25 22:23:14 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_free(t_data *frac)
{
	if (frac && frac->win)
		mlx_destroy_window(frac->init, frac->win);
	exit (1);
}

int	fractal_draw(t_data *frac)
{
	int	a;
	int	b;

	a = -1;
	while (++a < WIDTH)
	{
		frac->x = frac->lim.xmin + (double)a * (frac->lim.xmax - \
			frac->lim.xmin) / WIDTH;
		b = -1;
		while (++b < HEIGHT)
		{
			frac->y = frac->lim.ymin + (double)b * (frac->lim.ymax - \
			frac->lim.ymin) / HEIGHT;
			if (frac->type == 1)
				draw_mandel(frac);
			else if (frac->type == 2)
				draw_julia(frac);
			else
				draw_ship(frac);
			ft_pixel_put(frac, a, b, ft_color(frac));
		}
	}
	mlx_put_image_to_window(frac->init, frac->win, frac->img.ipt, 0, 0);
	return (1);
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
	ft_memset(&img, 0, sizeof(t_img));
	frac->img = img;
	frac->img.ipt = mlx_new_image(frac->init, WIDTH, HEIGHT);
	if (!frac->img.ipt)
		exit (ft_free(frac));
	frac->img.ppt = mlx_get_data_addr(frac->img.ipt, &frac->img.bits, \
	&frac->img.line, &frac->img.endian);
	fractal_draw(frac);
}

void	parse(int ac, char **argv, t_data *frac)
{
	t_lim	lim;

	ft_memset(&lim, 0, sizeof(t_lim));
	frac->lim = lim;
	frac->color = 3;
	if (ac == 2 && !ft_strncmp(argv[1], "mandelbrot", 10) && !*(argv[1] + 10))
		set_mandelbrot(frac);
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
}

int	main(int argc, char **argv)
{
	t_data	frac;

	parse(argc, argv, &frac);
	initialize(argv[1], &frac);
	mlx_hook(frac.win, 17, 0, ft_free, &frac);
	mlx_hook(frac.win, 2, 0, ft_read_keys, &frac);
	mlx_key_hook(frac.win, ft_key_hook, &frac);
	mlx_mouse_hook(frac.win, ft_mouse_hook, &frac);
	mlx_loop(frac.init);
	return (0);
}
