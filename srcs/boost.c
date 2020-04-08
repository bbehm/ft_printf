/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:00:55 by bbehm             #+#    #+#             */
/*   Updated: 2020/02/24 12:33:57 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab	*boost(t_tab *tab)
{
	tab->specifier_flag = '\0';
	tab->convert[0] = '\0';
	tab->convert[1] = '\0';
	tab->convert[2] = '\0';
	tab->convert[3] = '\0';
	tab->convert[4] = '\0';
	tab->convert[5] = '\0';
	tab->argument_flag[0] = '\0';
	tab->argument_flag[1] = '\0';
	tab->precision = -1;
	tab->width = 0;
	return (tab);
}
