/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:39:01 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/06 17:40:30 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_nblen(unsigned int nb, t_flags *flags)
{
	unsigned int	length;
	int				i;

	i = 1;
	length = 10;
	if (flags->conv == 'x' || flags->conv == 'X')
		length = 16;
	while (nb / length > 0)
	{
		nb = nb / length;
		i++;
	}
	return (i);
}

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (6);
	while (c[i])
		i++;
	return (i);
}

void	ft_set_flags(t_flags *flags)
{
	if (flags->splus)
		flags->first = 1;
	if (flags->hash)
		flags->first = 2;
	if (flags->minus && flags->zero == '0')
		flags->zero = ' ';
	flags->nb -= flags->first;
	if (flags->zero == '0' && flags->dot == -1)
		flags->dot = flags->nb;
}
