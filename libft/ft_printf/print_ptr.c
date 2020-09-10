/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:00:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/06/10 12:26:30 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include <stdlib.h>

void	print_ptr(t_pf *pf)
{
	char			*s;
	unsigned long	num;
	int				len;

	num = (unsigned long)va_arg(pf->args, unsigned long);
	if (!(s = ft_itoa_base(num, 16)))
		exit(-1);
	len = ft_strlen(s) + 2;
	if ((pf->flags[1] == '0') && (pf->flags[2] != '-'))
		fill_width(pf, '0', (pf->width - len), 1);
	else if (pf->flags[2] != '-')
		fill_width(pf, ' ', (pf->width - len), 1);
	if (pf->flags[4] == ' ')
		ft_putchar(' ');
	if (num && (pf->flags[0] == '#'))
		(pf->spec_flag == 'x') ? (ft_putstr("0x")) : (ft_putstr("0X"));
	ft_putstr("0x");
	ft_putstr(ft_strlower(s));
	pf->len += (ft_strlen(s) + 2);
	if (pf->flags[2] == '-')
		fill_width(pf, ' ', (pf->width - len), 1);
	pf->len += (pf->precision <= pf->width) ? pf->width : pf->precision;
	free(s);
}
