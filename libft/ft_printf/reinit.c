/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:00:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/06/10 12:26:30 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reinit(t_pf *pf)
{
	int i;

	i = 0;
	pf->precision = -1;
	pf->width = 0;
	while (i < 6)
	{
		pf->flags[i] = '\0';
		i++;
	}
	pf->spec_flag = '\0';
	i = 0;
	while (i < 5)
	{
		pf->mod_flag[i] = '\0';
		i++;
	}
}
