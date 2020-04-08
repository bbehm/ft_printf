/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_gap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:19:20 by bbehm             #+#    #+#             */
/*   Updated: 2020/02/24 12:34:33 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

void	do_gap(t_tab *tab, char c, int len, int new_len)
{
	char *str;

	if (len > 0)
	{
		if (new_len)
			tab->length += len;
		if (!(str = ft_strnew(len)))
			exit(-1);
		ft_memset(str, c, len);
		write(1, str, len);
		free(str);
	}
}
