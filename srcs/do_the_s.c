/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:30:43 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/25 15:59:08 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static void	do_more_s(t_tab *tab, char *output)
{
	if (tab->width && !tab->minus)
		ft_put_spaces(tab->width, tab->len, tab->size);
	if (tab->minus)
	{
		if (!tab->num && tab->output != 0)
			ft_putstr_size(output, tab->size);
		ft_put_spaces(tab->width, tab->len, tab->size);
		tab->precision ? free(output) : 0;
		return ;
	}
	if (tab->num)
		return ;
	ft_putstr_size(output, tab->size);
	if (tab->precision)
		free(output);
}

void		do_the_s(t_tab *tab)
{
	char *output;

	output = va_arg(tab->args, char*);
	output == NULL ? output = "(null)" : 0;
	if (!tab->num)
		tab->len = ft_strlen(output);
	if (tab->precision)
	{
		output = ft_strsub(output, 0, tab->precision);
		tab->len = ft_strlen(output);
	}
	do_more_s(tab, output);
}
