/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:38:47 by bbehm             #+#    #+#             */
/*   Updated: 2020/02/26 12:51:32 by bbehm            ###   ########.fr       */
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
	if (*conv == 'd' || *conv == 'i' || *conv == 'D')
		do_the_d(tab);
	else if (*conv == 'c' || *conv == 'C')
		do_the_c(tab);
	else if (*conv == 's' && ft_strcmp(tab->argument_flag, "l") == 0)
		do_the_ws(tab);
	else if (*conv == 's')
		do_the_s(tab);
	else if (*conv == 'S')
		do_the_ws(tab);
	else if (*conv == 'u' || *conv == 'U')
		do_the_u(tab);
	else if (*conv == 'x' || *conv == 'X')
		do_the_x(tab);
	else if (*conv == 'o' || *conv == 'O')
		do_the_o(tab);
	else if (*conv == 'p')
		do_the_p(tab);
	else if (*conv == 'f')
		do_the_f(tab);
	else
		leftover(tab);
	return (tab);
}

int		fix(t_tab *tab)
{
	tab->i++;
	fix_conversion(tab);
	fix_width(tab);
	fix_precision(tab);
	fix_arguments(tab);
	fix_specifier(tab);
	display_options(tab);
	return (tab->length);
}
