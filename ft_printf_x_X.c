/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:26:14 by tamighi           #+#    #+#             */
/*   Updated: 2021/09/30 09:54:49 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr, t_flags *flags, char *base)
{
	unsigned int	length;
	int				i;

	length = 1;
	i = 0;
	while (nbr / length >= 16)
		length = length * 16;
	if (flags->hash)
	{
		ft_putchar('0');
		ft_putchar('x' - ('x' - flags->conv));
	}
	while (flags->dot-- > ft_nblen(nbr, flags) && ++i)
		ft_putchar('0');
	while (length != 0)
	{
		if (nbr / length > 9 && flags->conv == 'X')
			ft_putchar(base[nbr / length] - 32);
		else
			ft_putchar(base[nbr / length]);
		nbr = nbr % length;
		length = length / 16;
	}
	return (i);
}

int	ft_add_hex(unsigned int nbr, t_flags *flags)
{
	int	length;
	int	dot;

	length = 0;
	dot = flags->dot;
	if (ft_nblen(nbr, flags) > dot)
		dot = ft_nblen(nbr, flags);
	while (!flags->minus && (flags->nb--) > dot && ++length)
		ft_putchar(' ');
	if (flags->splus && ++length)
		ft_putchar(flags->splus);
	length += ft_puthex(nbr, flags, "0123456789abcdef");
	while (flags->minus && (flags->nb--) > dot && ++length)
		ft_putchar(' ');
	length += ft_nblen(nbr, flags);
	return (length + flags->hash);
}

int	ft_print_x(va_list valist, t_flags *flags)
{
	int				length;
	unsigned int	arg;

	arg = va_arg(valist, unsigned int);
	if (!arg)
		flags->hash = 0;
	ft_set_flags(flags);
	length = ft_add_hex(arg, flags);
	return (length);
}
