/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:24:29 by bbehm             #+#    #+#             */
/*   Updated: 2020/02/24 12:53:32 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include <unistd.h>

static void	oct_four(wint_t c)
{
	unsigned char output[4];

	output[0] = (c >> 18) + 240;
	output[1] = ((c >> 12) & 63) + 128;
	output[2] = ((c >> 6) & 63) + 128;
	output[3] = ((c & 63) + 128);
	write(1, output, 4);
}

static void	oct_three(wint_t c)
{
	unsigned char output[3];

	output[0] = (c >> 12) + 224;
	output[1] = ((c >> 6) & 63) + 128;
	output[2] = ((c & 63) + 128);
	write(1, output, 3);
}

static void	oct_two(wint_t c)
{
	unsigned char output[2];

	output[0] = (c >> 6) + 192;
	output[1] = ((c & 63) + 128);
	write(1, output, 2);
}

static void	oct_one(wint_t c)
{
	write(1, &c, 1);
}

void		show_char(wint_t c, t_tab *tab)
{
	if (c <= 127)
	{
		tab->length += 1;
		oct_one(c);
	}
	if (c >= 127 && c <= 2047)
	{
		tab->length += 2;
		oct_two(c);
	}
	if (c >= 2048 && c <= 65535)
	{
		tab->length += 3;
		oct_three(c);
	}
	if (c >= 65536 && c <= 2097151)
	{
		tab->length += 4;
		oct_four(c);
	}
}
