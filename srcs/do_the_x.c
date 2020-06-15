/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:19:39 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/15 15:11:10 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include <stdio.h>

static uintmax_t	get_num(t_tab *tab)
{
	uintmax_t	num;

	if (tab->specifier_flag == 'U')
		num = (unsigned long)(va_arg(tab->args, unsigned long int));
	else if (ft_strcmp(tab->argument_flag, "hh") == 0)
		num = (unsigned char)(va_arg(tab->args, unsigned int));
	else if (ft_strcmp(tab->argument_flag, "h") == 0)
		num = (unsigned short)(va_arg(tab->args, unsigned int));
	else if (ft_strcmp(tab->argument_flag, "ll") == 0)
		num = (unsigned long long)(va_arg(tab->args, unsigned long long int));
	else if (ft_strcmp(tab->argument_flag, "l") == 0)
		num = (unsigned long)(va_arg(tab->args, unsigned long int));
	else if (ft_strcmp(tab->argument_flag, "j") == 0)
		num = (uintmax_t)(va_arg(tab->args, uintmax_t));
	else if (ft_strcmp(tab->argument_flag, "z") == 0)
		num = (size_t)(va_arg(tab->args, size_t));
	else
		num = (unsigned int)(va_arg(tab->args, unsigned int));
	num = (uintmax_t)num;
	return (num);
}

static void			display_zero(uintmax_t num, char hash, char flag)
{
	if (num)
	{
		if (hash == '#' && flag == 'x')
			write(1, "0x", 2);
		if (hash == '#' && flag == 'X')
			write(1, "0X", 2);
	}
}

static t_tab		*do_more_x(t_tab *tab, uintmax_t num, char *str, int l_a)
{
	int is_blank;
	int num_width;

	if ((num_width = ft_strlen(str)) && tab->convert[4] == '#' && num &&
			tab->convert[3] == '0' && tab->width)
		num_width += 2;
	else if ((num_width = ft_strlen(str)) && tab->convert[4] == '#' && num)
	{
		tab->width -= 2;
		tab->length += 2;
	}
	is_blank = (num_width <= tab->precision && tab->precision > 0) ?
		tab->precision : num_width;
	tab->length += (is_blank <= tab->width) ? tab->width : is_blank;
	if (!l_a)
		do_gap(tab, ' ', tab->width - is_blank, 0);
	display_zero(num, tab->convert[4], tab->specifier_flag);
	ft_putstr(str);
	if (l_a)
		do_gap(tab, ' ', tab->width - is_blank, 0);
	return (tab);
}

t_tab				*do_the_x(t_tab *tab, char flag)
{
	char		*str;
	char		cases;
	int			left_align;
	uintmax_t	num;

	left_align = 0;
	num = get_num(tab);
	if (num == 0 && tab->precision == 0)
	{
		do_gap(tab, ' ', tab->width, 1);
		return (tab);
	}
	cases = 'a';
	if (tab->specifier_flag == 'X')
		cases = 'A';
	if (!(str = ft_itoa_base_mod(num, 16, cases)))
		exit(-1);
	if (tab->convert[0] == '-')
		left_align = 1;
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
		tab->precision = tab->width;
	do_more_x(tab, num, str, left_align);
	free(str);
	return (tab);
}
