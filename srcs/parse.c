/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:55:38 by bbehm             #+#    #+#             */
/*   Updated: 2020/02/24 12:52:44 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include <unistd.h>

int	parse(t_tab *tab)
{
	if (ft_strcmp(tab->f_copy, "%") == 0)
		return (0);
	while (tab->f_copy[tab->i] != '\0')
	{
		if (tab->f_copy[tab->i] == '%')
		{
			boost(tab);
			fix(tab);
		}
		else
		{
			write(1, &tab->f_copy[tab->i], 1);
			tab->length++;
		}
		tab->i++;
	}
	return (tab->length);
}
