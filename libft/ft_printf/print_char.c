/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:00:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/06/10 12:26:30 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include <ctype.h>

void	print_char(t_pf *pf)
{
	char c;

	if ((pf->mod_flag[0] == 'l') || (pf->spec_flag == 'C'))
		c = va_arg(pf->args, int);
	else
		c = va_arg(pf->args, int);
	if ((pf->flags[1] == '0') && (pf->flags[2] != '-'))
		fill_width(pf, '0', (pf->width - 1), 1);
	else if (pf->flags[2] != '-')
		fill_width(pf, ' ', (pf->width - 1), 1);
	ft_putchar(c);
	pf->len++;
	if (pf->flags[2] == '-')
		fill_width(pf, ' ', (pf->width - 1), 1);
}
