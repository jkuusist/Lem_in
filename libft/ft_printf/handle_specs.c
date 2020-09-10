/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:00:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/06/10 12:26:30 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

static void	handle_stuff(t_pf *pf)
{
	handle_flags(pf);
	handle_width(pf);
	handle_precision(pf);
	handle_modifiers(pf);
	handle_specifier(pf);
	print_format(pf);
}

int			handle_specs(t_pf *pf)
{
	int count;

	count = 0;
	if (ft_strchr(pf->format, '%') == 0)
		return (0);
	while (pf->format[pf->i] != '\0')
	{
		if (pf->format[pf->i] == '%')
		{
			print_format_str(pf, count);
			reinit(pf);
			(pf->i)++;
			handle_stuff(pf);
			count = 0;
		}
		else
		{
			count++;
			pf->len++;
		}
		(pf->i)++;
	}
	print_format_str(pf, count);
	return (pf->len);
}
