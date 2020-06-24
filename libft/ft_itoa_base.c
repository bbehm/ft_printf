/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 10:25:41 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/24 10:44:32 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

/*
** First, we check if the value is zero, if not we count how long the string will
** be with the indicated base and store it in num_len. Then, we take the original
** value and check if it's negative. If negative, we convert it to unsigned. If
** the base however is 10 we need to add one to num_len to allocate space for
** minus sign.
** Now we allocate space for the string we will return. After that we add the null
** terminator to the string.
** Then it's time to convert the value into the correct base, this can be done
** by taking the modulo of the base from the number, and choosing that point from
** the base string and storing it in the result string.
** Finally, we add the minus sign if it's a negative value in base 10, and then
** return the result string (ptr).
*/

char		*ft_itoa_base(int value, int base)
{
    int     num_len;
    int     num;
    char    *ptr;
    char    *base_str = "0123456789ABCDEF";

    if (value == 0)
        return ("0");
    num_len = 0;
    num = value;
    while (num)
    {
        num = num / base;
        num_len++;
    }
    num = value;
    if (num < 0)
    {
        if (base == 10)
            num_len++;
        num = num * -1;
    }
    if (!(ptr = (char*)malloc(sizeof(char) * num_len + 1)))
        return (NULL);
    ptr[num_len] = '\0';
    while (num)
    {
        ptr[--num_len] = base_str[num % base];
        num = num / base;
    }
    if (value < 0 && base == 10)
        ptr[0] = '-';
    return (ptr);
}