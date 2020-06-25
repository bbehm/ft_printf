/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:19:27 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/25 16:57:39 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static void		typecast_u(t_tab *tab)
{
	if (tab->length == 'a')
		tab->output_u = (unsigned long)va_arg(tab->args, void*);
	else if (tab->length == 'A')
		tab->output_u = (unsigned long long)va_arg(tab->args, void*);
	else if (tab->length == 'h')
		tab->output_u = (unsigned short)va_arg(tab->args, void*);
	else if (tab->length == 'H')
		tab->output_u = (unsigned char)va_arg(tab->args, void*);
	else
		tab->output_u = va_arg(tab->args, unsigned int);
}

static void		ft_putnbr_u(uintmax_t n, int *size)
{
	if (n < 0)
	{
		ft_putchar_size('-', size);
		n = -n;
	}
	if (n / 10)
	{
		ft_putnbr_u(n / 10, size);
	}
	*size = *size + 1;
	ft_putchar(n % 10 + '0');
}

static void		do_more_u(t_tab *tab)
{
	tab->width && tab->zero && !tab->precision ? ft_put_zeros(tab->width, &tab->len, tab->size) : 0;
	tab->precision || tab->zero ? ft_put_zeros(tab->precision, &tab->len, tab->size) : 0;
	if (tab->minus)
	{
		!(tab->num && tab->output_u == 0) ? ft_putnbr_size(tab->output_u, tab->size) : 0;
		ft_put_spaces(tab->width, tab->len, tab->size);
		return ;
	}
	if (tab->num && tab->output_u == 0)
		return ;
	ft_putnbr_u(tab->output_u, tab->size);
}

/*
** This function handles unsigned values
*/

void			do_the_u(t_tab *tab)
{
	typecast_u(tab);
	tab->len = ft_numlen(tab->output_u);
	(tab->num == -1 || tab->num == -2) && tab->output_u == 0 ? tab->len = 0 : 0;
	tab->width && !tab->zero && !tab->minus && !tab->precision ? ft_put_spaces(tab->width, tab->len, tab->size) : 0;
	if (tab->width && tab->precision && !tab->minus)
	{
		if (tab->width > tab->precision && tab->precision > tab->len)
			(tab->plus || tab->space) ? ft_put_spaces(tab->width, tab->precision + 1, tab->size) : ft_put_spaces(tab->width, tab->precision, tab->size);
		else if (tab->width > tab->precision && tab->width > tab->len)
			ft_put_spaces(tab->width, tab->len, tab->size);
	}
	do_more_u(tab);
}
