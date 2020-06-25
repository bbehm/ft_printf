/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:19:39 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/25 16:57:49 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static void		typecast_x(t_tab *tab)
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

static void		do_final_x(t_tab *tab, char flag)
{
	(tab->zero || tab->precision) ? ft_put_zeros(tab->precision, &tab->len, tab->size) : 0;
	if (tab->minus)
	{
		if (!tab->num && tab->output_u != 0)
			ft_itoa_base_size(tab->output_u, 16, tab->size, flag);
		if (tab->hash && tab->output_u != 0 && tab->precision >= tab->len)
			tab->len = tab->len + 2;
		ft_put_spaces(tab->width, tab->len, tab->size);
		return ;
	}
	if (tab->output_u != 0 && !tab->num)
		ft_itoa_base_size(tab->output_u, 16, tab->size, flag);
	return ;
}

static void		do_further_x(t_tab *tab, char flag)
{
	if (tab->hash)
	{
		if (tab->output_u != 0)
		{
			if (flag == 'x')
				ft_putstr_size("0x", tab->size);
			else
				ft_putstr_size("0X", tab->size);
			if (!tab->minus && tab->zero)
			{
				tab->precision ? ft_put_zeros(tab->precision, &tab->len, tab->size) : 0;
				!tab->precision && !tab->minus && tab->zero ? ft_put_zeros(tab->width, &tab->len, tab->size) : 0;
			}
		}
	}
	do_final_x(tab, flag);
}

static void		do_more_x(t_tab *tab, char flag)
{
	tab->width && !tab->minus && !tab->precision && !tab->zero ? ft_put_spaces(tab->width, tab->len, tab->size) : 0;
	if (tab->precision && tab->width && !tab->minus)
	{
		if (tab->precision < tab->width && tab->precision > tab->len)
			(tab->hash && tab->output_u != 0) ? ft_put_spaces(tab->width, tab->precision + 2, tab->size) : ft_put_spaces(tab->width, tab->precision, tab->size);
		else if (tab->precision < tab->width && tab->len < tab->width)
			ft_put_spaces(tab->width, tab->len, tab->size);
	}
	tab->zero && tab->width && !tab->precision && !tab->hash ? ft_put_zeros(tab->width, &tab->len, tab->size) : 0;
	do_further_x(tab, flag);
}

void			do_the_x(t_tab *tab, char flag)
{
	typecast_x(tab);
	tab->nbr = ft_itoa_base(tab->output_u, 16);
	tab->len = ft_strlen(tab->nbr);
	free(tab->nbr);
	tab->len = (tab->hash && tab->output_u != 0 && tab->width > tab->precision && tab->precision <= tab->len) ? tab->len + 2 : tab->len;
	tab->num && tab->output_u == 0 ? tab->len = 0 : 0;
	do_more_x(tab, flag);
}
