/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 08:11:00 by tamighi           #+#    #+#             */
/*   Updated: 2021/09/29 16:38:32 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_init_flags(void)
{
	t_flags	*init;

	init = (t_flags *)malloc(sizeof(t_flags));
	if (!init)
		return (0);
	init->nb = 0;
	init->splus = 0;
	init->minus = 0;
	init->zero = ' ';
	init->hash = 0;
	init->dot = -1;
	init->first = 0;
	return (init);
}

t_struct	*ft_init_struct(void)
{
	t_struct	*tab;

	tab = (t_struct *)malloc(sizeof(t_struct) * 9);
	if (!tab)
		return (0);
	tab[0].c = 'c';
	tab[0].function = *ft_print_c;
	tab[1].c = 'd';
	tab[1].function = *ft_print_d;
	tab[2].c = 'i';
	tab[2].function = *ft_print_d;
	tab[3].c = 'u';
	tab[3].function = *ft_print_u;
	tab[4].c = 'x';
	tab[4].function = *ft_print_x;
	tab[5].c = 'X';
	tab[5].function = *ft_print_x;
	tab[6].c = 's';
	tab[6].function = *ft_print_s;
	tab[7].c = 'p';
	tab[7].function = *ft_print_p;
	tab[8].c = 0;
	return (tab);
}
