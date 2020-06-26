/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:19:27 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/26 12:47:20 by bbehm            ###   ########.fr       */
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

static void		do_more_u(t_tab *tab)
{
	if (tab->width && tab->zero && !tab->precision)
		ft_put_zeros(tab->width, &tab->len, tab->size);
	if (tab->precision || tab->zero)
		ft_put_zeros(tab->precision, &tab->len, tab->size);
	if (tab->minus)
	{
		if (!(tab->num && tab->output_u == 0))
			ft_putnbr_size(tab->output_u, tab->size);
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
	tab->len = ft_numlen_u(tab->output_u);
	if ((tab->num == -1 || tab->num == -2) && tab->output_u == 0)
		tab->len = 0;
	if (tab->width && !tab->zero && !tab->minus && !tab->precision)
		ft_put_spaces(tab->width, tab->len, tab->size);
	if (tab->width && tab->precision && !tab->minus)
	{
		if (tab->width > tab->precision && tab->precision > tab->len)
		{
			if (tab->plus || tab->space)
				ft_put_spaces(tab->width, tab->precision + 1, tab->size);
			else
				ft_put_spaces(tab->width, tab->precision, tab->size);
		}
		else if (tab->width > tab->precision && tab->width > tab->len)
			ft_put_spaces(tab->width, tab->len, tab->size);
	}
	do_more_u(tab);
}
