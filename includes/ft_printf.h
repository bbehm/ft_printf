/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:02:03 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/11 12:03:09 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <ctype.h>

/*
** This struct holds all the relevant information on flags and info we need to
** display the output correctly.
*/

typedef struct	s_tab
{
	const char	*form;
	char		*f_copy;
	char		*f_treat;
	va_list		args;
	int			length;
	int			dot;
	int			hash;
	int			minus;
	int			space;
	int			zero;
	int			plus;
	int			sign;
	size_t		i;
	long int	precision;
	long int	width;
	char		specifier_flag;
	char		convert[6];
	char		argument_flag[2];
	char		*specifier_mask;
	char		*converter_mask;
	char		*argument_mask;
	long double	output_f;
	char		*nbr;
	int			*bytes;
	int			nb;
}				t_tab;

int				ft_printf(const char *format, ...);
int				fix(t_tab *tab);
int				parse(t_tab	*tab);

t_tab			*display_options(t_tab *tab);
t_tab			*initialize(t_tab *tab);
t_tab			*boost(t_tab *tab);
t_tab			*fix_conversion(t_tab *tab);
t_tab			*fix_precision(t_tab *tab);
t_tab			*fix_width(t_tab *tab);
t_tab			*fix_arguments(t_tab *tab);
t_tab			*fix_specifier(t_tab *tab);
t_tab			*do_the_d(t_tab *tab);
t_tab			*do_the_c(t_tab *tab);
t_tab			*do_the_ws(t_tab *tab);
t_tab			*do_the_s(t_tab *tab);
t_tab			*do_the_o(t_tab *tab);
t_tab			*do_the_u(t_tab *tab);
t_tab			*do_the_x(t_tab *tab);
t_tab			*do_the_p(t_tab *tab);
t_tab			*leftover(t_tab *tab);

void    		do_the_f(t_tab *tab);
void			do_gap(t_tab *tab, char c, int len, int new_len);
void			show_char(wint_t c, t_tab *tab);

#endif
