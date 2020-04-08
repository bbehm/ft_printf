/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:20:15 by bbehm             #+#    #+#             */
/*   Updated: 2020/02/24 12:51:56 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static t_tab	*do_the_percent(t_tab *tab)
{
	if (tab->convert[3] == '0' && tab->precision <= 0 && !tab->convert[0])
	{
		tab->precision = tab->width;
		tab->width = 0;
	}
	if (tab->convert[0] != '-')
		do_gap(tab, ' ', tab->width - 1, 1);
	if (tab->convert[3] == '0')
		do_gap(tab, '0', tab->precision - 1, 1);
	write(1, "%", 1);
	if (tab->convert[0] == '-')
		do_gap(tab, ' ', tab->width - 1, 1);
	tab->length++;
	return (tab);
}

t_tab			*leftover(t_tab *tab)
{
	if (tab->f_treat[tab->i] == '%')
	{
		do_the_percent(tab);
		return (tab);
	}
	if (tab->convert[3] == '0' && tab->precision <= 0 && !tab->convert[0])
	{
		tab->precision = tab->width;
		tab->width = 0;
	}
	if (tab->convert[0] != '-')
		do_gap(tab, ' ', tab->width - 1, 1);
	if (tab->convert[3] == '0')
		do_gap(tab, '0', tab->precision - 1, 1);
	write(1, &tab->f_copy[tab->i], 1);
	if (tab->convert[0] == '-')
		do_gap(tab, ' ', tab->width - 1, 1);
	tab->length++;
	return (tab);
}
