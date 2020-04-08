/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:58:55 by bbehm             #+#    #+#             */
/*   Updated: 2020/02/16 12:19:49 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

int	ft_printf(const char *format, ...)
{
	t_tab *tab;

	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	tab->form = format;
	tab = initialize(tab);
	if (format)
	{
		va_start(tab->args, format);
		tab->length = parse(tab);
		va_end(tab->args);
	}
	free(tab);
	return (tab->length);
}
