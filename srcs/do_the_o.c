/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:19:52 by bbehm             #+#    #+#             */
/*   Updated: 2020/02/24 12:39:48 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static void			display_zero(uintmax_t num, char hash)
{
	if (hash == '#' && num)
		write(1, "0", 1);
}

static uintmax_t	get_num(t_tab *tab)
{
	uintmax_t num;

	if (tab->specifier_flag == '0')
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

static t_tab		*display(t_tab *tab, uintmax_t num, char *str, size_t left)
{
	int	is_blank;
	int num_width;

	num_width = ft_strlen(str);
	if (tab->convert[4] == '#' && num)
		num_width++;
	is_blank = num_width;
	if (num_width <= tab->precision && tab->precision > 0)
		is_blank = tab->precision;
	tab->length += (is_blank <= tab->width) ? tab->width : is_blank;
	if (!left)
		do_gap(tab, ' ', tab->width - is_blank, 0);
	display_zero(num, tab->convert[4]);
	do_gap(tab, '0', tab->precision - num_width, 0);
	ft_putstr(str);
	free(str);
	if (left)
		do_gap(tab, ' ', tab->width - is_blank, 0);
	return (tab);
}

t_tab				*do_the_o(t_tab *tab)
{
	char		*str;
	uintmax_t	num;
	size_t		left;

	left = 0;
	num = get_num(tab);
	if (num == 0 && tab->precision == 0 && tab->convert[4] != '#')
	{
		do_gap(tab, ' ', tab->width, 1);
		return (tab);
	}
	if (!(str = ft_itoa_base_mod(num, 8, 'a')))
		exit(-1);
	if (tab->convert[0] == '-')
		left = 1;
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
		tab->precision = tab->width;
	display(tab, num, str, left);
	return (tab);
}
