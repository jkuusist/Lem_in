/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
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

void	print_double(t_pf *pf)
{
	long double	dub;
	char		*s;
	int			len;

	if (!(s = (char*)malloc(sizeof(char) * 25)))
		exit(-1);
	if (pf->mod_flag[1] == 'L')
		dub = (long double)va_arg(pf->args, long double);
	else
		dub = (double)va_arg(pf->args, double);
	if (pf->precision == -1)
		pf->precision = 6;
	double_to_str(dub, s, pf->precision, pf->flags);
	len = ft_strlen(s);
	if ((pf->flags[1] == '0') && (pf->flags[2] != '-'))
		fill_width(pf, '0', (pf->width - len), 1);
	else if (pf->flags[2] != '-')
		fill_width(pf, ' ', (pf->width - len), 1);
	ft_putstr(s);
	pf->len += ft_strlen(s);
	if (pf->flags[2] == '-')
		fill_width(pf, ' ', (pf->width - len), 1);
	free(s);
}
