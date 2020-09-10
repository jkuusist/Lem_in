/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
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

void	print_str(t_pf *pf)
{
	char	*s;
	int		len;
	int		is_malloced;

	s = va_arg(pf->args, char*);
	is_malloced = 1;
	if (s && (pf->precision > -1))
		s = ft_strndup(s, pf->precision);
	else if (!s && (pf->precision > -1))
		s = ft_strndup("(null)", pf->precision);
	else if (!s && (pf->precision == -1))
		s = ft_strdup("(null)");
	else
		is_malloced = 0;
	len = ft_strlen(s);
	pf->len += len;
	if ((pf->flags[1] == '0') && (pf->flags[2] != '-'))
		fill_width(pf, '0', (pf->width - len), 1);
	else if (pf->flags[2] != '-')
		fill_width(pf, ' ', (pf->width - len), 1);
	ft_putstr(s);
	if (pf->flags[2] == '-')
		fill_width(pf, ' ', (pf->width - len), 1);
	if (is_malloced)
		free(s);
}
