/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:54:04 by bbehm             #+#    #+#             */
/*   Updated: 2020/02/23 15:59:20 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

t_tab	*do_the_c(t_tab *tab)
{
	wint_t c;

	if (ft_strcmp(tab->argument_flag, "l") == 0)
		c = (unsigned long)va_arg(tab->args, unsigned long);
	else if (tab->specifier_flag == 'C')
		c = (wchar_t)va_arg(tab->args, wint_t);
	else
		c = (char)va_arg(tab->args, int);
	c = (wint_t)c;
	if (tab->convert[3] == '0' && tab->convert[0] != '-')
		do_gap(tab, '0', tab->width - 1, 1);
	else if (tab->convert[0] != '-')
		do_gap(tab, ' ', tab->width - 1, 1);
	show_char(c, tab);
	if (tab->convert[0] == '-')
		do_gap(tab, ' ', tab->width - 1, 1);
	return (tab);
}
