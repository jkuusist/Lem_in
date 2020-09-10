/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:00:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/06/10 12:26:30 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

static long long	get_num(t_pf *pf)
{
	long long num;

	if (pf->spec_flag == 'D')
		num = (long)va_arg(pf->args, long);
	else if (pf->spec_flag == 'u')
	{
		if (pf->mod_flag[0] == 'l')
			num = (unsigned long)va_arg(pf->args, unsigned long);
		else if (pf->mod_flag[3] == 'l')
			num = (unsigned long long)va_arg(pf->args, unsigned long long);
		else
			num = (unsigned int)va_arg(pf->args, unsigned int);
	}
	else if (pf->mod_flag[2] == 'h')
		num = (short)va_arg(pf->args, int);
	else if (pf->mod_flag[4] == 'h')
		num = (signed char)va_arg(pf->args, int);
	else if (pf->mod_flag[0] == 'l')
		num = (long)va_arg(pf->args, long);
	else if (pf->mod_flag[3] == 'l')
		num = (long long)va_arg(pf->args, long long);
	else
		num = (int)va_arg(pf->args, int);
	return (num);
}

void				print_int(t_pf *pf)
{
	long long	num;

	num = get_num(pf);
	if (num < 0)
		print_negative_int(pf, num);
	else
		print_positive_int(pf, num);
}
