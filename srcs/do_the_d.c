/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:00:51 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/18 09:36:36 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static void 	do_final(t_tab *tab)
{
	if (tab->minus)
	{
		if (tab->output < 0)
		{
			ft_putchar_size('-', tab->size);
			tab->output *= -1;
		}
		!(tab->num && tab->output == 0) ? ft_putnbr_size(tab->output, tab->size) : 0;
		(tab->output >= 0 && (tab->plus || tab->space) && !(tab->precision < tab->len) && !tab->sign) ? tab->len += 1 : 0;
		tab->sign == 1 && !(tab->precision < tab->len) ? tab->len += 1 : 0;
		ft_put_spaces(tab->width, tab->len, tab->size);
		return ;
	}
	if (tab->num && tab->output == 0)
		return ;
	ft_putnbr_size(tab->output, tab->size);
}

static void		do_further(t_tab *tab)
{
	tab->space && !tab->minus && tab->width && !tab->zero && tab->precision ? do_gap(tab->width, tab->len, tab->size) : 0;
	if (tab->output >= 0 && (tab->plus || tab->space))
		tab->plus ? ft_put_plus(tab->size) : ft_put_space(tab->size);
	if (tab->precision || tab->zero)
	{
		if (tab->output < 0)
		{
			ft_putchar_size('-', tab->size);
			tab->output *= -1;
			tab->sign = 1;
		}
		tab->precision ? ft_put_zeros(tab->precision, &tab->len, tab->size) : 0;
		tab->zero && !tab->precision && !tab->minus ? ft_put_zeros(tab->width, &tab->len, tab->size) : 0;
	}
	do_final(tab);
}

static void		do_more(t_tab *tab)
{
	tab->width && !tab->zero && !tab->space && !tab->minus && !tab->precision ? do_gap(tab->width, tab->len, tab->size) : 0;
	if (tab->width && tab->precision && !tab->minus)
	{
		if (tab->width > tab->precision && tab->precision > tab->len)
			(tab->plus || tab->space || tab->output < 0) ? do_gap(tab->width, tab->precision + 1, tab->size) : do_gap(tab->width, tab->precision, tab->size);
		else if (tab->width > tab->precision && tab->width > tab->len)
			do_gap(tab->width, tab->len, tab->size);
		do_further(tab);
	}
}

void			do_the_d(t_tab *tab)
{
	typecast_int(tab);
	tab->len = ft_numlen(tab->output);
	tab->len = (tab->output >= 0 && (tab->plus || tab->space) && tab->precision < tab->width && tab->precision <= tab->len) ? tab->len + 1 : tab->len;
	tab->len = (tab->precision >= tab->len && tab->output < 0) ? tab->len - 1 : tab->len;
	tab->num && tab->output == 0 ? tab->len = 0 : 0;
	tab->num && tab->output == 0 && (tab->plus || tab->space) ? tab->len = 1 : 0;
	do_more(tab);
}
