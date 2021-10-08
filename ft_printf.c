/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 08:57:32 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/04 09:56:59 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getnb(char **str)
{
	int	nb;

	nb = 0;
	if (**str == '.')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		nb = nb * 10;
		nb += **str - '0';
		(*str)++;
	}
	(*str)--;
	return (nb);
}

t_flags	*ft_checkflags(char **str)
{
	t_flags	*flags;

	flags = ft_init_flags();
	if (!flags)
		return (0);
	while (**str)
	{
		if (**str == '+' || **str == ' ')
			flags->splus = **str;
		else if (**str == '-')
			flags->minus = 1;
		else if (**str == '0')
			flags->zero = '0';
		else if (**str == '#')
			flags->hash = 2;
		else if (**str >= '1' && **str <= '9')
			flags->nb = ft_getnb(str);
		else if (**str == '.')
			flags->dot = ft_getnb(str);
		else
			break ;
		(*str)++;
	}
	return (flags);
}

int	free_my_structs(t_struct *tab, t_flags *flags)
{
	if (tab)
		free(tab);
	if (flags)
		free(flags);
	return (0);
}

int	ft_convert(char **str, va_list valist)
{
	t_struct	*tab;
	t_flags		*flags;
	int			length;
	int			i;

	tab = ft_init_struct();
	flags = ft_checkflags(str);
	i = 0;
	if (!flags || !tab)
		return (free_my_structs(tab, flags));
	while (tab[i].c)
	{
		if (tab[i].c == **str)
		{
			flags->conv = **str;
			length = tab[i].function(valist, flags);
			free(flags);
			free(tab);
			return (length);
		}
		i++;
	}
	free(flags);
	free(tab);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	valist;
	int		length;

	length = 0;
	va_start(valist, str);
	while (*str)
	{
		if (*str == '%' && *++str != '%')
			length += ft_convert((char **)&str, valist);
		else
			length += ft_putchar(*str);
		str++;
	}
	va_end(valist);
	return (length);
}
