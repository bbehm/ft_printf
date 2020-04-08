/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:20:07 by bbehm             #+#    #+#             */
/*   Updated: 2020/02/24 16:59:53 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static uintmax_t	get_num(t_tab *tab)
{
	uintmax_t num;

	num = (unsigned long)(va_arg(tab->args, unsigned long int));
	num = (uintmax_t)num;
	return (num);
}

static t_tab		*do_more_u(t_tab *tab, char *str, int left_align)
{
	int is_blank;
	int num_width;

	num_width = ft_strlen(str) + 2;
	is_blank = num_width;
	tab->length += (is_blank <= tab->width) ? tab->width : is_blank;
	if (!left_align)
		do_gap(tab, ' ', tab->width - is_blank, 0);
	write(1, "0x", 2);
	do_gap(tab, '0', (tab->precision - num_width) + 2, 1);
	ft_putstr(str);
	if (left_align)
		do_gap(tab, ' ', tab->width - is_blank, 0);
	free(str);
	return (tab);
}

t_tab				*do_the_p(t_tab *tab)
{
	char		*str;
	int			left_align;
	uintmax_t	num;

	left_align = 0;
	num = get_num(tab);
	if (!(str = ft_itoa_base_mod(num, 16, 'a')))
		exit(-1);
	if (tab->convert[0] == '-')
		left_align = 1;
	if (tab->precision == 0 && num == 0)
		*str = '\0';
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
	{
		tab->precision = tab->width - 2;
		tab->width = 0;
	}
	do_more_u(tab, str, left_align);
	return (tab);
}
