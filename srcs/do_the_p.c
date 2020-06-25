/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:20:07 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/25 15:49:18 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

void	do_the_p(t_tab *tab, char flag)
{
	tab->output_u = (unsigned long)va_arg(tab->args, void*);
	tab->nbr = ft_itoa_base_ul(tab->output_u, 16);
	if (!tab->minus && tab->width)
		ft_put_spaces(tab->width, ft_strlen(tab->nbr) + 2, tab->size);
	if (tab->minus)
	{
		ft_putstr_size("0x", tab->size);
		if (!tab->num && tab->output_u != 0)
			ft_itoa_base_size(tab->output_u, 16, tab->size, flag);
		ft_put_spaces(tab->width, ft_strlen(tab->nbr) + 2, tab->size);
		free(tab->nbr);
		return ;
	}
	free(tab->nbr);
	ft_putstr_size("0x", tab->size);
	if (tab->output_u != 0 && !tab->num)
		ft_itoa_base_size(tab->output_u, 16, tab->size, flag);
	return ;
}
