/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:12:35 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/26 11:26:47 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

void fix_width(t_tab *tab, const char *format)
{
	if (format[tab->i] != '\0' && (format[tab->i] == '*' || (format[tab->i] >= '0' && format[tab->i] <= '9')))
    {
        if (format[tab->i] == '*' || format[tab->i + 1] == '*')
        {
            tab->width = va_arg(tab->args, int);
            if (tab->width < 0)
            {
                tab->minus = 1;
                tab->width *= -1;
            }
            tab->i = (format[tab->i + 1]) == '*' ? tab->i + 2 : tab->i + 1;
        }
        else
        {
            tab->i = (format[tab->i] == '0') ? tab->i + 1 : tab->i;
            tab->width = ft_atoi(&format[tab->i]);
            while (format[tab->i] >= '0' && format[tab->i] <= '9')
                tab->i++;
        }
        tab->i = tab->i - 1;
        parse(tab, format);
    }
}