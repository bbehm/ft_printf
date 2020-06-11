/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:38:10 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/11 15:12:32 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab	*initialize(t_tab *tab)
{
	tab->length = 0;
	tab->i = 0;
	tab->specifier_mask = "scdiuoxXpf%";
	tab->converter_mask = "-+ 0#";
	tab->argument_mask = "llhh";
	tab->f_treat = (char *)tab->form;
	tab->f_copy = (char *)tab->form;
	tab->nb = 0;
	return (tab);
}
