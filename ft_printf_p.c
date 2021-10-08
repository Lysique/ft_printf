/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:36:41 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/07 09:48:36 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointerlen(unsigned long int nb)
{
	unsigned long int	length;
	int					i;

	length = 16;
	i = 1;
	while (nb / length > 0)
	{
		nb = nb / length;
		i++;
	}
	return (i);
}

int	ft_putpointer(unsigned long int nbr, t_flags *flags, char *base)
{
	unsigned long int	length;
	int					dot;
	int					i;

	length = 1;
	dot = flags->dot;
	i = 0;
	while (nbr / length >= 16)
		length = length * 16;
	ft_putchar('0');
	ft_putchar('x');
	if (!flags->dot)
		return (0);
	while ((flags->dot--) > ft_pointerlen(nbr) && ++i)
		ft_putchar('0');
	while (length != 0)
	{
		ft_putchar(base[nbr / length]);
		nbr = nbr % length;
		length = length / 16;
	}
	flags->dot = dot;
	return (i);
}

int	ft_add_pointer(unsigned long int nbr, t_flags *flags)
{
	int	length;

	length = 0;
	if (!nbr && !flags->dot)
		flags->dot = 0;
	else if (flags->dot < ft_pointerlen(nbr))
		flags->dot = ft_pointerlen(nbr);
	while (!flags->minus && (flags->nb--) > flags->dot && ++length)
		ft_putchar(' ');
	if (flags->splus && ++length)
		ft_putchar(flags->splus);
	length += ft_putpointer(nbr, flags, "0123456789abcdef");
	while (flags->minus && (flags->nb--) > flags->dot && ++length)
		ft_putchar(' ');
	if (flags->dot)
		length += ft_pointerlen(nbr);
	return (length + flags->hash);
}

int	ft_print_p(va_list valist, t_flags *flags)
{
	unsigned long int	arg;
	int					length;

	arg = va_arg(valist, unsigned long int);
	flags->hash = 2;
	ft_set_flags(flags);
	length = ft_add_pointer(arg, flags);
	return (length);
}
