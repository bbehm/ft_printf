/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:38:47 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/11 15:04:21 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>

t_tab	*display_options(t_tab *tab)
{
	char *conv;

	conv = &tab->specifier_flag;
	if (*conv == 'd' || *conv == 'i')
		do_the_d(tab);
	else if (*conv == 'c')
		do_the_c(tab);
	else if (*conv == 's' && ft_strcmp(tab->argument_flag, "l") == 0)
		do_the_ws(tab);
	else if (*conv == 's')
		do_the_s(tab);
	else if (*conv == 'u')
		do_the_u(tab);
	else if (*conv == 'x' || *conv == 'X')
		do_the_x(tab);
	else if (*conv == 'o')
		do_the_o(tab);
	else if (*conv == 'p')
		do_the_p(tab);
	else if (*conv == 'f')
		do_the_f(tab);
	else
		leftover(tab);
	return (tab);
}

static void	flag_options(t_tab *tab)
{
	char *flag;

	flag = &tab->specifier_flag;
	if (*flag == '#')
		tab->hash = 1;
	else if (*flag == '-')
		tab->minus = 1;
	else if (*flag == ' ')
		tab->space = 1;
	else if (*flag == '0')
		tab->zero = 1;
	else if (*flag == '+')
		tab->plus = 1;
}

int		fix(t_tab *tab)
{
	tab->i++;
	fix_conversion(tab);
	fix_width(tab);
	fix_precision(tab);
	fix_arguments(tab);
	fix_specifier(tab);
	flag_options(tab);
	display_options(tab);
	return (tab->length);
}
