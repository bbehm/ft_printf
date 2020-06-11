/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_zeros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 11:47:08 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/11 12:08:01 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void    ft_put_zeros(int max, int *len)
{
    int i;
    int count;

    i = 0;
    count = max - *len;
    if (max < *len)
        return ;
    while (i < count)
    {
        write(1, "0", 1);
        i++;
    }
}