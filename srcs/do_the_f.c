/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:24:42 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/11 12:00:16 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static void do_final_f(t_tab *tab)
{
    if (tab->zero)
    {
        if (tab->sign)
        {
            ft_putchar('-');
            tab->sign = 0;
        }
        tab->zero ? ft_put_zeros(tab->width, &tab->length) : 0;
    }
    tab->sign && tab->nbr[0] != '-' ? ft_putchar('-') : 0;
    ft_putstr(tab->nbr);
    free(tab->nbr);
}

static void do_further_f(t_tab *tab)
{
    tab->width && !tab->zero && !tab->space &&\
    !tab->minus ? ft_put_spaces(tab->width, tab->length) : 0;
    if (tab->output_f >= 0 && (tab->plus || tab->space))
        tab->plus ? write(1, "+", 1) : write(1, " ", 1);
    tab->space && tab->width && !tab->zero && !tab->minus ?\
    ft_put_spaces(tab->width, tab->length) : 0;
    if (tab->minus)
    {
        if (tab->sign)
        {
            ft_putchar('-');
            tab->sign = 0;
        }
        ft_putstr(tab->nbr);
        ft_put_spaces(tab->width, tab->length);
        free(tab->nbr);
        return ;
    }
    do_final_f(tab);
}

static void do_more_f(t_tab *tab)
{
    tab->length = ft_strlen(tab->nbr);
    tab->output_f < 0 ? tab->length += 1 : 0;
    tab->length = (tab->output_f >= 0 && (tab->plus || tab->space)) ?\
    tab->length + 1 : tab->length;
    tab->nb && tab->output_f == 0 ? tab->length = 0 : 0;
    tab->nb && tab->output_f == 0 && (tab->plus || tab->space) ?\
    tab->length = 1 : 0;
    do_further_f(tab);
}

void    do_the_f(t_tab *tab)
{
    int round;

    round = tab->precision;
    tab->output_f = (double)va_arg(tab->args, double);
    (tab->precision >= 1) ? tab->dot = 1 : 0;
    tab->sign = (tab->output_f < 0) ? 1 : 0;
    if (tab->precision == 0)
    {
        round = 6;
        tab->dot = 1;
    }
    tab->nbr = ft_ftoa(tab->output_f, round, tab->dot);
    do_more_f(tab);
}