/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:18:03 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/23 18:59:10 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlongnbr(long nb)
{
	int	len;
	int	check;

	if (nb < 10)
		return (ft_putchar(nb + 48));
	else
		len = ft_putlongnbr(nb / 10);
	if (len == -1)
		return (-1);
	check = ft_putchar(nb % 10 + 48);
	if (check == -1)
		return (-1);
	return (len + check);
}

int	ft_putnbr(long nb)
{
	int	len;
	int	check;

	len = 0;
	if (nb < 0)
	{
		len = ft_putchar('-');
		nb = nb * -1;
	}
	if (len == -1)
		return (-1);
	check = ft_putlongnbr(nb);
	if (check == -1)
		return (-1);
	return (len + check);
}

int	ft_putnbr_hex(unsigned long long nb, const char x)
{
	char	*hex;
	int		len;
	int		check;

	if (x == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nb < 16)
		return (ft_putchar(hex[nb]));
	else
		len = ft_putnbr_hex(nb / 16, x);
	if (len == -1)
		return (-1);
	check = ft_putchar(hex[nb % 16]);
	if (check == -1)
		return (-1);
	return (len + check);
}

int	ft_putptr_hex(void *p)
{
	int	len;
	int	check;

	len = write(1, "0x", 2);
	if (len == -1)
		return (-1);
	check = ft_putnbr_hex((unsigned long long)p, 'x');
	if (check == -1)
		return (-1);
	return (len + check);
}
