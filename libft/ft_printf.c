/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:50:40 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/23 18:30:17 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(const char *str, va_list alst)
{
	str++;
	if (*str == '%')
		return (ft_putchar('%'));
	if (*str == 'c')
		return (ft_putchar(va_arg(alst, int)));
	if (*str == 's')
		return (ft_putstr(va_arg(alst, char *)));
	if (*str == 'p')
		return (ft_putptr_hex(va_arg(alst, void *)));
	if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(alst, int)));
	if (*str == 'u')
		return (ft_putnbr(va_arg(alst, unsigned int)));
	if (*str == 'x' || *str == 'X')
		return (ft_putnbr_hex(va_arg(alst, unsigned int), *str));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	alst;
	int		numchr;
	int		check;

	numchr = 0;
	check = 0;
	va_start(alst, str);
	while (*str && check != -1)
	{
		if (*str != '%')
		{
			check = ft_putchar(*str);
			str++;
		}
		else
		{	
			check = ft_type(str, alst);
			str = str + 2;
		}
		numchr = numchr + check;
	}
	if (check == -1)
		return (-1);
	va_end(alst);
	return (numchr);
}

/*#include <stdio.h>

int	main(void)
{
//	int	c = 99;
//	char	*str;
	int	i = -21474;
		
//	str = "";

//	printf(" NULL %s NULL ", NULL);
//	printf("\n%d\n", printf(" NULL %s NULL ", NULL));
	printf("\n%d", ft_printf("%i", i));
//	printf("\n%d", printf("%i", ""));
	//printf("decimal: %d  unsigned decimal: %u  percent: %% \n", i, i);
	//ft_printf("decimal: %d  unsigned decimal: %u  percent: %% \n", i, i);
	//printf("xhex: %x  XHEX: %X  pointer: %p \n", i, i, str);
	//ft_printf("xhex: %x  XHEX: %X  pointer: %p \n", i, i, str);

	return (0);
}*/
