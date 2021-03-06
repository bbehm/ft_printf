/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 14:03:43 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/29 14:45:31 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstr_size(char *str, int *size)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_size(str[i], size);
		i++;
	}
}
