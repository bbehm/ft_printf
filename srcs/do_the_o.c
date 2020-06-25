/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:19:52 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/25 16:58:16 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static void	typecast_u(t_tab *tab)
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

static void	do_further_o(t_tab *tab, char flag)
{
	if (tab->hash)
	{
		tab->output_u != 0 ? ft_putchar_size('0', tab->size) : 0;
		tab->hash && tab->output_u == 0 && (tab->num == -2 || tab->num == -1) ? ft_putchar_size('0', tab->size) : 0;
	}
	if (tab->minus)
	{
		!(tab->num && tab->output_u == 0) ? ft_itoa_base_size(tab->output_u, tab->base, tab->size, flag) : 0;
		if (tab->precision < tab->width && tab->precision > tab->len)
			ft_put_spaces(tab->width, tab->precision, tab->size);
		else
			ft_put_spaces(tab->width, tab->len, tab->size);
		return ;
		ft_itoa_base_size(tab->output_u, tab->base, tab->size, flag);
	}
}

static void	do_more_o(t_tab *tab, char flag)
{
	tab->width && !tab->zero && !tab->minus && !tab->precision ? ft_put_spaces(tab->width, tab->len, tab->size) : 0;
	if (tab->width && !tab->minus && tab->precision)
	{
		if (tab->precision < tab->width && tab->precision > tab->len)
			ft_put_spaces(tab->width, tab->precision, tab->size);
		else if (tab->precision < tab->width && tab->width > tab->len)
			ft_put_spaces(tab->width, tab->len, tab->size);
	}
	tab->width && tab->zero && !tab->minus && !tab->precision ? ft_put_zeros(tab->width, &tab->len, tab->size) : 0;
	tab->zero || tab->precision ? ft_put_zeros(tab->precision, &tab->len, tab->size) : 0;
	do_further_o(tab, flag);
}

void		do_the_o(t_tab *tab, char flag)
{
	typecast_u(tab);
	tab->base = (flag == 'o' ? 8 : 2);
	tab->nbr = ft_itoa_base(tab->output_u, tab->base);
	tab->len = (flag == 'o') ? ft_strlen(tab->nbr) : 8;
	free(tab->nbr);
	(tab->hash && tab->output_u != 0) ? tab->len += 1 : tab->len;
	tab->num && tab->output_u == 0 ? tab->len = 0 : 0;
	tab->num && tab->output == 0 && tab->hash ? tab->len = 1 : 0;
	do_more_o(tab, flag);
}
