/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:30:43 by bbehm             #+#    #+#             */
/*   Updated: 2020/02/24 12:42:40 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

t_tab	*do_the_s(t_tab *tab)
{
	char	*str;
	size_t	i;
	size_t	length;

	i = 0;
	str = va_arg(tab->args, char *);
	if (tab->precision > -1 && str)
		str = ft_strndup(str, tab->precision);
	else if (tab->precision == -1 && str)
		str = ft_strdup(str);
	else if (tab->precision > -1 && !str)
		str = ft_strndup("(null)", tab->precision);
	else if (tab->precision == -1 && !str)
		str = ft_strdup("(null)");
	length = ft_strlen(str);
	tab->length += length;
	if (tab->convert[3] == '0' && tab->convert[0] != '-')
		do_gap(tab, '0', tab->width - length, 1);
	else if (tab->convert[0] != '-')
		do_gap(tab, ' ', tab->width - length, 1);
	ft_putstr(str);
	if (tab->convert[0] == '-')
		do_gap(tab, ' ', tab->width - length, 1);
	free(str);
	return (tab);
}
