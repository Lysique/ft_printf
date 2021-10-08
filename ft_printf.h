/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 08:57:37 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/04 09:59:34 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flag
{	
	char	conv;	
	char	zero;
	char	splus;
	int		nb;
	int		minus;
	int		hash;
	int		dot;
	int		first;
}				t_flags;

typedef struct s_struct
{
	char	c;
	int		(*function)(va_list, t_flags *);
}				t_struct;

int			ft_printf(const char *str, ...);
int			ft_print_s(va_list, t_flags *flags);
int			ft_print_c(va_list, t_flags *flags);
int			ft_print_d(va_list, t_flags *flags);
int			ft_print_x(va_list, t_flags *flags);
int			ft_print_u(va_list, t_flags *flags);
int			ft_print_p(va_list, t_flags *flags);

int			ft_putchar(char c);
int			ft_strlen(char *c);
void		ft_set_flags(t_flags *flags);
int			ft_nblen(unsigned int nb, t_flags *flags);

t_flags		*ft_init_flags(void);
t_struct	*ft_init_struct(void);

#endif
