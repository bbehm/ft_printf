/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:38:47 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/26 11:34:56 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

void	fix_h(t_tab *tab, const char *str)
{
	tab->i++;
	tab->flag = str[tab->i];
	if (tab->flag == 'd' || tab->flag == 'i')
	{
		tab->length = 'h';
		do_the_d(tab);
	}
	else if (tab->flag == 'u')
	{
		tab->length = 'h';
		do_the_u(tab);
	}
	else if (tab->flag == 'o')
	{
		tab->length = 'h';
		do_the_o(tab, tab->flag);
	}
	else if (tab->flag == 'x' || tab->flag == 'X')
	{
		tab->length = 'h';
		do_the_x(tab, tab->flag);
	}
	else
		tab->i = tab->i - 1;

}

void	fix_hh(t_tab *tab, const char *str)
{
	tab->i = tab->i + 2;
	tab->flag = str[tab->i];
	if (tab->flag == 'd' || tab->flag == 'i')
	{
		tab->length = 'H';
		do_the_d(tab);
	}
	else if (tab->flag == 'u')
	{
		tab->length = 'H';
		do_the_u(tab);
	}
	else if (tab->flag == 'o')
	{
		tab->length = 'H';
		do_the_o(tab, tab->flag);
	}
	else if (tab->flag == 'x' || tab->flag == 'X')
	{
		tab->length = 'H';
		do_the_x(tab, tab->flag);
	}
	else
		tab->i = tab->i - 2;
}

void	fix_ll(t_tab *tab, const char *str)
{
	tab->i = tab->i + 2;
	tab->flag = str[tab->i];
	if (tab->flag == 'd' || tab->flag == 'i')
	{
		tab->length = 'A';
		do_the_d(tab);
	}
	else if (tab->flag == 'u')
	{
		tab->length = 'A';
		do_the_u(tab);
	}
	else if (tab->flag == 'o')
	{
		tab->length = 'A';
		do_the_o(tab, tab->flag);
	}
	else if (tab->flag == 'x' || tab->flag == 'X')
	{
		tab->length = 'A';
		do_the_x(tab, tab->flag);
	}
	else
		tab->i = tab->i - 2;
}

void	fix_l(t_tab *tab, const char *str)
{
	tab->i++;
	tab->flag = str[tab->i];
	if (tab->flag == 'd' || tab->flag == 'i')
	{
		tab->length = 'a';
		do_the_d(tab);
	}
	else if (tab->flag == 'u')
	{
		tab->length = 'a';
		do_the_u(tab);
	}
	else if (tab->flag == 'o')
	{
		tab->length = 'a';
		do_the_o(tab, tab->flag);
	}
	else if (tab->flag == 'x' || tab->flag == 'X')
	{
		tab->length = 'a';
		do_the_x(tab, tab->flag);
	}
	else
		tab->i = tab->i - 1;
}

void	fix_f(t_tab *tab, const char *str)
{
	tab->i = tab->i + 1;
	tab->flag = str[tab->i];
	if (str[tab->i - 1] == 'l')
		do_the_f(tab);
	else if (tab->flag == 'f')
	{
		tab->length = 'a';
		do_the_f(tab);
	}
	else
		tab->i = tab->i - 1;
}
