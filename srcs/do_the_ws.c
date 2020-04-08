/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_ws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:04:05 by bbehm             #+#    #+#             */
/*   Updated: 2020/02/24 17:01:56 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static wchar_t	*wstrndup(wchar_t *str, int length)
{
	wchar_t	*new_str;
	int		i;

	i = 0;
	if (!(new_str = (wchar_t *)malloc(sizeof(wchar_t) * length + 1)))
		exit(-1);
	while (str[i] && i < length)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static wchar_t	*wstrdup(wchar_t *str)
{
	int length;

	length = 0;
	while (str[length])
		length++;
	return (wstrndup(str, length));
}

static t_tab	*handle_null(t_tab *tab)
{
	wchar_t	*str;
	int		i;

	i = 0;
	str = wstrdup(L"(null)");
	if (tab->precision > -1)
	{
		while (str[i] && tab->precision-- > 0)
			show_char(str[i++], tab);
	}
	else
	{
		while (str[i])
			show_char(str[i++], tab);
	}
	free(str);
	return (tab);
}

static int		char_len(wchar_t c)
{
	int len;

	if (c <= 127)
		len = 1;
	else if (c >= 127 && c <= 2047)
		len = 2;
	else if (c >= 2048 && c <= 65535)
		len = 3;
	else
		len = 4;
	return (len);
}

t_tab			*do_the_ws(t_tab *tab)
{
	wchar_t		*str;
	int			i;
	int			j;
	int			len;

	i = 0;
	len = 0;
	if (!(str = (wchar_t *)va_arg(tab->args, wchar_t *)))
		return (handle_null(tab));
	while (str[i] && !(j = 0))
	{
		if (tab->precision > -1 && (len + char_len(str[i])) > tab->precision)
			break ;
		len += char_len(str[i++]);
	}
	if (tab->convert[3] == '0' && tab->convert[0] != '-')
		do_gap(tab, '0', tab->width - len, 1);
	else if (tab->convert[0] != '-')
		do_gap(tab, ' ', tab->width - len, 1);
	while (j < i)
		show_char(str[j++], tab);
	if (tab->convert[0] == '-')
		do_gap(tab, ' ', tab->width - len, 1);
	return (tab);
}
