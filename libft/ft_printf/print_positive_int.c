/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_positive_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:03:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/07/01 11:03:30 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

static void		handle_zeroes(t_pf *pf)
{
	if ((pf->flags[3] == '+') && (pf->spec_flag != 'u'))
		ft_putchar('+');
	if ((pf->flags[4] == ' ') && (pf->spec_flag != 'u'))
		ft_putchar(' ');
	fill_width(pf, ' ', pf->width, 1);
}

static void		check_flags(t_pf *pf, int len)
{
	int preci;
	int width;
	int to_fill;

	preci = pf->precision;
	width = pf->width;
	to_fill = (preci > len) ? preci : len;
	if ((pf->flags[3] == '+') && (pf->spec_flag != 'u'))
		to_fill++;
	if (pf->flags[1] == '0' && pf->flags[3] == '+' && pf->spec_flag != 'u')
		ft_putchar_pf('+', pf, 1);
	if (pf->flags[2] != '-')
		((pf->flags[1] == '0') && (pf->precision == -1))
		? fill_width(pf, '0', width - to_fill, 1)
		: fill_width(pf, ' ', width - to_fill, 1);
	if ((pf->width == 0) && (pf->flags[3] != '+') && (pf->flags[4] == ' ')
		&& (pf->spec_flag != 'u'))
		ft_putchar_pf(' ', pf, 1);
	if ((pf->flags[1] != '0') && (pf->flags[3] == '+')
		&& (pf->spec_flag != 'u'))
		ft_putchar_pf('+', pf, 1);
	if (preci > len)
		fill_width(pf, '0', preci - len, 1);
}

void			print_positive_int(t_pf *pf, long long num)
{
	int len;

	if ((num == 0) && (pf->precision == 0))
	{
		handle_zeroes(pf);
		return ;
	}
	len = numlen(num, 10);
	check_flags(pf, len);
	ft_putlong(num);
	pf->len += len;
	if (pf->precision > len)
		len = pf->precision;
	if (pf->flags[2] == '-')
	{
		if (pf->flags[3] == '+')
			len++;
		fill_width(pf, ' ', (pf->width - len), 1);
	}
}
