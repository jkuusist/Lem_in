/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:00:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/06/10 12:26:30 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

void	print_format(t_pf *pf)
{
	if ((pf->spec_flag == 'c') || (pf->spec_flag == 'C'))
		print_char(pf);
	else if (pf->spec_flag == 's')
		print_str(pf);
	else if ((pf->spec_flag == 'd') || (pf->spec_flag == 'i')
		|| (pf->spec_flag == 'D') || (pf->spec_flag == 'u'))
		print_int(pf);
	else if ((pf->spec_flag == 'f') || (pf->spec_flag == 'F'))
		print_double(pf);
	else if ((pf->spec_flag == 'o') || (pf->spec_flag == 'O'))
		print_oct(pf);
	else if ((pf->spec_flag == 'x') || (pf->spec_flag == 'X'))
		print_hex(pf);
	else if (pf->spec_flag == 'p')
		print_ptr(pf);
	else if (pf->spec_flag == 'b')
		print_bin(pf);
	else if (pf->spec_flag == '%')
		print_percent(pf);
}
