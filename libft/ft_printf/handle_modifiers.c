/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_modifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:11:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/07/01 10:11:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

static void	handle_ll_hh(t_pf *pf, char c)
{
	if (c == 'l')
	{
		pf->mod_flag[0] = '\0';
		pf->mod_flag[3] = 'l';
	}
	else if (c == 'h')
	{
		pf->mod_flag[2] = '\0';
		pf->mod_flag[4] = 'h';
	}
}

void		handle_modifiers(t_pf *pf)
{
	int l_is_found;
	int h_is_found;

	l_is_found = 0;
	h_is_found = 0;
	while (ft_strchr(pf->mod_mask, pf->format[pf->i]))
	{
		if ((pf->format[pf->i] == 'l') && (l_is_found == 0) && pf->i++)
		{
			pf->mod_flag[0] = 'l';
			l_is_found = 1;
		}
		else if ((l_is_found == 1) && pf->i++)
			handle_ll_hh(pf, 'l');
		if ((pf->format[pf->i] == 'L') && pf->i++)
			pf->mod_flag[1] = 'L';
		if ((pf->format[pf->i] == 'h') && (h_is_found == 0) && pf->i++)
		{
			pf->mod_flag[2] = 'h';
			h_is_found = 1;
		}
		else if ((h_is_found == 1) && pf->i++)
			handle_ll_hh(pf, 'h');
	}
}
