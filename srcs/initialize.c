/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:38:10 by bbehm             #+#    #+#             */
/*   Updated: 2020/02/24 12:51:27 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab	*initialize(t_tab *tab)
{
	tab->length = 0;
	tab->i = 0;
	tab->specifier_mask = "scSCdDiuUoOxXbp%";
	tab->converter_mask = "-+ 0#";
	tab->argument_mask = "lhjz";
	tab->f_treat = (char *)tab->form;
	tab->f_copy = (char *)tab->form;
	return (tab);
}
