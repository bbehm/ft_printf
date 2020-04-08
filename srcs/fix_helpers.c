/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:12:35 by bbehm             #+#    #+#             */
/*   Updated: 2020/02/24 12:50:59 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>

t_tab	*fix_conversion(t_tab *tab)
{
	size_t i;

	i = 0;
	while (tab->converter_mask[i] != '\0')
	{
		while (tab->f_treat[tab->i] == '-' && tab->i++)
		{
			while (tab->f_treat[tab->i] == '-' && tab->i++)
				tab->convert[0] = '-';
			while (tab->f_treat[tab->i] == '+' && tab->i++)
				tab->convert[1] = '+';
			while (tab->f_treat[tab->i] == ' ' && tab->i++)
				tab->convert[2] = ' ';
			while (tab->f_treat[tab->i] == '0' && tab->i++)
				tab->convert[3] = '0';
			while (tab->f_treat[tab->i] == '#' && tab->i++)
				tab->convert[4] = '#';
			i = 0;
		}
		i++;
	}
	return (tab);
}

t_tab	*fix_precision(t_tab *tab)
{
	while (tab->f_treat[tab->i] == '.')
	{
		tab->i++;
		tab->precision = 0;
	}
	while (tab->f_treat[tab->i] >= '0' && tab->f_treat[tab->i] <= '9')
	{
		tab->precision *= 10;
		tab->precision += (tab->f_treat[tab->i] - 48);
		tab->i++;
	}
	return (tab);
}

t_tab	*fix_width(t_tab *tab)
{
	while (tab->f_treat[tab->i] >= '0' && tab->f_treat[tab->i] <= '9')
	{
		tab->width *= 10;
		tab->width += (tab->f_treat[tab->i] - 48);
		tab->i++;
	}
	return (tab);
}

t_tab	*fix_arguments(t_tab *tab)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (tab->argument_mask[i] != '\0')
	{
		while (tab->argument_mask[i] == tab->f_treat[tab->i])
		{
			tab->argument_flag[j] = tab->f_treat[tab->i];
			tab->argument_flag[j + 1] = '\0';
			tab->i++;
			j++;
		}
		i++;
	}
	return (tab);
}

t_tab	*fix_specifier(t_tab *tab)
{
	size_t i;

	i = 0;
	while (tab->specifier_mask[i] != '\0')
	{
		if (tab->specifier_mask[i] == tab->f_treat[tab->i])
			tab->specifier_flag = tab->specifier_mask[i];
		i++;
	}
	return (tab);
}
