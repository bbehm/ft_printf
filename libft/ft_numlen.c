/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 09:37:48 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/25 17:37:16 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_numlen(long long num)
{
	int tens;

	tens = 1;
	if (num < 0)
		tens++;
	while (num / 10)
	{
		num = num / 10;
		tens++;
	}
	return (tens);
}