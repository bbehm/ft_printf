/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:00:51 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/11 15:10:15 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static int		num_len(intmax_t num)
{
	int tens;

	if (num < 0)
		num *= -1;
	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static intmax_t	get_num(t_tab *tab)
{
	intmax_t num;

	if (ft_strcmp(tab->argument_flag, "hh") == 0)
		num = (signed char)(va_arg(tab->args, int));
	else if (ft_strcmp(tab->argument_flag, "h") == 0)
		num = (short)(va_arg(tab->args, int));
	else if (ft_strcmp(tab->argument_flag, "ll") == 0)
		num = (long long)(va_arg(tab->args, long long int));
	else if (ft_strcmp(tab->argument_flag, "l") == 0)
		num = (long)(va_arg(tab->args, long int));
	else
		num = (int)(va_arg(tab->args, int));
	num = (intmax_t)num;
	return (num);
}

static char		get_negativity(t_tab *tab, int is_negative)
{
	char *temp;

	temp = tab->convert;
	if (is_negative)
		return ('-');
	if (temp[1] == '+')
		return ('+');
	if (temp[2] == ' ')
		return (' ');
	return ('\0');
}

static t_tab	*do_more(t_tab *tab, intmax_t num, int n_w, int l_a)
{
	int		is_blank;
	int		is_negative;
	char	negativity;

	is_negative = (num < 0) ? 1 : 0;
	num *= (is_negative && num != (-9223372036854775807 - 1)) ? -1 : 1;
	negativity = get_negativity(tab, is_negative);
	is_blank = n_w;
	if (n_w <= tab->precision && tab->precision >= 0)
		is_blank = tab->precision;
	if (negativity)
		is_blank++;
	tab->length += (is_blank <= tab->width) ? tab->width : is_blank;
	if (!l_a)
		do_gap(tab, ' ', tab->width - is_blank, 0);
	if (negativity)
		write(1, &negativity, 1);
	do_gap(tab, '0', tab->precision - n_w, 0);
	if (num != (-9223372036854775807 - 1))
		ft_putnbrmax_fd(num, 1);
	else if ((tab->length += 18) > 0)
		write(1, "9223372036854775808", 19);
	if (l_a)
		do_gap(tab, ' ', tab->width - is_blank, 0);
	return (tab);
}

t_tab			*do_the_d(t_tab *tab)
{
	intmax_t	num;
	int			num_width;
	int			left_align;

	num = get_num(tab);
	if (num == 0 && tab->precision == 0)
	{
		if (tab->convert[1] == '+')
			show_char('+', tab);
		if (tab->convert[2] == ' ')
			show_char(' ', tab);
		do_gap(tab, ' ', tab->width, 1);
		return (tab);
	}
	num_width = num_len(num);
	left_align = (tab->convert[0] == '-') ? 1 : 0;
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
	{
		tab->precision = tab->width;
		if (num < 0 || tab->convert[2] || tab->convert[1] || tab->convert[0])
			tab->precision--;
	}
	do_more(tab, num, num_width, left_align);
	return (tab);
}
