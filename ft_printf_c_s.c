/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:33:22 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/06 18:04:56 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *c, int length)
{
	int	i;

	i = 0;
	while (c[i] != '\0' && i < length)
		ft_putchar(c[i++]);
	return (i);
}

int	ft_print_c(va_list valist, t_flags *flags)
{
	char	arg;
	int		length;

	length = 0;
	arg = va_arg(valist, int);
	ft_set_flags(flags);
	while (!flags->minus && flags->nb > ++length)
		ft_putchar(' ');
	ft_putchar(arg);
	while (flags->minus && flags->nb > ++length)
		ft_putchar(' ');
	return (length);
}

int	ft_print_s(va_list valist, t_flags *flags)
{
	int		length;
	char	*arg;

	length = 0;
	arg = va_arg(valist, char *);
	if (flags->dot == -1 || flags->dot > ft_strlen(arg))
		flags->dot = ft_strlen(arg);
	while (!flags->minus && flags->nb-- > flags->dot && ++length)
		ft_putchar(' ');
	if (!arg)
		length += ft_putstr("(null)", flags->dot);
	else
		length += ft_putstr(arg, flags->dot);
	while (flags->minus && flags->nb-- > flags->dot && ++length)
		ft_putchar(' ');
	return (length);
}
