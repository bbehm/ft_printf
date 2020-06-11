/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:19:27 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/10 11:03:35 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

/*
** This function handles unsigned 
*/

void				ft_putnbrumax_fd(uintmax_t n, int fd)
{
	if (n > 9)
		ft_putnbrumax_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

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

static int			num_len(uintmax_t num)
{
	int len;

	len = 1;
	while ((num /= 10) > 0)
		len++;
	return (len);
}

static t_tab		*do_more_u(t_tab *tab, uintmax_t num, int n_w, int l)
{
	int is_blank;

	is_blank = n_w;
	if (n_w <= tab->precision)
		is_blank = tab->precision;
	tab->length += (is_blank <= tab->width) ? tab->width : is_blank;
	if (!l)
		do_gap(tab, ' ', tab->width - is_blank, 0);
	do_gap(tab, '0', tab->precision - n_w, 0);
	ft_putnbrumax_fd(num, 1);
	if (l)
		do_gap(tab, ' ', tab->width - is_blank, 0);
	return (tab);
}

t_tab				*do_the_u(t_tab *tab)
{
	uintmax_t	num;
	int			num_width;
	int			left;

	left = 0;
	num = get_num(tab);
	if (num == 0 && tab->precision == 0)
	{
		do_gap(tab, ' ', tab->width, 1);
		return (tab);
	}
	num_width = num_len(num);
	if (num == 0 && tab->precision == 0)
		left = 1;
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
		tab->precision = tab->width;
	do_more_u(tab, num, num_width, left);
	return (tab);
}
