/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 11:58:48 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/11 11:59:36 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void    ft_put_spaces(int min, int size)
{
    int i;

	i = 0;
	if (min < size)
		return ;
	while (i < (min - size))
	{
		ft_putchar(' ');
		i++;
	}
}