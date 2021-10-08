/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:20:16 by tamighi           #+#    #+#             */
/*   Updated: 2021/09/29 17:54:59 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(unsigned int nbr, t_flags *flags)
{
	unsigned int	length;
	int				i;

	length = 1;
	i = 1;
	while (nbr / length >= 10)
	{
		length = length * 10;
		i++;
	}
	while (flags->dot > i && ++i)
		ft_putchar('0');
	while (length != 0)
	{
		ft_putchar(nbr / length + '0');
		nbr = nbr % length;
		length = length / 10;
	}
	return (i);
}

int	ft_add_nb(unsigned int nbr, t_flags *flags)
{
	int	length;
	int	dot;

	length = 0;
	dot = flags->dot;
	if (dot < ft_nblen(nbr, flags))
		dot = ft_nblen(nbr, flags);
	while (!flags->minus && (flags->nb--) > dot && ++length)
		ft_putchar(' ');
	if (flags->splus && ++length)
		ft_putchar(flags->splus);
	length += ft_putnbr(nbr, flags);
	while (flags->minus && (flags->nb--) > dot && ++length)
		ft_putchar(' ');
	return (length);
}

int	ft_print_u(va_list valist, t_flags *flags)
{
	int				length;
	unsigned int	arg;

	arg = va_arg(valist, unsigned int);
	ft_set_flags(flags);
	length = ft_add_nb(arg, flags);
	return (length);
}

int	ft_print_d(va_list valist, t_flags *flags)
{
	int				length;
	int				arg;
	unsigned int	nb;

	arg = va_arg(valist, int);
	if (arg < 0)
	{
		flags->splus = '-';
		nb = (unsigned int)(arg * -1);
	}
	else
		nb = (unsigned int)arg;
	ft_set_flags(flags);
	length = ft_add_nb(nb, flags);
	return (length);
}
